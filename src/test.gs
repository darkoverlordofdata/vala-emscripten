[indent=4]
uses Gee
const MAXIMUM_CAPACITY: int = 16
const LOADING_FACTOR: double = 0.75

struct Item
    name:string
    value:int

init
    var x = new list of Item?
    x.add({"frodo", 42})
    print "%d", x[0].value
    // var z = x.get(0)
    // print "z = %d", z
    // x.add("frodo")
    // x.add("frodo")
    // for var n in x
    //     print "got %d", n.value
    
namespace Gee
    [Compact]
    class Iterable of V
        read_only: bool = false
        items: array of V //
        capacity: int = 0
        // index: int = 0
        size : int
        construct()
            pass
            

    [Compact]
    class Iterator of V
        it: unowned Iterable of V
        index: int = 0
        construct(it:Iterable of V)
            print "new iterator"

        def next():bool
            print "next %d", index
            print "next"
            if !has_next() do return false
            index++
            print "next %d", index
            return true

        def has_next():bool
            print "has_next %d, %d", index, it.size
            return index < it.size
        
        def get():V
            print "Iterator::get %d", index
            return it.items[index]
        

    [Compact]
    class ArrayList of G : Iterable of G

        construct(capacity:int=MAXIMUM_CAPACITY)
            items = new array of G[capacity]
            size = 0
            this.capacity = capacity

        def add(item:G)
            //if size == capacity do grow_if_needed(1)
            items[size++] = item

        def set(index:int, item:G)
            assert(index >= 0)
            assert(index < size)
            items[index] = item
            

        def get(index:int):G
            print "get at %d", index
            // assert(index >= 0)
            // assert(index < size)
            return items[index]

        def iterator():Iterator of G
            return new Iterator of G(this)


        def grow_if_needed(a:int)
            pass

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

        data_: array of V = new array of V[5]

        def hasKey(key:K):bool
            for var k in keys do if k == key do return true
            return false
            

        def add(key:K, value:V)
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


