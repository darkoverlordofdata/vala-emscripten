namespace sdx.graphics {

	public struct Scale {
		double x;
		double y;
	}
	
	public class Sprite : Object {
		public static sdx.graphics.Surface[] cache;
		public static int uniqueId = 0;
		public SDL.Video.Texture texture;
		public SDL.Video.Surface surface;
		public int width;
		public int height;
		public int x;
		public int y;
		public Scale scale = Scale() { x = 1.0, y = 1.0 };
		public SDL.Video.Color color = sdx.Color.WHITE;
		public bool centered = true;
		public int layer = 0;
		public int id = ++uniqueId;
		public string path;
		public bool isText;

		public Sprite(string path, sdx.Font? font = null, SDL.Video.Color? color = null) {

			if (font == null) {
				isText = false;
				var i = indexOfPath(path);
				if (i<0) { 
					stdout.printf("Ran out of surface cache\n");
				} else {
					texture = SDL.Video.Texture.create_from_surface(renderer, cache[i].surface);
					if (texture == null)
						stdout.printf("Unable to load image texture %s\n", path);
					texture.set_blend_mode(SDL.Video.BlendMode.BLEND);
					width = cache[i].width;
					height = cache[i].height;
					this.path = path;
				}
			} else {
				isText = true;
				var surface = font.render(path, color);
				if (surface == null) {
					stdout.printf("Unable to load font surface %s\n", font.path);
				} else {
					texture = SDL.Video.Texture.create_from_surface(renderer, surface);
					if (texture == null) {
						 stdout.printf("Unable to load image text %s\n", path);
					} else {
						texture.set_blend_mode(SDL.Video.BlendMode.BLEND);
						width = surface.w;
						height = surface.h;
						this.path = path;
					}
				}
			}
		}

		public static void initialize(int length) {
			if (cache.length == 0)
				cache = new sdx.graphics.Surface[length];
		}

		public int indexOfPath(string path) {
			// if cache.length == 0 do cache = new array of sdx.graphics.Surface[Pool.Count]
			for (var i=0; i<cache.length; i++) {
				if (cache[i] == null) cache[i] = new sdx.graphics.Surface(path);
				if (cache[i].path == path) return i;
			}
			return -1;
		}

		/**
		 *  Change the text value of a Sprite.fromRenderedText
		 *
		 * @param text string of text to generate
		 * @param font used to generate text
		 * @param color foregound text color (background transparent)
		 */
		public void setText(string text, sdx.Font font, SDL.Video.Color color) {
			var surface = font.render(text, color);
			if (surface == null) {
				stdout.printf("Unable to set font surface %s\n", font.path);
			} else {
				texture = SDL.Video.Texture.create_from_surface(sdx.renderer, surface);
				if (texture == null) {
					stdout.printf("Unable to set image text %s\n", text);
				} else {
					texture.set_blend_mode(SDL.Video.BlendMode.BLEND);
					width = surface.w;
					height = surface.h;
					path = text;
				}
			}
		}

		/**
		 *  Render the sprite on the Video.Renderer context
		 *
		 * @param renderer video context
		 * @param x display coordinate
		 * @param y display coordinate
		 * @param clip optional clipping rectangle
		 */
		public void render(SDL.Video.Renderer renderer, int x, int y, SDL.Video.Rect? clip = null) {
			/* do clipping? */
			var w = (int)((clip == null ? width : clip.w) * scale.x);
			var h = (int)((clip == null ? height : clip.h) * scale.y);

			/* center in display? */
			x = centered ? x-(w/2) : x;
			y = centered ? y-(h/2) : y;

			/* apply current tint */
			texture.set_color_mod(color.r, color.g, color.b);
			/* copy to the rendering context */
			renderer.copy(texture, null, {x, y, w, h});
		}
	}
}

