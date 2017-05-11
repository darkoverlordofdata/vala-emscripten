using util;

errordomain TestError {
	Wow
}

public int test2(string[] args) {
	stdout.printf("Hello World\n");

	stdout.printf("indexOf = %d\n", "this is a test".indexOf("is"));

	try {
		throw new TestError.Wow("it works");
	} catch (TestError e) {
		stdout.printf("Error Message %s\n", e.message);
	}
	return 0;
}



public class Person : Object {
    public int _age = 32;  
	public string _name;

    public int age {
        get { return _age; }
    }
    public string name {
        get { return _name; }
    }

	public Person(string name, int age) {
		_name = name;
		_age = age;
	}
	public string toString() {
		return _name;
	}
}