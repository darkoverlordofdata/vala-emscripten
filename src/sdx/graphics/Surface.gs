namespace sdx.graphics



	/**
	 * a reference counted wrapper for surface
	 * prevents the surface memory from being reclaimed 
	 * 
	 */
	
	class Surface : Object
		uniqueId : static int = 0
		surface : SDL.Video.Surface
		width : int
		height : int
		id : int = ++uniqueId
		path: string

		construct(path: string)

			this.path = path
			surface = SDLImage.load_png(new SDL.RWops.from_file(path, "r"))	
			//surface = SDLImage.load(path)
			width = surface.w
			height = surface.h

