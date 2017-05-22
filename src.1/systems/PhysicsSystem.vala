using entitas;
namespace systems {

	/**
	* game systems
	*/
	public class PhysicsSystem : Object {
		public ISystem _ISystem { get { return { initialize, execute }; } }

		public Game game;
		public Factory world;
		public Group physics;

		public PhysicsSystem(Game game, Factory world) {
			this.game = game;
			this.world = world;
		}

		public void initialize() {
			physics = world.getGroup(Matcher.AllOf({Components.VelocityComponent}));
		}

		/**
		* physics system
		* model movement
		*/
		public void execute(double delta) {

			foreach (var entity in physics.entities)  {
				if (entity.isActive()) {

					var x = entity.position.x + entity.velocity.x * delta;
					var y = entity.position.y + entity.velocity.y * delta;

					entity.setPosition(x, y);
					entity.bounds.x = (int)x;
					entity.bounds.y = (int)y;
				}
			}
		}
	}
}



