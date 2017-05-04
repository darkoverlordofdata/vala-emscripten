/**
 * Entity Factory
 */
uses SDL
uses SDL.Video
uses SDLImage
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

	/**
	 * The stuff that all entities have
	 */
	def createBase(game:Game, name:string, path: string, pool:int, scale:double = 1.0, active:bool = false):Entity*
		var sprite = new sdx.Sprite(game.renderer, path)
		return (createEntity(name, pool, active)
			.addPosition(0, 0)
			.addLayer(pool)
			.addBounds(0, 0, sprite.width, sprite.height)
            .addScale(scale, scale)
			.addSprite(sprite, sprite.width, sprite.height))

	/**
	 * specialize background
	 */
	def createBackground(game:Game):Entity*
		var e = (createBase(game, "background", "assets/images/background.png", Pool.BACKGROUND, 2.0, true)
			.setBackground(true))
		entityAdded(e)
		return e

	def createPlayer(game:Game):Entity*
		var e = createBase(game, "player", "assets/images/spaceshipspr.png", Pool.PLAYER, 1.0, true)
		entityAdded(e)
		return e

	def createBullet(game:Game):Entity*
		var entity = (createBase(game, "bullet", "assets/images/bullet.png", Pool.BULLET)
			// .addSound(new audio.Sound(Sdx.files.resource("sounds/pew.wav")))
			.addTint(0xd2, 0xfa, 0, 0xfa)
			.addExpires(1.0)
			.addHealth(2, 2)
			.addVelocity(0, -800)
			.setBullet(true))
		cache[Pool.BULLET].prepend(entity)
		return entity

	def createEnemy1(game:Game):Entity*
		var entity = (
			createBase(game, "enemy1", "assets/images/enemy1.png", Pool.ENEMY1)
			.addHealth(10, 10)
			.addVelocity(0, 40)
			// .addText("100%", new s2d.Sprite.text("100%", Sdx.app.font, Color.Lime))
			.setEnemy1(true))
		cache[Pool.ENEMY1].prepend(entity)
		return entity

	def createEnemy2(game:Game):Entity*
		var entity = (
			createBase(game, "enemy2", "assets/images/enemy2.png", Pool.ENEMY2)
			.addHealth(20, 20)
			.addVelocity(0, 30)
			// .addText("100%", new s2d.Sprite.text("100%", Sdx.app.font, Color.Lime))
			.setEnemy2(true))
		cache[Pool.ENEMY2].prepend(entity)
		return entity

	def createEnemy3(game:Game):Entity*
		var entity = (
			createBase(game, "enemy3", "assets/images/enemy3.png", Pool.ENEMY3)
			.addHealth(60, 60)
			.addVelocity(0, 20)
			// .addText("100%", new s2d.Sprite.text("100%", Sdx.app.font, Color.Lime))
			.setEnemy3(true))
		cache[Pool.ENEMY3].prepend(entity)
		return entity

	def createExplosion(game:Game):Entity*
		var entity = (
			createBase(game, "explosion", "assets/images/explosion.png", Pool.EXPLOSION, 0.6)
			// .addSound(new audio.Sound(Sdx.files.resource("sounds/asplode.wav")))
			.addTint(0xd2, 0xfa, 0xd2, 0x7f)
			.addExpires(0.2)
			.addTween(0.006, 0.6, -3, false, true))
		cache[Pool.EXPLOSION].prepend(entity)
		return entity

	def createBang(game:Game):Entity*
		var entity = (
			createBase(game, "bang", "assets/images/explosion.png", Pool.BANG, 0.3)
			// .addSound(new audio.Sound(Sdx.files.resource("sounds/smallasplode.wav")))
			.addTint(0xd2, 0xfa, 0xd2, 0x9f)
			.addExpires(0.2)
			.addTween(0.003, 0.3, -3, false, true))
		cache[Pool.BANG].prepend(entity)
		return entity

	def createParticle(game:Game):Entity*
		var entity = (
			createBase(game, "particle", "assets/images/star.png", Pool.PARTICLE)
			.addTint(0xd2, 0xfa, 0xd2, 0xfa)
			.addExpires(0.75)
			.addVelocity(0, 0))
		cache[Pool.PARTICLE].prepend(entity)
		return entity

	def newBullet(x:int, y:int)
		if cache[Pool.BULLET].length() == 0 
			print "out of bullets"
			return

		var entity = cache[Pool.BULLET].nth_data(0)
		cache[Pool.BULLET].remove_link(cache[Pool.BULLET].nth(0))
		entityAdded(entity
			.setPosition(x, y)
			.setExpires(1.0)
			.setActive(true))

	def newEnemy1(x:int, y:int) 
		if cache[Pool.ENEMY1].length() == 0
			print "out of enemy1"
			return

		var entity = cache[Pool.ENEMY1].nth_data(0)
		cache[Pool.ENEMY1].remove_link(cache[Pool.ENEMY1].nth(0))
		entityAdded(entity
			.setPosition(x, y)
			.setHealth(10, 10)
			.setActive(true))

	def newEnemy2(x:int, y:int) 
		if cache[Pool.ENEMY2].length() == 0
			print "out of enemy2"
			return

		var entity = cache[Pool.ENEMY2].nth_data(0)
		cache[Pool.ENEMY2].remove_link(cache[Pool.ENEMY2].nth(0))
		entityAdded(entity
			.setPosition(x, y)
			.setHealth(20, 20) 
			.setActive(true))

	def newEnemy3(x:int, y:int) 
		if cache[Pool.ENEMY3].length() == 0
			print "out of enemy3"
			return

		var entity = cache[Pool.ENEMY3].nth_data(0)
		cache[Pool.ENEMY3].remove_link(cache[Pool.ENEMY3].nth(0))
		entityAdded(entity
			.setPosition(x, y)
			.setHealth(60, 60)
			.setActive(true))


	def newExplosion(x:int, y:int)
		if cache[Pool.EXPLOSION].length() == 0
			print "out of explosions"
			return

		var entity = cache[Pool.EXPLOSION].nth_data(0)
		cache[Pool.EXPLOSION].remove_link(cache[Pool.EXPLOSION].nth(0))
		entityAdded(entity
			.setBounds(x, y, (int)entity.bounds.w, (int)entity.bounds.h)
			.setTween(0.006, 0.6, -3, false, true)
			.setPosition(x, y)
			.setScale(0.6, 0.6)
			.setExpires(0.2)
			.setActive(true))

	def newBang(x:int, y:int)
		if cache[Pool.BANG].length() == 0
			print "out of bang"
			return

		var entity = cache[Pool.BANG].nth_data(0)
		cache[Pool.BANG].remove_link(cache[Pool.BANG].nth(0))
		entityAdded(entity
			.setBounds(x, y, (int)entity.bounds.w, (int)entity.bounds.h)
			.setTween(0.003, 0.3, -3, false, true)
			.setPosition(x, y)
			.setScale(0.3, 0.3)
			.setExpires(0.2)
			.setActive(true))

	def newParticle(x:int, y:int) 
		if cache[Pool.PARTICLE].length() == 0
			print "out of particles"
			return

		var radians = emscripten_random() * TAU
		var magnitude = emscripten_random() * 200
		var velocityX = magnitude * Math.cos(radians)
		var velocityY = magnitude * Math.sin(radians)
		var scale = emscripten_random()

		var entity = cache[Pool.PARTICLE].nth_data(0)
		cache[Pool.PARTICLE].remove_link(cache[Pool.PARTICLE].nth(0))
		entityAdded(entity
			.setBounds(x, y, (int)entity.bounds.w, (int)entity.bounds.h)
			.setPosition(x, y)
			.setScale(scale, scale)
			.setVelocity(velocityX, velocityY)
			.setExpires(0.75)
			.setActive(true))

