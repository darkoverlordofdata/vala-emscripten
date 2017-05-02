/**
 * Game controller 
 */
uses SDL
uses Emscripten
uses entitas
	
// [Compact, CCode ( /** reference counting */
// 	ref_function = "game_addRef", 
// 	unref_function = "game_release"
// )]
// class Game

[Pseudo]
class Game
	width		: int
	height		: int
	mark1		: double
	mark2		: double
	delta		: double
	mouseX		: double
	mouseY		: double
	mouseDown	: bool
	running		: bool
	keys		: uint8[256]
	evt			: SDL.Event
	surface		: unowned Surface
	factory		: Factory
	systems		: Systems
	sprites		: List of Entity* = new List of Entity*

	k           : int
	t           : double
	t1          : double = 0.0
	t2          : double = 0.0
	t3          : double = 0.0
	

	construct(width:int, height:int)
		this.width = width
		this.height = height

	def initialize()
		factory = new Factory()
		systems = new Systems(this, factory)
		systems.initialize()
		// list the entities in the console
		// for var i=0 to (POOL.length-1)
		// 	// if !POOL[i].isActive() do continue
		// 	if POOL[i].name == null do continue
		// 	print POOL[i].toString()
		

	def start()
		running = true
		mark1 = emscripten_get_now()/1000

	def processEvents()
		while Event.poll(out evt) != 0

			case evt.type
				when EventType.QUIT
					running = false
				when EventType.KEYDOWN
					keys[evt.key.keysym.sym] = 1
				when EventType.KEYUP
					keys[evt.key.keysym.sym] = 0
				when EventType.MOUSEMOTION
					mouseX = evt.motion.x
					mouseY = evt.motion.y
				when EventType.MOUSEBUTTONDOWN
					mouseDown = true
				when EventType.MOUSEBUTTONUP
					mouseDown = false


	def update()
		mark2 = emscripten_get_now()/1000
		delta = mark2 - mark1
		mark1 = mark2

		processEvents()

		t1 = emscripten_get_now()/1000
		systems.update(delta)
		t2 = emscripten_get_now()/1000
		t3 = t2 - t1
		t = t + t3
		k += 1
		if k == 1000
			k = 0
			t = t / 1000.0
			print "%f", t
			t = 0


		surface.fill(null, surface.format.map_rgb(255, 0, 0))
		for var i=0 to (POOL.length-1)
			if !POOL[i].isActive() do continue
			POOL[i].sprite.surface.blit(null, surface, 
				{ 	
					(int16)POOL[i].bounds.x, 
					(int16)POOL[i].bounds.y, 
					(int16)POOL[i].bounds.w, 
					(int16)POOL[i].bounds.h
				})

		surface.flip()


	// /**
	// * Implement reference counting
	// */
	// refCount: int = 1
	// def addRef() : unowned Game
	// 	GLib.AtomicInt.add (ref refCount, 1)
	// 	return this
	// def release() 
	// 	if GLib.AtomicInt.dec_and_test (ref refCount) do this.free ()
	// def extern free()
