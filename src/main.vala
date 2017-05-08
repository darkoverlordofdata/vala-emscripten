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

/**
 * game
 * 
 * -s EXPORTED_FUNCTIONS='["_game"]'
 * Invoked by clicking on the start button in the browser
 *
 */
public void game() {

	test();

	var window = sdx.initialize(720, 512, "Shmupwarz");
	var game = new Game(720, 512);
	game.initialize();
	game.start();
	emscripten_set_main_loop_arg(mainloop, game, 0, 1);
	return;
}

/**
 *	random number
 */
public double nextRand() {
	return emscripten_random();
}


/**
 * the main loop
 */
public void mainloop(void* arg) {
	var game = (Game*)arg;

	t1 = emscripten_get_now()/1000;
	game->update();
	t2 = emscripten_get_now()/1000;
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
