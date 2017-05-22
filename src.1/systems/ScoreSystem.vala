using entitas;
namespace systems {

	/**
	* game systems
	*/
	public class ScoreSystem : Object {
		public ISystem _ISystem { get { return { initialize, execute }; } }

		public Game game;
		public Factory world;
		public Group group;	

		public ScoreSystem(Game game, Factory world) {
			this.game = game;
			this.world = world;
		}

		public void initialize() {
			group = world.getGroup(Matcher.AllOf({
				Components.HealthComponent, 
				Components.TextComponent
			}));
		}
			

		public void execute(double delta) {
			foreach (var entity in group.entities) {
				if (entity.isActive()) {
					var pct = "%d%%".printf((int)Math.fmin(100, (double)entity.health.current/(double)entity.health.maximum*100.0));
					if (pct != entity.text.text) {
						entity.text.text = pct;
						entity.text.sprite.setText(pct, sdx.smallFont, sdx.Color.LimeGreen);
						entity.text.sprite.x = (int)entity.position.x;
						entity.text.sprite.y = (int)entity.position.y;
					}
				}
			}
		}
	}
}

