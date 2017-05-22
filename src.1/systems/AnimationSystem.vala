using entitas;
namespace systems {
	/**
	* game systems
	*/
	
	public class AnimationSystem : Object {
		public ISystem _ISystem { get { return { initialize, execute }; } }

		public Game game;
		public Factory world;
		public Group tweens;

		public AnimationSystem(Game game, Factory world) {
			this.game = game;
			this.world = world;
		}

		public void initialize(){
			tweens = world.getGroup(Matcher.AllOf({Components.TweenComponent}));
		}


		/**
		* physics system
		* model movement
		*/
		public void execute(double delta) {

			foreach (var entity in tweens.entities) {
				if (entity.isActive()) {
					var x = entity.scale.x + (entity.tween.speed * delta);
					var y = entity.scale.y + (entity.tween.speed * delta);
					var active = entity.tween.active;

					if (x > entity.tween.max) {
						x = entity.tween.max;
						y = entity.tween.max;
						active = false;
					} else if (x < entity.tween.min) {
						x = entity.tween.min;
						y = entity.tween.min;
						active = false;
					}
					
					entity.scale.x = x; 
					entity.scale.y = y;
					entity.tween.active = active;
				}
			}
		}
	}
} 




