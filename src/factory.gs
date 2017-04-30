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

 
[Compact]
class Factory

	cache	   : array of List of Entity* 
	//pool: Entity[20]
	id:int = 0
	images: array of Surface = {
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
		

	def createCore(name:string, pool:int, active:bool = false):Entity*
		var id = this.id++
		return POOL[id].setId(id).setName(name).setPool(pool).setActive(active)

	def createEntity(name:string, pool:int, s:Surface, active:bool = false):Entity*
		return (createCore(name, pool, active)
			.addPosition(0, 0)
			.addLayer(pool)
			.addBounds(0, 0, s.w, s.h)
			.addSprite(s))

	def createBackground(tile:int):Entity*
		var e = (createEntity("background", Pool.BACKGROUND, images[Pool.BACKGROUND], true)
			.setBackground(true))
		e.bounds.x = e.bounds.w * tile
		return e

	def createPlayer():Entity*
		return createEntity("player", Pool.PLAYER, images[Pool.PLAYER], true)

	def createBullet():Entity*
		return (
			createEntity("bullet", Pool.BULLET, images[Pool.BULLET])
			.addTint(0xd2, 0xfa, 0, 0xfa)
			.addExpires(1.0)
			.addHealth(2, 2)
			.addVelocity(0, -800)
			.setBullet(true))

	// def newBullet(x:int, y:int)
	// 	if cache[Pool.BULLET].is_empty 
	// 		cache[Pool.BULLET].add(createBullet())
			
	// 	var entity = world.cache[Pool.BULLET].remove_at(0)
	// 	listener.entityAdded(entity
	// 		.setPosition(x, y)
	// 		.setExpires(1.0)
	// 		.setActive(true))

