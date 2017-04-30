uses SDL
uses Emscripten


struct Item
	name:string
	value:int

init

	if SDL.init(SDL.InitFlag.VIDEO) < 0
		print "Unable to init SDL %s", SDL.get_error()
		return

	var game = new Game()
	game.surface = Screen.set_video_mode(600, 480, 32, SurfaceFlag.HWSURFACE | SurfaceFlag.DOUBLEBUF)

	if game.surface == null	
		print "Unable to set video mode %s", SDL.get_error()
		return

	WindowManager.set_caption("ShmupWarz", "ShmupWarz")
	game.initialize()
	game.start()
	emscripten_set_main_loop_arg(mainloop, game, 0, 1)


def mainloop(arg:void*)
	var game = (Game*)arg
	game->update()


