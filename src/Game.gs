/**
 * Game controller 
 */
uses Emscripten
uses entitas

[Pseudo]
class Game
	instance	: static Game
	width		: int
	height		: int
	world		: Factory

	collision	: systems.Collision
	expire		: systems.Expire
	input		: systems.Input
	physics		: systems.Physics
	remove		: systems.Remove
	spawn		: systems.Spawn
	animate		: systems.Animation
	display		: systems.Display
	score		: systems.Score


	construct(window: SDL.Video.Window)
		instance = this
		window.get_size(out width, out height)

	def initialize()

		sdx.setSmallFont("assets/fonts/OpenDyslexic-Bold.otf", 16)
		sdx.setDefaultFont("assets/fonts/OpenDyslexic-Bold.otf", 24)
		sdx.setShowFps(true)

		world = new Factory()
		world.setEntityRemovedListener(entityRemoved)

		spawn = new systems.Spawn(this, world)
		input = new systems.Input(this, world)
		collision = new systems.Collision(this, world)
		physics = new systems.Physics(this, world)
		expire = new systems.Expire(this, world)
		remove = new systems.Remove(this, world)
		animate = new systems.Animation(this, world)
		display = new systems.Display(this, world)
		score = new systems.Score(this, world)

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
		sdx.renderer.set_draw_color(0, 0, 0, 0)
		sdx.renderer.clear()
		for sprite in display.sprites
			if sprite.isActive() do display.draw(sprite)
		sdx.drawFps()
		sdx.renderer.present()


