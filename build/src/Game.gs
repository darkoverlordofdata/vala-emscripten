/**
 * Game controller 
 */
uses SDL
uses Emscripten
uses entitas
	
[Compact, CCode ( /** reference counting */
	ref_function = "game_addRef", 
	unref_function = "game_release"
)]
class Game
	refCount: int = 1
	def addRef() : unowned Game
		GLib.AtomicInt.add (ref refCount, 1)
		return this
	def release() 
		if GLib.AtomicInt.dec_and_test (ref refCount) do this.free ()
	def extern free()
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

	player : Entity*
	

	construct(width:int, height:int)
		this.width = width
		this.height = height

	def initialize()
		factory = new Factory()
		factory.createBackground(0)
		factory.createBackground(1)
		player = factory.createPlayer()
		for var i=1 to 10 do factory.createBullet()
		for var i=1 to 15 do factory.createEnemy1()
		for var i=1 to 10 do factory.createEnemy2()
		for var i=1 to  5 do factory.createEnemy3()
		systems = new Systems()
		systems.initialize(this, factory)
		

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


