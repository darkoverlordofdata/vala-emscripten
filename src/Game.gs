/**
 * Game controller 
 */
uses SDL
uses Emscripten
uses entitas
uses systems


[Pseudo]
class Game
	instance	: static Game
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
	world		: Factory
	//systems		: Systems
	sprites		: List of Entity* = new List of Entity*

	collision	: Collision
	expire		: Expire
	input		: Input
	physics		: Physics
	remove		: Remove
	spawn		: Spawn

		
	k		   	: int
	t		   	: double
	t1		  	: double = 0.0
	t2		  	: double = 0.0
	t3		  	: double = 0.0

	player : Entity*
	

	construct(width:int, height:int)
		instance = this
		this.width = width
		this.height = height

	def initialize()
		world = new Factory()
		world.setEntityRemovedListener(entityRemoved)
		world.createBackground(0)
		world.createBackground(1)
		player = world.createPlayer()
		for var i=1 to 10 do world.createBullet()
		for var i=1 to 15 do world.createEnemy1()
		for var i=1 to 10 do world.createEnemy2()
		for var i=1 to  5 do world.createEnemy3()
		for var i=1 to 90 do world.createParticle()

		spawn = new Spawn(this, world)
		input = new Input(this, world)
		collision = new Collision(this, world)
		physics = new Physics(this, world)
		expire = new Expire(this, world)
		remove = new Remove(this, world)

		world.addSystem(spawn.initialize, spawn.execute)
		world.addSystem(input.initialize, input.execute)
		world.addSystem(collision.initialize, collision.execute)
		world.addSystem(physics.initialize, physics.execute)
		world.addSystem(expire.initialize, expire.execute)
		world.addSystem(remove.initialize, remove.execute)
		
		world.initialize()
			
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
		world.execute(delta)
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

		for entity in sprites
			if !entity.isActive() do continue
			if entity.hasIndex()
				var w = (int16)(entity.bounds.w / entity.index.limit)
				var h = (int16)entity.bounds.h
				var x = (int16)0
				var y = (int16)(entity.index.value * w)
				entity.sprite.surface.blit({ x, y, w, h }, surface, 
					{ 	
						(int16)entity.bounds.x, 
						(int16)entity.bounds.y, 
						(int16)w, 
						(int16)h
					})
			else
				entity.sprite.surface.blit(null, surface, 
					{ 	
						(int16)entity.bounds.x, 
						(int16)entity.bounds.y, 
						(int16)entity.bounds.w, 
						(int16)entity.bounds.h
					})


		surface.flip()


/**
 * add to game.sprites in layer order
 */
def entityAdded(e:Entity*) 
	if !e.hasSprite() do return

	var layer = e.layer.value
	if Game.instance.sprites.length() == 0
		Game.instance.sprites.append(e)

	else
		var i = 0
		for s in Game.instance.sprites
			assert(s != null)
			if layer <= s.layer.value
				Game.instance.sprites.insert(e, i)
				return
			else
				i++
		Game.instance.sprites.append(e)

/**
* remove from game.sprites
*/
def entityRemoved(e:Entity*) 
	Game.instance.sprites.remove(e)

	
