
public void test() {

	var x1 = new Test("frodo", 42);
	var x2 = new Test("this", 43);
	var x3 = new Test("is", 44);
	var x4 = new Test("a", 45);
	var x5 = new Test("test", 46);
	
	HashTable<string, Test> table = new HashTable<string, Test>(str_hash, str_equal);

	table.insert(x1.name, x1);
	table.insert(x2.name, x2);
	table.insert(x3.name, x3);
	table.insert(x4.name, x4);
	table.insert(x5.name, x5);

	var z = table.get("frodo");
	stdout.printf("Found %d\n", z.value);

	table.foreach((key, val) => {
		stdout.printf ("%s => %d\n", key, val.value);
	});

	foreach (string key in table.get_keys ()) {
		stdout.printf ("%s \n", key);
	}

	var a = table.get_keys_as_array();
	stdout.printf("Number of keys %d\n", a.length);
}

public class Test : Object {

	public string name;
	public int value;
	public Test(string name, int value) {
		this.name = name;
		this.value = value;

	}
}