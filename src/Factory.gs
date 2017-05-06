/**
 * Entity Factory
 */
uses Emscripten
uses entitas
uses systems

const TAU: double = 2.0 * Math.PI 
enum Pool
	BACKGROUND
	ENEMY1
	ENEMY2
	ENEMY3
	PLAYER
	BULLET
	EXPLOSION
	BANG
	PARTICLE
	HUD
	Count

/**
 * fabricate specialized entities
 */
[Compact]
class Factory : World

	construct()
		super()
		setPool(256, Pool.Count, {
			Buffer() { pool = Pool.BULLET,      size = 20,  factory = createBullet },
			Buffer() { pool = Pool.ENEMY1,      size = 15,  factory = createEnemy1 },
			Buffer() { pool = Pool.ENEMY2,      size = 5,   factory = createEnemy2 },
			Buffer() { pool = Pool.ENEMY3,      size = 4,   factory = createEnemy3 },
			Buffer() { pool = Pool.EXPLOSION,   size = 10,  factory = createExplosion },
			Buffer() { pool = Pool.BANG,        size = 12,  factory = createBang },
			Buffer() { pool = Pool.PARTICLE,    size = 100, factory = createParticle }
		})


	/**
	 * The stuff that all entities have
	 */
	def createBase(name:string, path: string, pool:int, scale:double = 1.0, active:bool = false):Entity*
		if sdx.Sprite.cache.length == 0
			sdx.Sprite.initialize(Pool.Count)
	
		var sprite = new sdx.Sprite(path)
		return (createEntity(name, pool, active)
			.addPosition(0, 0)
			.addLayer(pool)
			.addBounds(0, 0, sprite.width, sprite.height)
            .addScale(scale, scale)
			.addSprite(sprite, sprite.width, sprite.height))

	/** 
	 *	factory methods:
	 */
	def createBackground():Entity*
		return entityAdded(createBase("background", "assets/images/background.png", Pool.BACKGROUND, 2.0, true)
			.setBackground(true))

	def createPlayer():Entity*
		return entityAdded(createBase("player", "assets/images/spaceshipspr.png", Pool.PLAYER, 1.0, true))

	def createBullet():Entity*
		return (createBase("bullet", "assets/images/bullet.png", Pool.BULLET)
			// .addSound(new audio.Sound(Sdx.files.resource("sounds/pew.wav")))
			.addTint(0xd2, 0xfa, 0, 0xfa)
			.addHealth(2, 2)
			.addVelocity(0, -800)
			.setBullet(true))

	def createEnemy1():Entity*
		return (
			createBase("enemy1", "assets/images/enemy1.png", Pool.ENEMY1)
			.addHealth(10, 10)
			.addVelocity(0, 40)
			.addText("100%", new sdx.Sprite("100%", sdx.smallFont, sdx.Color.LimeGreen))
			.setEnemy1(true))

	def createEnemy2():Entity*
		return (
			createBase("enemy2", "assets/images/enemy2.png", Pool.ENEMY2)
			.addHealth(20, 20)
			.addVelocity(0, 30)
			.addText("100%", new sdx.Sprite("100%", sdx.smallFont, sdx.Color.LimeGreen))
			.setEnemy2(true))

	def createEnemy3():Entity*
		return (
			createBase("enemy3", "assets/images/enemy3.png", Pool.ENEMY3)
			.addHealth(60, 60)
			.addVelocity(0, 20)
			.addText("100%", new sdx.Sprite("100%", sdx.smallFont, sdx.Color.LimeGreen))
			.setEnemy3(true))

	def createExplosion():Entity*
		return (
			createBase("explosion", "assets/images/explosion.png", Pool.EXPLOSION, 0.6)
			// .addSound(new audio.Sound(Sdx.files.resource("sounds/asplode.wav")))
			.addTint(0xd2, 0xfa, 0xd2, 0x7f)
			.addExpires(0.2)
			.addTween(0.006, 0.6, -3, false, true))

	def createBang():Entity*
		return (
			createBase("bang", "assets/images/explosion.png", Pool.BANG, 0.3)
			// .addSound(new audio.Sound(Sdx.files.resource("sounds/smallasplode.wav")))
			.addTint(0xd2, 0xfa, 0xd2, 0x9f)
			.addExpires(0.2)
			.addTween(0.003, 0.3, -3, false, true))

	def createParticle():Entity*
		return (
			createBase("particle", "assets/images/star.png", Pool.PARTICLE)
			.addTint(0xd2, 0xfa, 0xd2, 0xfa)
			.addExpires(0.75)
			.addVelocity(0, 0))

	/**
	 * Get entity from the pool
	 */
	def bullet(x:int, y:int):Entity*
		if cache[Pool.BULLET].isEmpty() 
			print "out of bullets"
			return null

		return entityAdded(cache[Pool.BULLET].pop()
			.setPosition(x, y)
			.setActive(true))

	def enemy1(x:int, y:int):Entity*
		if cache[Pool.ENEMY1].isEmpty()
			print "out of enemy1"
			return null

		return entityAdded(cache[Pool.ENEMY1].pop()
			.setPosition(x, y)
			.setHealth(10, 10)
			.setActive(true))

	def enemy2(x:int, y:int):Entity*
		if cache[Pool.ENEMY2].isEmpty()
			print "out of enemy2"
			return null

		return entityAdded(cache[Pool.ENEMY2].pop()
			.setPosition(x, y)
			.setHealth(20, 20) 
			.setActive(true))

	def enemy3(x:int, y:int):Entity*
		if cache[Pool.ENEMY3].isEmpty()
			print "out of enemy3"
			return null

		return entityAdded(cache[Pool.ENEMY3].pop()
			.setPosition(x, y)
			.setHealth(60, 60)
			.setActive(true))

	def explosion(x:int, y:int):Entity*
		if cache[Pool.EXPLOSION].isEmpty()
			print "out of explosions"
			return null

		var entity = cache[Pool.EXPLOSION].pop()
		entityAdded(entity
			.setBounds(x, y, (int)entity.bounds.w, (int)entity.bounds.h)
			.setTween(0.006, 0.6, -3, false, true)
			.setPosition(x, y)
			.setScale(0.6, 0.6)
			.setExpires(0.2)
			.setActive(true))
		return entity

	def bang(x:int, y:int):Entity*
		if cache[Pool.BANG].isEmpty()
			print "out of bang"
			return null

		var entity = cache[Pool.BANG].pop()
		entityAdded(entity
			.setBounds(x, y, (int)entity.bounds.w, (int)entity.bounds.h)
			.setTween(0.003, 0.3, -3, false, true)
			.setPosition(x, y)
			.setScale(0.3, 0.3)
			.setExpires(0.2)
			.setActive(true))
		return entity

	def particle(x:int, y:int):Entity*
		if cache[Pool.PARTICLE].isEmpty()
			print "out of particles"
			return null

		var radians = emscripten_random() * TAU
		var magnitude = emscripten_random() * 200
		var velocityX = magnitude * Math.cos(radians)
		var velocityY = magnitude * Math.sin(radians)
		var scale = emscripten_random()


		var entity = cache[Pool.PARTICLE].pop()
		entityAdded(entity
			.setBounds(x, y, (int)entity.bounds.w, (int)entity.bounds.h)
			.setPosition(x, y)
			.setScale(scale, scale)
			.setVelocity(velocityX, velocityY)
			.setExpires(0.75)
			.setActive(true))
		return entity

