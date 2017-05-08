namespace entitas

	
	class Group : Object
		matcher		: unowned Matcher
		entities	: List of Entity* = new List of Entity*
		
		construct(matcher: Matcher)
			this.matcher = matcher

		/** Add entity to group */
		def handleEntitySilently(entity : Entity*)
			if matcher.matches(entity) do entities.prepend(entity)
			else do entities.remove(entity)

		/** Add entity to group and raise events */
		def handleEntity(entity : Entity*, index : Components)
			if matcher.matches(entity) do entities.prepend(entity) 
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
						
