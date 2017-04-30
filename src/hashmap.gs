/**
	* HashMap
	*
	* version 1 is sequential access and very slow
	* only used during startup when compiling getGroup for systems
	*/
[Compact]
class HashMap of K, V

	keys: List of K = new List of K
	data: List of V = new List of V


	def hasKey(key:K):bool
		for var k in keys do if k == key do return true
		return false
		

	def add(key:K, value:V)
		// ptr:void* = (void*)value
		// i:int = (int)ptr
		// print "ptr = %d", i
		for var k in keys do if k == key do return
		keys.append(key)
		data.append(value)

	def get(key:K):V
		var index = 0
		for var k in keys
			if k == key do break
			index++

		for var v in data
			if index == 0 do return v
			index--

		return null


	[Compact]
	class Entry of K, V
		key: K
		value: V
		construct(k:K, v:V)
			key = k
			value = v


