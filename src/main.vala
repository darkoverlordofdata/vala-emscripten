using sdx;
using util;
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

	var window = sdx.initialize(720, 512, "Shmupwarz");
	var game = new Game(720, 512);
	game.initialize();
	game.start();
	setMainLoopArg(mainloop, game);
	return;
}

/**
 *	random number
 */
public double nextRand() {
	return random();
}


/**
 * the main loop
 */
public void mainloop(void* arg) {
	var game = (Game*)arg;

	t1 = getNow()/1000;
	game->update();
	t2 = getNow()/1000;
	t3 = t2 - t1;
	t = t + t3;
	k += 1;
	if (k == 1000) {
		k = 0;
		t = t / 1000.0;
		stdout.printf("%f\n", t);
		t = 0;
	}
	
	game->draw();

}


//  [Compact]
//  public class Items<G> {
//  	public string _name;
//  	public Items(string name) {
//  		_name = name;
//  	}
//  }