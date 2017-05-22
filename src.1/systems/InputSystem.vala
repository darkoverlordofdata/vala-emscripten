using entitas;
namespace systems {

	/**
	* game systems
	*/
	public class InputSystem : Object {
		public ISystem _ISystem { get { return { initialize, execute }; } }

		const double FIRE_RATE = 0.1;

		public Game game;
		public Factory world;
		public Entity* player;
		public double timeToFire = 0.0;
		public bool shoot;

		public InputSystem(Game game, Factory world) {
			this.game = game;
			this.world = world;
		}

		public void initialize() {
			player = world.createPlayer();
		}

		/**
		 * get player input
		 */
		public void execute(double delta) {
			var x = (int)sdx.mouseX;
			var y = (int)sdx.mouseY;
			player.setPosition(x, y);
			player.bounds.x = x;
			player.bounds.y = y;
			shoot = sdx.mouseDown || (sdx.keys[122] == 1);
			if (shoot) timeToFire -= delta;
			if (timeToFire < 0.0) {
				world.bullet(x + 27, y + 2);
				world.bullet(x - 27, y + 2);
				timeToFire = FIRE_RATE;
			}
		}
	}
}


