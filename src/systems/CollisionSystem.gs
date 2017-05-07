uses SDL
uses Emscripten
uses entitas
namespace systems


	/**
	* game systems
	*/
	
	class CollisionSystem : Object

		game		: Game
		world		: Factory
		bullets		: Group
		enemies		: Group

		construct(game:Game, world:Factory)
			this.game = game
			this.world = world

		def initialize()
			bullets = world.getGroup(Matcher.AllOf({ Components.BulletComponent }))
			enemies = world.getGroup(Matcher.AnyOf({
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
					if bullet.bounds.is_intersecting(enemy.bounds)
						var x = (int)((double)bullet.position.x)
						var y = (int)((double)bullet.position.y)
						world.bang(x, y)
						world.deleteEntity(bullet)
						for var i=0 to 3 do world.particle(x, y)
						if enemy.health != null
							var current = enemy.health.current - 2
							if current < 0
								world.explosion(x, y)
								world.deleteEntity(enemy)
							else 
								enemy.health.current = current
						return
