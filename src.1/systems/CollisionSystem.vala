using entitas;
namespace systems {
	/**
	* game systems
	*/
	public class CollisionSystem : Object {
		public ISystem _ISystem { get { return { initialize, execute }; } }

		public Game game;
		public Factory world;
		public Group bullets;
		public Group enemies;

		public CollisionSystem(Game game, Factory world) {
			this.game = game;
			this.world = world;
		}

		public void initialize() {
			bullets = world.getGroup(Matcher.AllOf({ Components.BulletComponent }));
			enemies = world.getGroup(Matcher.AnyOf({
				Components.Enemy1Component, 
				Components.Enemy2Component, 
				Components.Enemy3Component
			}));
		}

		/**
		* physics system
		* model movement
		*/
		public void execute(double delta) {
			foreach (var enemy in enemies.entities) {
				if (enemy.isActive()) {
					foreach (var bullet in bullets.entities) {
						if (bullet.isActive()) {
							if (bullet.bounds.is_intersecting(enemy.bounds)) {
								var x = (int)((double)bullet.position.x);
								var y = (int)((double)bullet.position.y);
								world.bang(x, y);
								world.deleteEntity(bullet);
								for (var i=0; i<3; i++) 
									world.particle(x, y);
								if (enemy.health != null) {
									var current = enemy.health.current - 2;
									if (current < 0) {
										world.explosion(x, y);
										world.deleteEntity(enemy);
									} else {
										enemy.health.current = current;
									}
								} 
								return;
							}
						}
					}
				}
			}
		}
	}
}
		
