/**
 * Entity Factory
 */
uses SDL
uses Emscripten
uses entitas

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
		images =  {
			new Surface.load("assets/images/background.png"),
			new Surface.load("assets/images/enemy1.png"),
			new Surface.load("assets/images/enemy2.png"),
			new Surface.load("assets/images/enemy3.png"),
			new Surface.load("assets/images/spaceshipspr.png"),
			new Surface.load("assets/images/bullet.png"),
			new Surface.load("assets/images/explosion.png"),
			new Surface.load("assets/images/explosion.png"),
			new Surface.load("assets/images/particle.png")
		}
		
	def createBase(name:string, pool:int, s:Surface, active:bool = false):Entity*
		return (createEntity(name, pool, active)
			.addPosition(0, 0)
			.addLayer(pool)
			.addBounds(0, 0, s.w, s.h)
			.addSprite(s))
	/**
	 * specialize background
	 */
	def createBackground(tile:int):Entity*
		var e = (createBase("background", Pool.BACKGROUND, images[Pool.BACKGROUND], true)
			.setBackground(true))
		e.bounds.x = e.bounds.w * tile
		return e

	def createPlayer():Entity*
		return createBase("player", Pool.PLAYER, images[Pool.PLAYER], true)

	def createBullet():Entity*
		var entity = (createBase("bullet", Pool.BULLET, images[Pool.BULLET])
			.addTint(0xd2, 0xfa, 0, 0xfa)
			.addExpires(1.0)
			.addHealth(2, 2)
			.addVelocity(0, -800)
			.setBullet(true))
		cache[Pool.BULLET].append(entity)
		return entity

	def createEnemy1():Entity*
		var entity = (
			createBase("enemy1", Pool.ENEMY1, images[Pool.ENEMY1])
			.addHealth(10, 10)
			.addVelocity(0, 40)
			// .addText("100%", new s2d.Sprite.text("100%", Sdx.app.font, Color.Lime))
			.setEnemy1(true))
		cache[Pool.ENEMY1].append(entity)
		return entity

	def createEnemy2():Entity*
		var entity = (
			createBase("enemy2", Pool.ENEMY2, images[Pool.ENEMY2])
			.addHealth(20, 20)
			.addVelocity(0, 30)
			// .addText("100%", new s2d.Sprite.text("100%", Sdx.app.font, Color.Lime))
			.setEnemy2(true))
		cache[Pool.ENEMY2].append(entity)
		return entity

	def createEnemy3():Entity*
		var entity = (
			createBase("enemy3", Pool.ENEMY3, images[Pool.ENEMY3])
			.addHealth(60, 60)
			.addVelocity(0, 20)
			// .addText("100%", new s2d.Sprite.text("100%", Sdx.app.font, Color.Lime))
			.setEnemy3(true))
		cache[Pool.ENEMY3].append(entity)
		return entity

	def newBullet(x:int, y:int)
		if cache[Pool.BULLET].length() == 0 
			print "out of bullets"
			return

		var entity = cache[Pool.BULLET].nth_data(0)
		cache[Pool.BULLET].remove_link(cache[Pool.BULLET].nth(0))
		(entity
			.setPosition(x, y)
			.setExpires(1.0)
			.setActive(true))

	def newEnemy1(x:int, y:int) 
		if cache[Pool.ENEMY1].length() == 0
			print "out of enemy1"
			return

		var entity = cache[Pool.ENEMY1].nth_data(0)
		cache[Pool.ENEMY1].remove_link(cache[Pool.ENEMY1].nth(0))
		(entity
			.setPosition(x, y)
			.setHealth(10, 10)
			.setActive(true))

	def newEnemy2(x:int, y:int) 
		if cache[Pool.ENEMY2].length() == 0
			print "out of enemy2"
			return

		var entity = cache[Pool.ENEMY2].nth_data(0)
		cache[Pool.ENEMY2].remove_link(cache[Pool.ENEMY2].nth(0))
		(entity
			.setPosition(x, y)
			.setHealth(20, 20) 
			.setActive(true))

	def newEnemy3(x:int, y:int) 
		if cache[Pool.ENEMY3].length() == 0
			print "out of enemy3"
			return

		var entity = cache[Pool.ENEMY3].nth_data(0)
		cache[Pool.ENEMY3].remove_link(cache[Pool.ENEMY3].nth(0))
		(entity
			.setPosition(x, y)
			.setHealth(60, 60)
			.setActive(true))


