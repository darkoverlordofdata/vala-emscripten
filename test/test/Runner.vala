using Emscripten;
using bunny;
using util;


namespace test {

	public class Runner : UnitTest  {
		public Runner () {
			describe("TestRunner");
			setEach({beforeEach, afterEach});

			it("is a 42!", () => { 
				expect(Val.Int(42)).to.equal(Val.Int(32+10));
			});

			it("Cache object", () => {
				var c = new Cache<Person>(1);
				c.enque(x1);
				c.enque(x2);
				c.enque(x3);
				c.enque(x4);
				c.enque(x5);
				var y = c.deque();
				var x = c.deque();
				expect(Val.Int(43)).to.not.equal(Val.Int(x.age));
			});

			it("Queue object", () => {
				var queue = new Queue<string>();
				queue.push_tail ("1");
				queue.push_tail ("2");
				queue.push_tail ("3");

				// Output: ``1 2 3 ``
				string item = null;
				string last = null;
				while ((item = queue.pop_head ()) != null) {
					last = item;
				}
				expect(Val.String("3")).to.equal(Val.String(last));
			});

			it("Table object", () => {
				var table = new HashTable<string, Person>(str_hash, str_equal);

				table.insert(x1.name, x1);
				table.insert(x2.name, x2);
				table.insert(x3.name, x3);
				table.insert(x4.name, x4);
				table.insert(x5.name, x5);

				var a = table.get_keys_as_array();
				expect(Val.Int(5)).to.equal(Val.Int(a.length));
			});
		}
	}
	Person x1;// = new Person("frodo", 42);
	Person x2;// = new Person("this", 43);
	Person x3;// = new Person("is", 44);
	Person x4;// = new Person("a", 45);
	Person x5;// = new Person("test", 46);

	public void beforeEach() {
		//  stdout.printf("Setup!\n");
		x1 = new Person("frodo", 42);
		x2 = new Person("this", 43);
		x3 = new Person("is", 44);
		x4 = new Person("a", 45);
		x5 = new Person("test", 46);
	}
	public void afterEach() {
		//  stdout.printf("Teardown!\n");
		x1 = null;
		x2 = null;
		x3 = null;
		x4 = null;
		x5 = null;
	}
}
