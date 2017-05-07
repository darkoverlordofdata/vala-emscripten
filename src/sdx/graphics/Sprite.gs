namespace sdx.graphics


	struct Scale
		x : double
		y : double

	/**
	 * a reference counted wrapper for sprite
	 * prevents the texture memory from being reclaimed 
	 */
	
	class Sprite : Object
		cache 		: static array of sdx.graphics.Surface
		uniqueId 	: static int = 0
		texture 	: SDL.Video.Texture
		surface 	: SDL.Video.Surface
		width 		: int
		height 		: int
		x 			: int
		y	 		: int
		scale 		: Scale = Scale() { x = 1.0, y = 1.0 }
		color 		: SDL.Video.Color = sdx.Color.WHITE
		centered 	: bool = true
		layer 		: int = 0
		id 			: int = ++uniqueId
		path		: string
		isText		: bool

		construct(path: string, font : sdx.Font? = null, color : SDL.Video.Color? = null)

			if font == null
				isText = false
				var i = indexOfPath(path)
				if i<0 
					print "Ran out of surface cache"
				else
				texture = SDL.Video.Texture.create_from_surface(renderer, cache[i].surface)
				if texture == null
					print "Unable to load image texture %s", path
				texture.set_blend_mode(SDL.Video.BlendMode.BLEND)
				width = cache[i].width
				height = cache[i].height
				this.path = path
			else
				isText = true
				var surface = font.render(path, color)
				if surface == null
					print "Unable to load font surface %s", font.path
				else
					texture = SDL.Video.Texture.create_from_surface(renderer, surface)
					if texture == null
						print "Unable to load image text %s", path
					else
						texture.set_blend_mode(SDL.Video.BlendMode.BLEND)
						width = surface.w
						height = surface.h
						this.path = path
				


		def static initialize(length:int)
			if cache.length == 0
				cache = new array of sdx.graphics.Surface[length]

		def indexOfPath(path:string):int
			// if cache.length == 0 do cache = new array of sdx.graphics.Surface[Pool.Count]
			for var i=0 to (cache.length-1)
				if cache[i] == null do cache[i] = new sdx.graphics.Surface(path)
				if cache[i].path == path do return i
			return -1

		/**
		 *  Create sprite from text value of a Sprite.fromRenderedText
		 *
		 * @param text string of text to generate
		 * @param font used to generate text
		 * @param color foregound text color (background transparent)
		 */
		// construct text(text : string, font : Font, color : sdx.graphics.Color)
		// 	var surface = font.render(text, color)

		// 	texture = Video.Texture.create_from_surface(Sdx.app.renderer, surface)
		// 	sdlFailIf(texture == null, "Unable to load image texture!")

		// 	texture.set_blend_mode(Video.BlendMode.BLEND)
		// 	width = surface.w
		// 	height = surface.h
		// 	path = ""


		/**
		 *  Change the text value of a Sprite.fromRenderedText
		 *
		 * @param text string of text to generate
		 * @param font used to generate text
		 * @param color foregound text color (background transparent)
		 */
		def setText(text : string, font : sdx.Font, color : SDL.Video.Color)
			var surface = font.render(text, color)
			if surface == null
				print "Unable to set font surface %s", font.path
			else
				texture = SDL.Video.Texture.create_from_surface(sdx.renderer, surface)
				if texture == null
					print "Unable to set image text %s", text
				else

					texture.set_blend_mode(SDL.Video.BlendMode.BLEND)
					width = surface.w
					height = surface.h
					path = text

		/**
		 *  Render the sprite on the Video.Renderer context
		 *
		 * @param renderer video context
		 * @param x display coordinate
		 * @param y display coordinate
		 * @param clip optional clipping rectangle
		 */
		def render(renderer: SDL.Video.Renderer, x : int, y : int, clip : SDL.Video.Rect? = null)
			/* do clipping? */
			var w = (int)((clip == null ? width : clip.w) * scale.x)
			var h = (int)((clip == null ? height : clip.h) * scale.y)

			/* center in display? */
			x = centered ? x-(w/2) : x
			y = centered ? y-(h/2) : y

			/* apply current tint */
			texture.set_color_mod(color.r, color.g, color.b)
			/* copy to the rendering context */
			renderer.copy(texture, null, {x, y, w, h})


