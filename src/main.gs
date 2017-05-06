uses SDL
uses SDL.Video
uses SDLImage
uses Emscripten
uses sdx
uses util

init 

	pass

/**
 * game
 * 
 * -s EXPORTED_FUNCTIONS='["_game"]'
 * Invoked by clicking on the start button in the browser
 *
 */
def game()

	var window = sdx.initialize(720, 512, "Shmupwarz")
	var game = new Game(window) 
	game.initialize()
	game.start()
	emscripten_set_main_loop_arg(mainloop, game, 0, 1)
	return 

/**
 *	profiling data
 */
k 	: int
t	: double
t1	: double = 0.0
t2	: double = 0.0
t3	: double = 0.0

/**
 * the main loop
 */
def mainloop(arg:void*)
	var game = (Game*)arg

	t1 = emscripten_get_now()/1000
	game->update()
	t2 = emscripten_get_now()/1000
	t3 = t2 - t1
	t = t + t3
	k += 1
	if k == 1000
		k = 0
		t = t / 1000.0
		print "%f", t
		t = 0
	
	game->draw()


