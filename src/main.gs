uses SDL
uses SDL.Video
uses SDLImage
uses Emscripten

init

	var name = "Shmupwarz"
	var width = 600
	var height = 400

	if SDL.init(SDL.InitFlag.VIDEO | SDL.InitFlag.TIMER | SDL.InitFlag.EVENTS) < 0
		print "Unable to init SDL %s", SDL.get_error()
		return

	if SDLImage.init(SDLImage.InitFlags.PNG) < 0
		print "SDL_image could not initialize!"

	if !SDL.Hint.set_hint(Hint.RENDER_SCALE_QUALITY, "1")	
		print "Warning: Linear texture filtering not enabled!!"	

	if SDLTTF.init() == -1
		print "SDL_ttf could not initialize!"

	// if SDLMixer.open(22050, SDL.Audio.AudioFormat.S16LSB, 2, 4096) == -1
	// 	print "SDL_mixer unagle to initialize!"


	var window = new Window(name, Window.POS_CENTERED, Window.POS_CENTERED, width, height, WindowFlags.SHOWN)
	if window == null
		print "Unable to open window %s", SDL.get_error()
		return
	
	var renderer = Renderer.create(window, -1, RendererFlags.ACCELERATED | RendererFlags.PRESENTVSYNC)
	if renderer == null
		print "Unable to get renderer %s", SDL.get_error()
		return

	var game = new Game(600, 480, renderer)
	game.initialize()
	game.start()
	emscripten_set_main_loop_arg(mainloop, game, 0, 1)

/**
 *	profiling data
 */
k 	: int
t	: double
t1	: double = 0.0
t2	: double = 0.0
t3	: double = 0.0

/**
 * call the main loop
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


