using sdx;
using util;

/**
 *	profiling data
 */
public int k;
public double t;
public double t1 = 0.0;
public double t2 = 0.0;
public double t3 = 0.0;
public Rand rnd;

errordomain TestError {
	Wow
}

/**
 * game
 * 
 *
 */
public int main(string args[]) {

	rnd = new Rand();

	var window = sdx.initialize(720, 512, "Shmupwarz");
	var game = new Game(720, 512);
	game.initialize();
	game.start();

	while (sdx.running) {

		t1 = (double)GLib.get_real_time()/1000000.0;
		game.update();
		t2 = (double)GLib.get_real_time()/1000000.0;
		t3 = t2 - t1;
		t = t + t3;
		k += 1;
		if (k == 1000) {
			k = 0;
			t = t / 1000.0;
			stdout.printf("%f\n", t);
			t = 0;
		}
		
		game.draw();
	}
	return 0;
}

/**
 *	random number
 */
public double nextRand() {
	return  rnd.next_double();
}

