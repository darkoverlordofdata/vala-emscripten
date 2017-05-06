uses SDL
uses Emscripten
uses entitas

/**
* add to sprites 
*/
def entityAdded(e:Entity*):Entity*
	if !e.hasSprite() do return e
	systems.Display.instance.add(e)
	return e

/**
* remove from sprites
*/
def entityRemoved(e:Entity*):Entity*
	systems.Display.instance.remove(e)
	return e

namespace systems


	/**
	* game systems
	*/
	[Pseudo]
	class Display

		instance	: static Display
		game		: Game
		factory		: Factory
		sprites		: List of Entity* = new List of Entity*

		construct(game:Game, factory:Factory)
			instance = this
			this.game = game
			this.factory = factory

		def initialize()
			pass

		def execute(delta:double)
			pass

		def remove(e:Entity*)
			sprites.remove(e)
		
		def add(e:Entity*)
			var layer = e.layer.value
			if sprites.length() == 0
				sprites.append(e)

			else
				var i = 0
				for s in sprites
					assert(s != null)
					if layer <= s.layer.value
						sprites.insert(e, i)
						return
					else
						i++
				sprites.append(e)

		def draw(e:Entity*):bool
			if e.hasSprite()

				e.bounds.w = (int)((double)e.sprite.width * e.scale.x)
				e.bounds.h = (int)((double)e.sprite.height * e.scale.y)
				if !e.isBackground()
					e.bounds.x = (int)((double)e.position.x - e.bounds.w / 2)
					e.bounds.y = (int)((double)e.position.y - e.bounds.h / 2)
					if e.hasTint()
						e.sprite.sprite.texture.set_color_mod((uint8)e.tint.r, (uint8)e.tint.g, (uint8)e.tint.b)
						e.sprite.sprite.texture.set_alpha_mod((uint8)e.tint.a)
				
				sdx.renderer.copy(e.sprite.sprite.texture, null, 
					{ e.bounds.x, e.bounds.y, (uint)e.bounds.w, (uint)e.bounds.h })

			if e.hasText()
				sdx.renderer.copy(e.text.sprite.texture, null, 
					{ (int)e.position.x, (int)e.position.y, e.text.sprite.width, e.text.sprite.height })

			return true

