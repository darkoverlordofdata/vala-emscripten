[Compact, CCode (ref_function = "foo_up", unref_function = "foo_down")]
class Foo
	

	ref_count: int = 1

	def up () : unowned Foo 
		GLib.AtomicInt.add (ref this.ref_count, 1)
		stdout.printf("add %d\n", ref_count)
		return this
	

	def down () 
		if GLib.AtomicInt.dec_and_test (ref this.ref_count)
			print "dec_and_test, free %d", ref_count
			this.free ()
		
		print "dec_and_test %d\n", ref_count
	

	def extern free ()

	def method ()
		pass  


def run_test () 
	stdout.printf("can you see me?\n")
	foo:Foo = new Foo ()	// allocate, ref
	foo.method ()
	bar:Foo = foo		   // ref
 // unref, unref => free
