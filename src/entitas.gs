namespace entitas

	exception Exception
		EntityIsNotEnabled
		EntityAlreadyHasComponent
		EntityDoesNotHaveComponent
		InvalidMatcherExpression
		EntityIsAlreadyReleased
		SingleEntity
		WorldDoesNotContainEntity

	[Compact, CCode (
		ref_function = "entitas_world_addRef", 
		unref_function = "entitas_world_release"
	)]
	class World
		instance	: static unowned World
		groups		: List of Group*
		cache		: array of List of Entity* 
		images		: array of SDL.Surface
		id			: int = 0
		refCount	: int=1

		construct()
			instance = this

		def addRef() : unowned World
			GLib.AtomicInt.add (ref refCount, 1)
			return this
		def release() 
			if GLib.AtomicInt.dec_and_test (ref refCount)
				this.free ()
		def extern free()

		def static onComponentAdded(e:Entity*, c:Components)
			instance.componentAddedOrRemoved(e, c)

		def static onComponentRemoved(e:Entity*, c:Components)
			instance.componentAddedOrRemoved(e, c)

		def componentAddedOrRemoved(entity:Entity*, component:Components)
			for var group in groups
				group->handleEntity(entity, component)

		/**
		* send antity back to it's pool
		*/		
		def deleteEntity(entity:Entity*)
			entity.setActive(false)
			cache[entity.pool].append(entity)

		/**
		* create an entity from the pool
		*/
		def createEntity(name:string, pool:int, active:bool):Entity*
			var id = this.id++
			return (POOL[id]
				.setId(id)
				.setName(name)
				.setPool(pool)
				.setActive(active))

		def getGroup(matcher : Matcher) : Group
			if groups.length() > matcher.id 
				return groups.nth_data(matcher.id)
			else
				groups.prepend(new Group(matcher))
				/**
				 * according to the docs, GLib.List doesn't referece count, therefore
				 * due to switching from Gee.ArrayList go GLib.List, we are required
				 * to manually bump the refCount
				 */
				matcher.addRef()
				for var i = 0 to (this.id-1) do groups.nth_data(0)->handleEntitySilently(&POOL[i])
				return groups.nth_data(0)


	/**
	 * A Group is a set of entities defined by a Matcher
	 */
	[Compact, CCode (
		ref_function = "entitas_group_addRef", 
		unref_function = "entitas_group_release"
	)]
	class Group
		matcher		: unowned Matcher
		entities	: List of Entity* = new List of Entity*
		refCount	: int=1
		singleEntityCache: Entity*
		
		construct(matcher: Matcher)
			this.matcher = matcher

		def addRef() : unowned Group 
			GLib.AtomicInt.add (ref refCount, 1)
			return this
		def release() 
			if GLib.AtomicInt.dec_and_test (ref refCount)
				this.free ()
		def extern free()
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
				raise new Exception.SingleEntity(matcher.toString())
						
		
	/**
	 * Match entities by component
	 * complile list of components to bit array for fast comparison
	 *
	 * modules that call this code need to add these forward declarations:
	 * 
	 *	void entitas_matcher_release (entitasMatcher* self);
	 *	void entitas_matcher_free (entitasMatcher* self);
	 *
	 */
	[Compact, CCode (
		ref_function = "entitas_matcher_addRef", 
		unref_function = "entitas_matcher_release"
	)]
	class Matcher
		/**
		 * A unique sequential index number assigned to each ,atch
		 * @type number */
		uniqueId : static int
		refCount: int = 1
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
		toStringCache  : string


		/**
		 *  clone/merge 1 or more existing matchers
		 */
		construct(matchers: array of Matcher=null)
			id = uniqueId++
			if matchers != null
				var allOf = new array of int[0]
				var anyOf = new array of int[0]
				var noneOf = new array of int[0]
				for var i=0 to (matchers.length-1)
					allOfMask |= matchers[i].allOfMask
					anyOfMask |= matchers[i].anyOfMask
					noneOfMask |= matchers[i].noneOfMask
					for var j in matchers[i].allOfIndices do allOf += i
					for var j in matchers[i].anyOfIndices do anyOf += i
					for var j in matchers[i].noneOfIndices do noneOf += i

				allOfIndices = Matcher.distinctIndices(allOf)
				anyOfIndices = Matcher.distinctIndices(anyOf)
				noneOfIndices = Matcher.distinctIndices(noneOf)

		def addRef() : unowned Matcher 
			GLib.AtomicInt.add (ref refCount, 1)
			return this
		def release() 
			if GLib.AtomicInt.dec_and_test (ref refCount)
				this.free ()
		def extern free()
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

			var indices = new array of int[0]
			if allOfIndices != null
				for var i in allOfIndices do indices += i

			if anyOfIndices != null
				for var i in anyOfIndices do indices += i

			if noneOfIndices != null
				for var i in noneOfIndices do indices += i

			return Matcher.distinctIndices(indices)

		/**
		 * toString representation of this matcher
		 * @returns string
		 */
		def toString() : string
			if toStringCache == null
				var sb = ""
				if allOfIndices != null
					sb += "AllOf("
					sb += componentstoString(allOfIndices)
					sb += ")"

				if anyOfIndices != null
					if allOfIndices != null
						sb += "."
					sb += "AnyOf("
					sb += componentstoString(anyOfIndices)
					sb += ")"

				if noneOfIndices != null
					sb += ".NoneOf("
					sb += componentstoString(noneOfIndices)
					sb += ")"

				toStringCache = sb

			return toStringCache

		def static componentstoString(indexArray : array of int) : string
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
					raise new Exception.InvalidMatcherExpression(matchers[i].toString())
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


