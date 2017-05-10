using entitas;

/**
* add to sprites 
*/
public Entity* entityAdded(Entity* e) {
	if (!e.hasSprite()) return e;
	systems.DisplaySystem.instance.add(e);
	return e;
}

/**
* remove from sprites
*/
public Entity* entityRemoved(Entity* e) {
	systems.DisplaySystem.instance.remove(e);
	return e;
}
namespace systems {
	/**
	* game systems
	*/
	public class DisplaySystem : Object {
		public ISystem _ISystem { get { return { initialize, execute }; } }

		public static DisplaySystem instance; 
		public Game game;
		public Factory world;
		public List<Entity*> sprites = new List<Entity*>();

		public DisplaySystem(Game game, Factory world) {
			instance = this;
			this.game = game;
			this.world = world;
		}

		public void initialize(){}
		public void execute(double delta){}

		public void remove(Entity* e) {
			sprites.remove(e);
		}
		
		public void add(Entity* e) {
			var layer = e.layer.value;
			if (sprites.length() == 0) {
				sprites.append(e);
			} else {
				var i = 0;
				foreach (var s in sprites) {
					assert(s != null);
					if (layer <= s.layer.value) {
						sprites.insert(e, i);
						return;
					} else {
						i++;
					}
				}
				sprites.append(e);
			}
		}

		public bool draw(Entity* e) {
			if (e.hasSprite()) {

				e.bounds.w = (int)((double)e.sprite.width * e.scale.x);
				e.bounds.h = (int)((double)e.sprite.height * e.scale.y);
				if (!e.isBackground()) {
					e.bounds.x = (int)((double)e.position.x - e.bounds.w / 2);
					e.bounds.y = (int)((double)e.position.y - e.bounds.h / 2);
					if (e.hasTint()) {
						e.sprite.sprite.texture.set_color_mod((uint8)e.tint.r, (uint8)e.tint.g, (uint8)e.tint.b);
						e.sprite.sprite.texture.set_alpha_mod((uint8)e.tint.a);
					}
				}
				sdx.renderer.copy(e.sprite.sprite.texture, null, 
					{ e.bounds.x, e.bounds.y, (uint)e.bounds.w, (uint)e.bounds.h });

			if (e.hasText())
				sdx.renderer.copy(e.text.sprite.texture, null, 
					{ (int)e.position.x, (int)e.position.y, e.text.sprite.width, e.text.sprite.height });
			}
			return true;
		}
	}
}