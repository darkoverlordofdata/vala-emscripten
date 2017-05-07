/**
 * Unordered cache 
 */
namespace entitas

	
	class Cache : Object

		items: array of Entity*
		size: int
		
		construct(capacity:int = 4)
			items = new array of Entity*[capacity]
			size = 0

		def isEmpty():bool
			return size == 0

		def get(index: int):Entity*
			if index < 0 || index > size
				print "Can't get cache at %d", index
				return null
			return items[index]

		def put(index: int, entity:Entity*)
			if index < 0 || index >= size
				print "Can't put cache at %d", index
				return
			items[index] = entity

		def push(entity: Entity*)
			if size >= items.length do grow(items.length*2)
			items[size++] = entity

		def pop():Entity*
			if size <= 0
				print "Unable to pop from queue"
				return null
			return items[--size]

		def grow(newSize:int)
			var temp = items
			items = new array of Entity*[newSize]
			for var i = 0 to (temp.length-1)
				items[i] = temp[i]
			

