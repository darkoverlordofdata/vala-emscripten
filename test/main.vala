using Emscripten;
/**
 *	profiling data
 */
public int k;
public double t;
public double t1 = 0.0;
public double t2 = 0.0;
public double t3 = 0.0;

errordomain TestError {
	Wow
}
/**
 * game
 * 
 * -s EXPORTED_FUNCTIONS='["_game"]'
 * Invoked by clicking on the start button in the browser
 *
 */
public void game() {

	test();

	stdout.printf("indexOf = %d\n", "this is a test".indexOf("is"));

	try {
		throw new TestError.Wow("it works");
	} catch (TestError e) {
		stdout.printf("Error Message %s\n", e.message);
	}

}

/**
 *	random number
 */
public double nextRand() {
	return random();
}




//  [Compact]
//  public class Items<G> {
//  	public string _name;
//  	public Items(string name) {
//  		_name = name;
//  	}
//  }