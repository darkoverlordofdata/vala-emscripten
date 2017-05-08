uses sdx
uses util
uses Emscripten

// def test()

// 	stuff: HashTable of string, int = new HashTable of string, int(str_hash, str_equal)

// 	stuff.insert("frodo", 42)
// 	stuff.insert("this", 43)
// 	stuff.insert("is", 44)
// 	stuff.insert("a", 45)
// 	stuff.insert("test", 46)

// 	var z = stuff.get("a")
// 	print "Found %d", z

// 	stuff.foreach(eachStuff)

// def eachStuff(key:string, val:int)
// 	print "%s => %d", key, val

/**
 * game
 * 
 * -s EXPORTED_FUNCTIONS='["_game"]'
 * Invoked by clicking on the start button in the browser
 *
 */
def game()

	test()

	var window = sdx.initialize(720, 512, "Shmupwarz")
	var game = new Game(720, 512) 
	game.initialize()
	game.start()
	emscripten_set_main_loop_arg(mainloop, game, 0, 1)
	return 

/**
 *	random number
 */
def nextRand(): double
	return emscripten_random()

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


