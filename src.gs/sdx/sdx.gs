uses SDL
uses SDL.Video
uses SDLImage

namespace sdx

	exception SdlException
		Initialization
		ImageInitialization
		TtfInitialization
		TextureFilteringNotEnabled
		OpenWindow
		CreateRenderer


	/**
	 * Global vars
	 * 
	 */
	renderer	: Renderer
	font		: sdx.Font
	smallFont	: sdx.Font
	largeFont	: sdx.Font
	fpsSprite	: sdx.graphics.Sprite
	fpsColor	: SDL.Video.Color
	showFps		: bool
	fps			: double
	delta		: double
	mouseX		: double
	mouseY		: double
	mouseDown	: bool
	running		: bool
	keys		: uint8[256]


	_frames		: int
	_evt		: Event
	_elapsed	: double
	_freq		: double
	_mark1		: double
	_mark2		: double

	/**
	 * Initialization
	 * 
	 */
	def initialize(width: int, height: int, name: string): Window
		if SDL.init(SDL.InitFlag.VIDEO | SDL.InitFlag.TIMER | SDL.InitFlag.EVENTS) < 0
			raise new SdlException.Initialization(SDL.get_error())
 

		if SDLImage.init(SDLImage.InitFlags.PNG) < 0
			raise new SdlException.ImageInitialization(SDL.get_error())

		if !SDL.Hint.set_hint(Hint.RENDER_SCALE_QUALITY, "1")	
			raise new SdlException.TextureFilteringNotEnabled(SDL.get_error())

		if SDLTTF.init() == -1
			raise new SdlException.TtfInitialization(SDL.get_error())
    
		var window = new Window(name, Window.POS_CENTERED, Window.POS_CENTERED, width, height, WindowFlags.SHOWN)
		if window == null
			raise new SdlException.OpenWindow(SDL.get_error())
		
		sdx.renderer = Renderer.create(window, -1, RendererFlags.ACCELERATED | RendererFlags.PRESENTVSYNC)
		if sdx.renderer == null
			raise new SdlException.CreateRenderer(SDL.get_error())

		_freq = SDL.Timer.get_performance_frequency()
		fpsColor = sdx.Color.AntiqueWhite

		return window

	def setDefaultFont(path: string, size: int)
		font = new sdx.Font(path, size)

	def setSmallFont(path: string, size: int)
		smallFont = new sdx.Font(path, size)

	def setLargeFont(path: string, size: int)
		largeFont = new sdx.Font(path, size)

	def setShowFps(value: bool)
		showFps = value
		if showFps = true
			fpsSprite = new sdx.graphics.Sprite("%2.2f".printf(60), font, fpsColor)
			fpsSprite.centered = false
		else
			fpsSprite = null

	def drawFps()
		if showFps
			fpsSprite.setText("%2.2f".printf(fps), font, fpsColor)
			fpsSprite.render(renderer, 0, 0)

	def start()
		running = true
		_mark1 = (double)SDL.Timer.get_performance_counter()/_freq

	def update()
		_mark2 = (double)SDL.Timer.get_performance_counter()/_freq
		delta = _mark2 - _mark1
		_mark1 = _mark2
		_frames++
		_elapsed = _elapsed + delta
		if _elapsed > 1.0
			fps = (int)((double)_frames / _elapsed)
			_elapsed = 0.0
			_frames = 0

	def processEvents()
		while SDL.Event.poll(out _evt) != 0

			case _evt.type
				when SDL.EventType.QUIT
					running = false
				when SDL.EventType.KEYDOWN
					keys[_evt.key.keysym.sym] = 1
				when SDL.EventType.KEYUP
					keys[_evt.key.keysym.sym] = 0
				when SDL.EventType.MOUSEMOTION
					mouseX = _evt.motion.x
					mouseY = _evt.motion.y
				when SDL.EventType.MOUSEBUTTONDOWN
					mouseDown = true
				when SDL.EventType.MOUSEBUTTONUP
					mouseDown = false
	
	def begin()
		renderer.set_draw_color(0, 0, 0, 0)
		renderer.clear()

	def end()
		sdx.renderer.present()
	
	

	[Compact]
	class Sdx

		construct(width: int, height: int, basePath: string)

			pass
			