using entitas;
namespace systems {
	/**
	* game systems
	*/
	public class ExpireSystem : Object {
		public ISystem _ISystem { get { return { initialize, execute }; } }

		public Game game;
		public Factory world;
		public Group expiring;

		public ExpireSystem(Game game, Factory world) {
			this.game = game;
			this.world = world;
		}

		public void initialize() {
			expiring = world.getGroup(Matcher.AllOf({Components.ExpiresComponent}));
		}

		/**
		 * Remove exired entities
		 */
		public void execute(double delta) {
			foreach (var entity in expiring.entities) {
				if (entity.isActive()) {
					var exp = entity.expires.value - delta;
					entity.expires.value = exp;
					if (entity.expires.value < 0)	
						world.deleteEntity(entity);
				}
			}
		}
	}
}


