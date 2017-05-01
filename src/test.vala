[Compact]
[CCode (ref_function = "foo_up", unref_function = "foo_down")]
public class Foo {

    public int ref_count = 1;

    public unowned Foo up () {
        GLib.AtomicInt.add (ref this.ref_count, 1);
        stdout.printf("add %d\n", ref_count);
        return this;
    }

    public void down () {
        if (GLib.AtomicInt.dec_and_test (ref this.ref_count)) {
            stdout.printf("dec_and_test, free %d", ref_count);
            this.free ();
        }
        stdout.printf("dec_and_test %d\n", ref_count);
    }

    private extern void free ();
    public void method () { }
}

void run_test () {
    stdout.printf("can you see me?\n");
    Foo foo = new Foo ();    // allocate, ref
    foo.method ();
    Foo bar = foo;           // ref
} // unref, unref => free
