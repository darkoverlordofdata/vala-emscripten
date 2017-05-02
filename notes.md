#### notes
no data structs (list, dict, array are from libGee), only GList, struct and [].
however, libGee is implemented in Vala. check dova-core for tips on integrating my own no-g version of libGee
missing some string handling - regex based
no virtual or override
no interface
no abstract
no for..in Iterable requres GObject
no [Flags] enum
subclasses, like derived structs, cannot declare instance members
limited generics - only primitive types except for builtins (List)

Basically, anything that relies on GTypeInfo or GObject is broken. 
Other stuff might work, and should be fixable by suplying missing runtime 

classes should implement ref counting for sane behaviour.
this requires some biolerplate:

	[Compact, CCode ( /** reference counting */
		ref_function = "entitas_<className>_addRef", 
		unref_function = "entitas_<className>_release"
	)]
	class <ClassName>
        ...
		def addRef() : unowned <ClassName>
			GLib.AtomicInt.add (ref refCount, 1)
			return this
		def release() 
			if GLib.AtomicInt.dec_and_test (ref refCount) do this.free ()
		def extern free()
		refCount: int = 1

### fixed

array concat:

    var x = array of int[0]
    x += 42

string funcs (ascii only):

    .up()
    .down()
    .reverse()

reference counting
string comparison
string.join
string.joinv
string.split

varoius list methods

convert +append bubble_explo*.png ../bubble_explo.png



Rebel Alliance logo By User:Tkgd2007 [Public domain], via Wikimedia Commons