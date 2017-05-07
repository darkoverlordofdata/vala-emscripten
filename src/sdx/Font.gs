namespace sdx

	/**
	 * a reference counted wrapper for surface
	 * prevents the surface memory from being reclaimed 
	 * 
	 */
	
	class Font : Object
		uniqueId : static int = 0
		id : int = ++uniqueId
		path: string
		size: int
		innerFont: SDLTTF.Font


		construct(path: string, size: int)

			innerFont = new SDLTTF.Font(path, size)
			this.path = path
			this.size = size

		/**
		 *  Render text for Sprite.fromRenderedText
		 *
		 * @param text to generate surface from
		 * @param color foreground color of text
		 * @return new Surface
		 */
		def render(text : string, color : SDL.Video.Color) : SDL.Video.Surface
			return innerFont.render(text, color)

