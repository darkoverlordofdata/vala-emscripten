namespace entitas

	
	class World : Object
		instance	: static unowned World
		groups		: List of Group
		pool		: array of Entity
		cache		: array of Cache 
		id			: int = 0
		systems		: ISystem?[100]
		count		: int = 0
		entityRemoved : unowned EntityRemovedListener

		construct()
			instance = this


		def static onComponentAdded(e:Entity*, c:Components)
			instance.componentAddedOrRemoved(e, c)

		def static onComponentRemoved(e:Entity*, c:Components)
			instance.componentAddedOrRemoved(e, c)

		def setPool(size:int, count:int, buffers: array of Buffer)
			pool = new array of Entity[size]
			cache = new array of Cache[count]
			for var i=0 to (buffers.length-1)
				var iPool = buffers[i].pool
				var iSize = buffers[i].size
				cache[iPool] = new Cache() //iSize) 
				for var k=1 to iSize
					cache[iPool].push(buffers[i].factory())

				
		def addSystem(initialize: SystemInitialize, execute: SystemExecute)
			systems[count++] = { initialize, execute } 

		def initialize()
			for var i=0 to (count-1)
				systems[i].initialize()


		def execute(delta:double)
			for var i=0 to (count-1)
				systems[i].execute(delta)
			

		def setEntityRemovedListener(removed:EntityRemovedListener)
			entityRemoved = removed

		def componentAddedOrRemoved(entity:Entity*, component:Components)
			for var group in groups
				group.handleEntity(entity, component)

		/**
		* send antity back to it's pool
		*/		
		def deleteEntity(entity:Entity*)
			entity.setActive(false)
			cache[entity.pool].push(entity)
			entityRemoved(entity)

		/**
		* create an entity from the pool
		*/
		def createEntity(name:string, pool:int, active:bool):Entity*
			var id = this.id++
			return  (this.pool[id]
				.setId(id)
				.setName(name)
				.setPool(pool)
				.setActive(active))
				

		def getGroup(matcher : Matcher) : Group
			matcher.addRef()
			if groups.length() > matcher.id 
				return groups.nth_data(matcher.id)
			else
				groups.prepend(new Group(matcher))
				/**
				 * according to the docs, GLib.List doesn't referece count, therefore
				 * due to switching from Gee.ArrayList go GLib.List, we are required
				 * to manually bump the refCount
				 */
				// matcher.addRef()
				for var i = 0 to (this.id-1) do groups.nth_data(0).handleEntitySilently(&pool[i])
				return groups.nth_data(0)


