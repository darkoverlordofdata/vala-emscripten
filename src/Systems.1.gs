uses SDL
uses Emscripten
uses entitas


/**
 * game systems
 */
[Pseudo]
class Systems

	enemyT1     : double = 1.0
	enemyT2     : double = 4.0
	enemyT3     : double = 6.0
	FireRate	: double = 0.1
	timeToFire  : double = 0.0
	shoot	   	: bool
	scale	   	: double = 1.0
	game		: Game
	factory		: Factory
	player		: Entity*
	physics		: Group
	expiring	: Group
	movable		: Group	
	enemies		: Group
	bullets		: Group

	construct(game:Game, factory:Factory)
		this.game = game
		this.factory = factory

	def initialize()
		factory.createBackground(0)
		factory.createBackground(1)
		player = factory.createPlayer()
		for var i=1 to 10 do factory.createBullet()
		for var i=1 to 15 do factory.createEnemy1()
		for var i=1 to 10 do factory.createEnemy2()
		for var i=1 to  5 do factory.createEnemy3()

		physics 	= factory.getGroup(Matcher.AllOf({Components.VelocityComponent}))
		expiring 	= factory.getGroup(Matcher.AllOf({Components.ExpiresComponent}))
		movable 	= factory.getGroup(Matcher.AllOf({Components.PositionComponent}))
		enemies 	= factory.getGroup(Matcher.AnyOf({
						Components.Enemy1Component,
						Components.Enemy2Component,
						Components.Enemy3Component
					}))
		bullets 	= factory.getGroup(Matcher.AllOf({Components.BulletComponent}))


	/**
	 *	update each game frame
	 */
	def update(delta:double)
		spawnSystem(delta)
		inputSystem(player, delta) 
		collisionSystem(delta)
		for var entity in physics.entities 	do physicsSystem(entity, delta)
		for var entity in expiring.entities do expireSystem(entity, delta)
		for var entity in movable.entities 	do removeSystem(entity, delta)


	/**
	 * collision system
	 */
	def collisionSystem(delta:double)
		pass

	/**
	 * expire system
	 */
	def expireSystem(entity:Entity*, delta:double)
		if entity.isActive() 
			var exp = entity.expires.value - delta
			entity.expires.value = exp
			if entity.expires.value < 0 do factory.deleteEntity(entity)

	/**
	 * input system
	 * process user input
	 */
	def inputSystem(player:Entity*, delta:double)
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
	def physicsSystem(entity:Entity*, delta:double)
		if entity.isActive() 

			var x = entity.position.x + entity.velocity.x * delta
			var y = entity.position.y + entity.velocity.y * delta

			entity.setPosition(x, y)
			entity.bounds.x = (int)x
			entity.bounds.y = (int)y
		
	/**
	 * remove system
	 */
	def removeSystem(entity:Entity*, delta:double)
		if entity.isActive() 
			case entity.pool
				when Pool.ENEMY1
					if entity.position.y > game.height do factory.deleteEntity(entity)
					
				when Pool.ENEMY2
					if entity.position.y > game.height do factory.deleteEntity(entity)
					
				when Pool.ENEMY3
					if entity.position.y > game.height do factory.deleteEntity(entity)
					
				when Pool.BULLET
					if entity.position.y < 0 do factory.deleteEntity(entity)
					
	/**
	 * spawn system
	 */
	def spawnSystem(delta:double)
		enemyT1 = spawnEnemy(delta, enemyT1, 1)
		enemyT2 = spawnEnemy(delta, enemyT2, 2)
		enemyT3 = spawnEnemy(delta, enemyT3, 3)

	def spawnEnemy(delta:double , t:double , enemy:int):double 
		var d1 = t-delta
		if (d1 < 0.0) 
			case enemy
				when 1
					var x = (int)(emscripten_random() * (game.width-70)) + 35
					factory.newEnemy1(x, -35)
					return 1.0
				when 2
					var x = (int)(emscripten_random() * (game.width-172)) + 85
					factory.newEnemy2(x, -85)
					return 4.0
				when 3
					var x = (int)(emscripten_random() * (game.width-320)) + 160
					factory.newEnemy3(x, -160)
					return 6.0
				default
					return 0.0
			
		else 
			return d1    
