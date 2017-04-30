/**
 * Entitas ECS
 *
 */

namespace entitas


	exception Exception
		EntityIsNotEnabled
		EntityAlreadyHasComponent
		EntityDoesNotHaveComponent
		InvalidMatcherExpression
		EntityIsAlreadyReleased
		SingleEntity
		WorldDoesNotContainEntity

	delegate Factory():Entity*

	struct Buffer
		pool: int		   // pool index
		size: int		   // pool size
		factory: Factory	// factory callback


	[Compact]
	class ISystem
		world:World

		def setWorld(world:World)
			this.world = world
		def initialize()
			pass
		def execute(delta:double)
			pass

	/**
	 * A Group is a set of entities defined by a Matcher
	 */
	[Compact]
	class Group 
		matcher:unowned Matcher
		entities:List of Entity* = new List of Entity*
		singleEntityCache: Entity*
		
		construct(matcher:Matcher)
			this.matcher = matcher

		/** Add entity to group */
		def handleEntitySilently(entity : Entity*)
			if matcher.matches(entity) do entities.append(entity)
			else do entities.remove(entity)

		/** Add entity to group and raise events */
		def handleEntity(entity : Entity*, index : Components)
			if matcher.matches(entity) do entities.append(entity) 
			else do entities.remove(entity) 

		def containsEntity(entity : Entity*) : bool
			return entities.find(entity) != null

		def getSingleEntity(): Entity* 
			var c = entities.length()
			if c == 1
				return (Entity*)entities.first().data
			else if c == 0
				return null
			else
				raise new Exception.SingleEntity(matcher.to_string())
						
		
	/**
	 * Match entities by component
	 * complile list of components to bit array for fast comparison
	 */
	[Compact]
	class Matcher

		/**
		 * A unique sequential index number assigned to each ,atch
		 * @type number */
		uniqueId : static int
		/**
		 * Get the matcher id
		 * @type number
		 * @name entitas.Matcher#id */
		id : int
		/**
		 * A unique sequential index number assigned to each entity at creation
		 * @type number
		 * @name entitas.Matcher#allOfIndices */
		allOfIndices : array of int

		allOfMask: uint64

		/**
		 * A unique sequential index number assigned to each entity at creation
		 * @type number
		 * @name entitas.Matcher#anyOfIndices */
		anyOfIndices : array of int

		anyOfMask: uint64
		/**
		 * A unique sequential index number assigned to each entity at creation
		 * @type number
		 * @name entitas.Matcher#noneOfIndices */
		noneOfIndices : array of int

		noneOfMask: uint64

		indices		: array of int
		to_stringCache  : string


		/**
		 *  clone/merge 1 or more existing matchers
		 */
		construct(matchers: array of Matcher=null)
			id = Matcher.uniqueId++
			if matchers != null
				var allOf = new List of int
				var anyOf = new List of int
				var noneOf = new List of int
				for var i=0 to (matchers.length-1)
					allOfMask |= matchers[i].allOfMask
					anyOfMask |= matchers[i].anyOfMask
					noneOfMask |= matchers[i].noneOfMask
					for var j in matchers[i].allOfIndices do allOf.append(i)
					for var j in matchers[i].anyOfIndices do anyOf.append(i)
					for var j in matchers[i].noneOfIndices do noneOf.append(i)

				allOfIndices = Matcher.distinctIndices(listToArray(allOf))
				anyOfIndices = Matcher.distinctIndices(listToArray(anyOf))
				noneOfIndices = Matcher.distinctIndices(listToArray(noneOf))


		/**
		 * A list of the component ordinals that this matches
		 * @type Array<number>
		 * @name entitas.Matcher#indices */
		def getIndices() : array of int
			if indices == null
				indices = mergeIndices()
			return indices

		/**
		 * Matches anyOf the components/indices specified
		 * @params Array<entitas.IMatcher>|Array<number> args
		 * @returns entitas.Matcher
		 */
		def anyOf(args : array of int) : Matcher*
			anyOfIndices = Matcher.distinctIndices(args)
			indices = null
			return this

		/**
		 * Matches noneOf the components/indices specified
		 * @params Array<entitas.IMatcher>|Array<number> args
		 * @returns entitas.Matcher
		 */
		def noneOf(args : array of int) : Matcher*
			noneOfIndices = Matcher.distinctIndices(args)
			indices = null
			return this

		/**
		 * Check if the entity matches this matcher
		 * @param entitas.IEntity entity	
		 * @returns boolean
		 */
		def matches(entity : Entity*) : bool
			var mask = entity.mask ^ __ACTIVE__ 
			var matchesAllOf  = allOfMask  == 0 ? true : (mask & allOfMask) == allOfMask 
			var matchesAnyOf  = anyOfMask  == 0 ? true : (mask & anyOfMask) != 0
			var matchesNoneOf = noneOfMask == 0 ? true : (mask & noneOfMask) == 0
			return matchesAllOf && matchesAnyOf && matchesNoneOf

		/**
		 * Merge list of component indices
		 * @returns Array<number>
		 */
		def mergeIndices() : array of int

			var indicesList = new List of int
			if allOfIndices != null
				for var i in allOfIndices do indicesList.append(i)

			if anyOfIndices != null
				for var i in anyOfIndices do indicesList.append(i)

			if noneOfIndices != null
				for var i in noneOfIndices do indicesList.append(i)

			return Matcher.distinctIndices(listToArray(indicesList))

		/**
		 * to_string representation of this matcher
		 * @returns string
		 */
		def to_string() : string
			if to_stringCache == null
				var sb = ""
				if allOfIndices != null
					sb += "AllOf("
					sb += componentsto_string(allOfIndices)
					sb += ")"

				if anyOfIndices != null
					if allOfIndices != null
						sb += "."

					sb += "AnyOf("
					sb += componentsto_string(anyOfIndices)
					sb += ")"

				if noneOfIndices != null
					sb += ".NoneOf("
					sb += componentsto_string(noneOfIndices)
					sb += ")"

				to_stringCache = sb

			return to_stringCache

		def static componentsto_string(indexArray : array of int) : string
			var sb = ""
			for var index in indexArray
				sb += ComponentString[index]
			return sb

		def static listToArray(l : List of int) : array of int
			var size = 0
			for var x in l do size++
			var a = new array of int[size]
			var i = 0
			for var x in l do a[i++] = x
			return a

		/**
		 * Get the set if distinct (non-duplicate) indices from a list
		 * @param Array<number> indices
		 * @returns Array<number>
		 */
		def static distinctIndices(indices : array of int) : array of int
			var indicesSet = new array of bool[64]
			var result = new List of int

			for var index in indices
				if !indicesSet[index]
					result.append(index)
				indicesSet[index] = true

			return listToArray(result)

		/**
		 * Merge all the indices of a set of Matchers
		 * @param Array<IMatcher> matchers
		 * @returns Array<number>
		 */
		def static merge(matchers : array of Matcher) : array of int raises Exception
			var indices = new List of int

			for var i=0 to (matchers.length-1)
				if matchers[i].indices.length != 1
					raise new Exception.InvalidMatcherExpression(matchers[i].to_string())
				indices.append(matchers[i].indices[0])
			return listToArray(indices)

		/**
		 * Matches noneOf the components/indices specified
		 * @params Array<entitas.IMatcher>|Array<number> args
		 * @returns entitas.Matcher
		 */
		def static NoneOf(args : array of int) : Matcher
			var matcher = new Matcher()
			matcher.noneOfIndices = Matcher.distinctIndices(args)
			matcher.noneOfMask = Matcher.buildMask(matcher.noneOfIndices)
			return matcher
		/**
		 * Matches allOf the components/indices specified
		 * @params Array<entitas.IMatcher>|Array<number> args
		 * @returns entitas.Matcher
		 */
		def static AllOf(args : array of int) : Matcher
			var matcher = new Matcher()
			matcher.allOfIndices = Matcher.distinctIndices(args)
			matcher.allOfMask = Matcher.buildMask(matcher.allOfIndices)
			return matcher

		/**
		 * Matches anyOf the components/indices specified
		 * @params Array<entitas.IMatcher>|Array<number> args
		 * @returns entitas.Matcher
		 */
		def static AnyOf(args : array of int) : Matcher
			var matcher = new Matcher()
			matcher.anyOfIndices = Matcher.distinctIndices(args)
			matcher.anyOfMask = Matcher.buildMask(matcher.anyOfIndices)
			return matcher

		def static buildMask(indices: array of int): uint64
			accume:uint64 = 0
			for var index in indices do accume |= __POW2__[index]
			return accume

	/**
	 * ECS World
	 */
	class World : Object
		instance	: static World
		running	 	: bool
		pool		: array of Entity
		cache	   	: array of List of Entity* 
		bufsiz	   	: array of int
		systems	 	: List of ISystem = new List of ISystem
		// listener	: EntityRemovedListener
		id		  	: private int = 0
		groups	  	: List of Group = new List of Group
		k		   	: int
		t		   	: double
		t1		  	: double = 0.0
		t2		  	: double = 0.0
		t3		  	: double = 0.0
		profile	 	: bool = false
		// freq		: double = SDL.Timer.get_performance_frequency()

		construct(profile:bool=false)
			this.profile = profile
			World.instance = this

		def static onComponentAdded(e:Entity*, c:Components)
			World.instance.componentAddedOrRemoved(e, c)

		def static onComponentRemoved(e:Entity*, c:Components)
			World.instance.componentAddedOrRemoved(e, c)

		def componentAddedOrRemoved(entity:Entity*, component:Components)
			for var group in groups
				group.handleEntity(entity, component)

		def setPool(size:int, count:int, buffers: array of Buffer)
			pool = new array of Entity[size]
			cache = new array of List of Entity*[count]
			bufsiz = new array of int[count]
			for var i=0 to (count-1) do cache[i] = new List of Entity*
			for var i=0 to (buffers.length)
				bufsiz[buffers[i].pool] = buffers[i].size
				for var k=1 to (buffers[i].size)  
					cache[buffers[i].pool].append(buffers[i].factory())
				print "%d) %d/%d", i, buffers[i].size, (int)cache[buffers[i].pool].length()
		

		// def setEntityRemovedListener(listener:EntityRemovedListener)
		// 	this.listener = listener

		def createEntity(name:string, pool:int, active:bool = false):Entity*
			var id = this.id++
			return this.pool[id].setId(id).setName(name).setPool(pool).setActive(active)

		def deleteEntity(entity:Entity*)
			entity.setActive(false)
			// listener.entityRemoved(entity)
			//print "how did i get here"
			cache[entity.pool].append(entity)

		def add(system: ISystem):World
			system.setWorld(this)
			systems.append(system)
			return this

		def initialize()
			for var system in systems do system.initialize()			
			running = true

		def execute(delta:double)
			if !running do return
			// if profile do t1 = (double)SDL.Timer.get_performance_counter()/freq

			for var system in systems do system.execute(delta)			
			
			// if profile
			// 	t2 = (double)SDL.Timer.get_performance_counter()/freq
			// 	t3 = t2 - t1
			// 	t = t + t3
			// 	k += 1
			// 	if k == 1000
			// 		k = 0
			// 		t = t / 1000.0
			// 		print "%f", t
			// 		t = 0




		def getGroup(matcher : Matcher) : Group
			group:Group

			for var g in groups	
				if 


			if groups[matcher.id] != null
				group = groups[matcher.id]
			else
				group = new Group(matcher)
				for var i = 0 to (this.id-1) do group.handleEntitySilently(&pool[i])
				groups[matcher.toString()] = group

			return group


	/**
	 * Bit array masks
	 */
	const __POW2__:array of uint64 = {
		0x0000000000000000,
		0x0000000000000001,
		0x0000000000000002,
		0x0000000000000004,
		0x0000000000000008,
		0x0000000000000010,
		0x0000000000000020,
		0x0000000000000040,
		0x0000000000000080,
		0x0000000000000100,
		0x0000000000000200,
		0x0000000000000400,
		0x0000000000000800,
		0x0000000000001000,
		0x0000000000002000,
		0x0000000000004000,
		0x0000000000008000,
		0x0000000000010000,
		0x0000000000020000,
		0x0000000000040000,
		0x0000000000080000,
		0x0000000000100000,
		0x0000000000200000,
		0x0000000000400000,
		0x0000000000800000,
		0x0000000001000000,
		0x0000000002000000,
		0x0000000004000000,
		0x0000000008000000,
		0x0000000010000000,
		0x0000000020000000,
		0x0000000040000000,
		0x0000000080000000,
		0x0000000100000000,
		0x0000000200000000,
		0x0000000400000000,
		0x0000000800000000,
		0x0000001000000000,
		0x0000002000000000,
		0x0000004000000000,
		0x0000008000000000,
		0x0000010000000000,
		0x0000020000000000,
		0x0000040000000000,
		0x0000080000000000,
		0x0000100000000000,
		0x0000200000000000,
		0x0000400000000000,
		0x0000800000000000,
		0x0001000000000000,
		0x0002000000000000,
		0x0004000000000000,
		0x0008000000000000,
		0x0010000000000000,
		0x0020000000000000,
		0x0040000000000000,
		0x0080000000000000,
		0x0100000000000000,
		0x0200000000000000,
		0x0400000000000000,
		0x0800000000000000,
		0x1000000000000000,
		0x2000000000000000,
		0x4000000000000000,
		0x8000000000000000

	}
