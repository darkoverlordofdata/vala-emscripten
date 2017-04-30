uses SDL
uses Emscripten
uses entitas


/**
 * game systems
 */
[Compact]
class Systems

	FireRate	: double = 0.1
	timeToFire  : double = 0.0
	shoot	   : bool
	scale	   : double = 1.0
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

	/**
	 *	update each game frame
	 */
	def update(delta:double)
	
		spawnSystem(delta)
		collisionSystem(delta)
		inputSystem(delta)
		for var i=0 to (POOL.length-1) do physicsSystem(ref POOL[i], delta)
		for var i=0 to (POOL.length-1) do expireSystem(ref POOL[i], delta)
		for var i=0 to (POOL.length-1) do removeSystem(ref POOL[i], delta)



	/**
	 * collision system
	 */
	def collisionSystem(delta:double)
		pass

	/**
	 * expire system
	 */
	def expireSystem(ref entity:Entity, delta:double)
		if entity.isActive() 
			if entity.hasExpires()
				var exp = entity.expires.value - delta
				entity.expires.value = exp
				if entity.expires.value < 0 do factory.deleteEntity(&entity)

	/**
	 * input system
	 * process user input
	 */
	def inputSystem(delta:double)
		var x = (int)game.mouseX
		var y = (int)game.mouseY
		var x1 = x-player.bounds.w/2
		var y1 = y-player.bounds.h/2
		player.setPosition(x1, y1)
		player.bounds.x = x1
		player.bounds.y = y1
		shoot = game.mouseDown || (game.keys[122] == 1)
		if shoot do timeToFire -= delta
		if timeToFire < 0.0
			factory.newBullet(x - 27, y + 2)
			factory.newBullet(x + 27, y + 2)
			timeToFire = FireRate


	/**
	 * physics system
	 * model movement
	 */
	def physicsSystem(ref entity:Entity, delta:double)
		if entity.isActive() 
			if entity.hasVelocity()

				var x = entity.position.x + entity.velocity.x * delta
				var y = entity.position.y + entity.velocity.y * delta

				entity.setPosition(x, y)
				entity.bounds.x = (int)x
				entity.bounds.y = (int)y
		
	/**
	 * remove system
	 */
	def removeSystem(ref entity:Entity, delta:double)
		if entity.isActive() 
			if entity.hasPosition()
				case entity.pool
					when Pool.ENEMY1
						if entity.position.y > game.height do factory.deleteEntity(&entity)
						
					when Pool.ENEMY2
						if entity.position.y > game.height do factory.deleteEntity(&entity)
						
					when Pool.ENEMY3
						if entity.position.y > game.height do factory.deleteEntity(&entity)
						
					when Pool.BULLET
						if entity.position.y < 0 do factory.deleteEntity(&entity)
						
	/**
	 * spawn system
	 */
	def spawnSystem(delta:double)
		pass

