uses SDL
uses Emscripten
uses entitas
namespace systems


	/**
	* game systems
	*/
	[Pseudo]
	class Collision

		game		: Game
		factory		: Factory
		bullets		: Group
		enemies		: Group

		construct(game:Game, factory:Factory)
			this.game = game
			this.factory = factory

		def initialize()
			bullets = factory.getGroup(Matcher.AllOf({ Components.BulletComponent }))
			enemies = factory.getGroup(Matcher.AnyOf({
				Components.Enemy1Component, 
				Components.Enemy2Component, 
				Components.Enemy3Component
			}))


		/**
		* physics system
		* model movement
		*/
		def execute(delta:double)
			for var enemy in enemies.entities do if enemy.isActive()
				for var bullet in bullets.entities do if bullet.isActive()
					if intersects(ref enemy, ref bullet)
						handleCollision(ref enemy, ref bullet)
						return


		def intersects(ref a:Entity*, ref b:Entity*):bool 
			return ((a.bounds.x < b.bounds.x + b.bounds.w) && 
					(a.bounds.x + a.bounds.w > b.bounds.x) && 
					(a.bounds.y < b.bounds.y + b.bounds.h) && 
					(a.bounds.y + a.bounds.h > b.bounds.y)) 
		

		def handleCollision(ref a:Entity*, ref b:Entity*)
			var x = (int)((double)a.position.x)
			var y = (int)((double)a.position.y)
			factory.newBang(x, y)
			factory.deleteEntity(b)
			for var i=0 to 3 do factory.newParticle(x, y)
			if a.health != null
				var current = a.health.current - 2
				if current < 0
					factory.newExplosion(x, y)
					factory.deleteEntity(a)
				else 
					a.health.current = current


