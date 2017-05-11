using SDL;
using SDL.Video;
using SDLImage;

namespace sdx {

	public errordomain SdlException {
		Initialization,
		ImageInitialization,
		TtfInitialization,
		TextureFilteringNotEnabled,
		OpenWindow,
		CreateRenderer
	}


	/**
	 * Global vars
	 * 
	 */
	Renderer renderer;
	sdx.Font font;
	sdx.Font smallFont;
	sdx.Font largeFont;
	sdx.graphics.Sprite fpsSprite;
	SDL.Video.Color fpsColor;
	bool showFps;
	double fps;
	double delta;
	double mouseX;
	double mouseY;
	bool mouseDown;
	bool running;
	uint8[] keys;

	int _frames;
	Event _evt;
	double _elapsed;
	double _freq;
	double _mark1;
	double _mark2;



	/**
	 * Initialization
	 * 
	 */
	Window initialize(int width, int height, string name) {
		keys = new uint8[256]; 

		if (SDL.init(SDL.InitFlag.VIDEO | SDL.InitFlag.TIMER | SDL.InitFlag.EVENTS) < 0)
			throw new SdlException.Initialization(SDL.get_error());
 

		if (SDLImage.init(SDLImage.InitFlags.PNG) < 0)
			throw new SdlException.ImageInitialization(SDL.get_error());

		if (!SDL.Hint.set_hint(Hint.RENDER_SCALE_QUALITY, "1"))	
			throw new SdlException.TextureFilteringNotEnabled(SDL.get_error());

		if (SDLTTF.init() == -1)
			throw new SdlException.TtfInitialization(SDL.get_error());
    
		var window = new Window(name, Window.POS_CENTERED, Window.POS_CENTERED, width, height, WindowFlags.SHOWN);
		if (window == null)
			throw new SdlException.OpenWindow(SDL.get_error());
		
		sdx.renderer = Renderer.create(window, -1, RendererFlags.ACCELERATED | RendererFlags.PRESENTVSYNC);
		if (sdx.renderer == null)
			throw new SdlException.CreateRenderer(SDL.get_error());

		_freq = SDL.Timer.get_performance_frequency();
		fpsColor = sdx.Color.AntiqueWhite;

		MersenneTwister.init_genrand((ulong)SDL.Timer.get_performance_counter());
		return window;
	}

	double getRandom() {
		return MersenneTwister.genrand_real2();
	}

	void setDefaultFont(string path, int size) {
		font = new sdx.Font(path, size);
	}

	void setSmallFont(string path, int size) {
		smallFont = new sdx.Font(path, size);
	}

	void setLargeFont(string path, int size) {
		largeFont = new sdx.Font(path, size);
	}

	void setShowFps(bool value) {
		showFps = value;
		if (showFps == true) {
			fpsSprite = new sdx.graphics.Sprite("%2.2f".printf(60), font, fpsColor);
			fpsSprite.centered = false;
		} else {
			fpsSprite = null;
		}
	}

	void drawFps() {
		if (showFps) {
			fpsSprite.setText("%2.2f".printf(fps), font, fpsColor);
			fpsSprite.render(renderer, 0, 0);
		}
	}

	double getNow() {
		return (double)SDL.Timer.get_performance_counter()/_freq;
	} 

	void start() {
		running = true;
		_mark1 = (double)SDL.Timer.get_performance_counter()/_freq;
	}

	void update() {
		_mark2 = (double)SDL.Timer.get_performance_counter()/_freq;
		delta = _mark2 - _mark1;
		_mark1 = _mark2;
		_frames++;
		_elapsed = _elapsed + delta;
		if (_elapsed > 1.0) {
			fps = (int)((double)_frames / _elapsed);
			_elapsed = 0.0;
			_frames = 0;
		}
	}

	void processEvents() {
		while (SDL.Event.poll(out _evt) != 0) {

			switch (_evt.type) {
				case SDL.EventType.QUIT:
					running = false;
					break;
				case SDL.EventType.KEYDOWN:
					if (_evt.key.keysym.sym < 0 || _evt.key.keysym.sym > 255) break;
					keys[_evt.key.keysym.sym] = 1;
					break;
				case SDL.EventType.KEYUP:
					if (_evt.key.keysym.sym < 0 || _evt.key.keysym.sym > 255) break;
					keys[_evt.key.keysym.sym] = 0;
					break;
				case SDL.EventType.MOUSEMOTION:
					mouseX = _evt.motion.x;
					mouseY = _evt.motion.y;
					break;
				case SDL.EventType.MOUSEBUTTONDOWN:
					mouseDown = true;
					break;
				case SDL.EventType.MOUSEBUTTONUP:
					mouseDown = false;
					break;
			}
		}
	}
	
	void begin() {
		renderer.set_draw_color(0, 0, 0, 0);
		renderer.clear();
	}

	void end() {
		sdx.renderer.present();
	}

}