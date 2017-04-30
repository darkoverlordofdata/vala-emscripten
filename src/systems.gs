/**
 * Game controller 
 */
uses SDL
uses Emscripten
uses entitas


[Compact]
class Systems

	FireRate    : double = 0.1
	timeToFire  : double = 0.0
	shoot       : bool
	scale       : double = 1.0
	game		: unowned Game
	factory		: unowned Factory
	player		: Entity*


	construct(game:Game, factory:Factory)
		this.game = game
		this.factory = factory
		factory.createBackground(0)
		factory.createBackground(1)
		player = factory.createPlayer()
		factory.createBullet()
		factory.createBullet()
		factory.createBullet()
		factory.createBullet()
		factory.createBullet()
		factory.createBullet()
		factory.createBullet()
		factory.createBullet()
		factory.createBullet()
		factory.createBullet()

	def update(delta:double)
		inputSystem(delta)
		physicsSystem(delta)

	def inputSystem(delta:double)
		player.bounds.x = (int)(game.mouseX-player.bounds.w/2)
		player.bounds.y = (int)(game.mouseY-player.bounds.h/2)
		if shoot do timeToFire -= delta
		if timeToFire < 0.0
			// factory.newBullet((int)player.position.x - 27, (int)player.position.y + 2)
			// factory.newBullet((int)player.position.x + 27, (int)player.position.y + 2)
			timeToFire = FireRate


	def physicsSystem(delta:double)
		for var i=0 to (POOL.length-1)
			if !POOL[i].isActive() do continue
			if POOL[i].hasVelocity()
				POOL[i].position.x += POOL[i].velocity.x * delta
				POOL[i].position.y += POOL[i].velocity.y * delta

		

