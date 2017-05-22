/**
 * Entity Factory
 */
using entitas;
using systems;
using GLib.Math;

const double TAU = 2.0 * Math.PI; 
enum Pool {
	BACKGROUND,
	ENEMY1,
	ENEMY2,
	ENEMY3,
	PLAYER,
	BULLET,
	EXPLOSION,
	BANG,
	PARTICLE,
	HUD,
	Count
}

/**
 * fabricate specialized entities
 */
public class Factory : World {

	public Factory() {
		base();
		setPool(256, Pool.Count, {
			Buffer(Pool.BULLET, 	 20, createBullet),
			Buffer(Pool.ENEMY1, 	 15, createEnemy1),
			Buffer(Pool.ENEMY2,  	  5, createEnemy2),
			Buffer(Pool.ENEMY3,  	  4, createEnemy3),
			Buffer(Pool.EXPLOSION, 	 10, createExplosion),
			Buffer(Pool.BANG,      	 12, createBang),
			Buffer(Pool.PARTICLE,  	100, createParticle)
		});
		//  setPool(256, Pool.Count, {
		//  	Buffer() { pool = Pool.BULLET,      size = 20,  factory = createBullet },
		//  	Buffer() { pool = Pool.ENEMY1,      size = 15,  factory = createEnemy1 },
		//  	Buffer() { pool = Pool.ENEMY2,      size = 5,   factory = createEnemy2 },
		//  	Buffer() { pool = Pool.ENEMY3,      size = 4,   factory = createEnemy3 },
		//  	Buffer() { pool = Pool.EXPLOSION,   size = 10,  factory = createExplosion },
		//  	Buffer() { pool = Pool.BANG,        size = 12,  factory = createBang },
		//  	Buffer() { pool = Pool.PARTICLE,    size = 100, factory = createParticle }
		//  });
	}

	/**
	 * The stuff that all entities have
	 */
	public Entity* createBase(string name, string path, int pool, double scale = 1.0, bool active = false) {
		if (sdx.graphics.Sprite.cache.length == 0)
			sdx.graphics.Sprite.initialize(Pool.Count);
	
		var sprite = new sdx.graphics.Sprite(path);
		return createEntity(name, pool, active)
			.addPosition(0, 0)
			.addLayer(pool)
			.addBounds(0, 0, sprite.width, sprite.height)
            .addScale(scale, scale)
			.addSprite(sprite, sprite.width, sprite.height);
	}
	/** 
	 *	factory methods:
	 */
	public Entity* createBackground() {
		return entityAdded(createBase("background", "assets/images/background.png", Pool.BACKGROUND, 2.0, true)
			.setBackground(true));
	}

	public Entity* createPlayer() {
		return entityAdded(createBase("player", "assets/images/spaceshipspr.png", Pool.PLAYER, 1.0, true));
	}

	public Entity* createBullet() {
		return (createBase("bullet", "assets/images/bullet.png", Pool.BULLET)
			// .addSound(new audio.Sound(Sdx.files.resource("sounds/pew.wav")))
			.addTint(0xd2, 0xfa, 0, 0xfa)
			.addHealth(2, 2)
			.addVelocity(0, -800)
			.setBullet(true));
	}

	public Entity* createEnemy1() {
		return createBase("enemy1", "assets/images/enemy1.png", Pool.ENEMY1)
			.addHealth(10, 10)
			.addVelocity(0, 40)
			.addText("100%", new sdx.graphics.Sprite("100%", sdx.smallFont, sdx.Color.LimeGreen))
			.setEnemy1(true);
	}

	public Entity* createEnemy2() {
		return createBase("enemy2", "assets/images/enemy2.png", Pool.ENEMY2)
			.addHealth(20, 20)
			.addVelocity(0, 30)
			.addText("100%", new sdx.graphics.Sprite("100%", sdx.smallFont, sdx.Color.LimeGreen))
			.setEnemy2(true);
	}

	public Entity* createEnemy3() {
		return createBase("enemy3", "assets/images/enemy3.png", Pool.ENEMY3)
			.addHealth(60, 60)
			.addVelocity(0, 20)
			.addText("100%", new sdx.graphics.Sprite("100%", sdx.smallFont, sdx.Color.LimeGreen))
			.setEnemy3(true);
	}

	public Entity* createExplosion() {
		return createBase("explosion", "assets/images/explosion.png", Pool.EXPLOSION, 0.6)
			// .addSound(new audio.Sound(Sdx.files.resource("sounds/asplode.wav")))
			.addTint(0xd2, 0xfa, 0xd2, 0x7f)
			.addExpires(0.2)
			.addTween(0.006, 0.6, -3, false, true);
	}

	public Entity* createBang() {
		return createBase("bang", "assets/images/explosion.png", Pool.BANG, 0.3)
			// .addSound(new audio.Sound(Sdx.files.resource("sounds/smallasplode.wav")))
			.addTint(0xd2, 0xfa, 0xd2, 0x9f)
			.addExpires(0.2)
			.addTween(0.003, 0.3, -3, false, true);
	}

	public Entity* createParticle() {
		return createBase("particle", "assets/images/star.png", Pool.PARTICLE)
			.addTint(0xd2, 0xfa, 0xd2, 0xfa)
			.addExpires(0.75)
			.addVelocity(0, 0);
	}

	/**
	 * Get entity from the pool
	 */
	public Entity* bullet(int x, int y) {
		if (cache[Pool.BULLET].isEmpty()) {
			stdout.printf("out of bullets\n");
			return null;
		}
		return entityAdded(cache[Pool.BULLET].deque()
			.setPosition(x, y)
			.setActive(true));
	}

	public Entity* enemy1(int x, int y) {
		if (cache[Pool.ENEMY1].isEmpty()) {
			stdout.printf("out of enemy1\n");
			return null;
		}
		return entityAdded(cache[Pool.ENEMY1].deque()
			.setPosition(x, y)
			.setHealth(10, 10)
			.setActive(true));
	}

	public Entity* enemy2(int x, int y) {
		if (cache[Pool.ENEMY2].isEmpty()) {
			stdout.printf("out of enemy2\n");
			return null;
		}
		return entityAdded(cache[Pool.ENEMY2].deque()
			.setPosition(x, y)
			.setHealth(20, 20) 
			.setActive(true));
	}

	public Entity* enemy3(int x, int y) {
		if (cache[Pool.ENEMY3].isEmpty()) {
			stdout.printf("out of enemy3\n");
			return null;
		}
		return entityAdded(cache[Pool.ENEMY3].deque()
			.setPosition(x, y)
			.setHealth(60, 60)
			.setActive(true));
	}

	public Entity* explosion(int x, int y) {
		if (cache[Pool.EXPLOSION].isEmpty()) {
			stdout.printf("out of explosions\n");
			return null;
		}
		var entity = cache[Pool.EXPLOSION].deque();
		entityAdded(entity
			.setBounds(x, y, (int)entity.bounds.w, (int)entity.bounds.h)
			.setTween(0.006, 0.6, -3, false, true)
			.setPosition(x, y)
			.setScale(0.6, 0.6)
			.setExpires(0.2)
			.setActive(true));
		return entity;
	}

	public Entity* bang(int x, int y) {
		if (cache[Pool.BANG].isEmpty()) {
			stdout.printf("out of bang\n");
			return null;
		}
		var entity = cache[Pool.BANG].deque();
		entityAdded(entity
			.setBounds(x, y, (int)entity.bounds.w, (int)entity.bounds.h)
			.setTween(0.003, 0.3, -3, false, true)
			.setPosition(x, y)
			.setScale(0.3, 0.3)
			.setExpires(0.2)
			.setActive(true));
		return entity;
	}

	public Entity* particle(int x, int y) {
		if (cache[Pool.PARTICLE].isEmpty()) {
			stdout.printf("out of particles\n");
			return null;
		}
		var radians = sdx.getRandom() * TAU;
		var magnitude = sdx.getRandom() * 200;
		var velocityX = magnitude * Math.cos(radians);
		var velocityY = magnitude * Math.sin(radians);
		var scale = sdx.getRandom();

		var entity = cache[Pool.PARTICLE].deque();
		entityAdded(entity
			.setBounds(x, y, (int)entity.bounds.w, (int)entity.bounds.h)
			.setPosition(x, y)
			.setScale(scale, scale)
			.setVelocity(velocityX, velocityY)
			.setExpires(0.75)
			.setActive(true));
		return entity;
	}

}
