namespace entitas

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
	
	class Mather : Object
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
					result.prepend(index)
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
				indices.prepend(matchers[i].indices[0])
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

