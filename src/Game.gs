/**
 * Game controller 
 */
uses entitas
uses systems


class Game : Object

	instance	: static Game
	width		: int
	height		: int
	world		: Factory

	collision	: CollisionSystem
	expire		: ExpireSystem
	input		: InputSystem
	physics		: PhysicsSystem
	remove		: RemoveSystem
	spawn		: SpawnSystem
	animate		: AnimationSystem
	display		: DisplaySystem
	score		: ScoreSystem


	construct(width: int, height: int)
		instance = this
		this.width = width
		this.height = height

	def initialize()

		sdx.setSmallFont("assets/fonts/OpenDyslexic-Bold.otf", 16)
		sdx.setDefaultFont("assets/fonts/OpenDyslexic-Bold.otf", 24)
		sdx.setShowFps(true)

		world = new Factory()
		world.setEntityRemovedListener(entityRemoved)

		spawn = new SpawnSystem(this, world)
		input = new InputSystem(this, world)
		collision = new CollisionSystem(this, world)
		physics = new PhysicsSystem(this, world)
		expire = new ExpireSystem(this, world)
		remove = new RemoveSystem(this, world)
		animate = new AnimationSystem(this, world)
		display = new DisplaySystem(this, world)
		score = new ScoreSystem(this, world)

		world.addSystem(spawn.initialize, spawn.execute)
		world.addSystem(input.initialize, input.execute)
		world.addSystem(physics.initialize, physics.execute)
		world.addSystem(collision.initialize, collision.execute)
		world.addSystem(animate.initialize, animate.execute)
		world.addSystem(expire.initialize, expire.execute)
		world.addSystem(remove.initialize, remove.execute)
		world.addSystem(score.initialize, score.execute)
		world.addSystem(display.initialize, display.execute)
		world.initialize()
		world.createBackground()
			
	def start()
		sdx.start()

	def update()
		sdx.update()		
		sdx.processEvents()
		world.execute(sdx.delta)

	def draw()
		sdx.begin()
		for sprite in display.sprites
			if sprite.isActive() do display.draw(sprite)
		sdx.drawFps()
		sdx.end()


