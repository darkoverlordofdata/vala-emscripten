uses SDL
uses Emscripten
uses entitas
namespace systems


	/**
	* game systems
	*/
	
	class ScoreSystem : Object

		game		: Game
		world		: Factory
		group	    : Group
		

		construct(game:Game, world:Factory)
			this.game = game
			this.world = world

		def initialize()
			group = world.getGroup(Matcher.AllOf({
				Components.HealthComponent, 
				Components.TextComponent
			}))
			

		def execute(delta:double)
			for var entity in group.entities do if entity.isActive()
				var pct = "%d%%".printf((int)Math.fmin(100, (double)entity.health.current/(double)entity.health.maximum*100.0))

				if pct != entity.text.text
					entity.text.text = pct
					entity.text.sprite.setText(pct, sdx.smallFont, sdx.Color.LimeGreen)
					entity.text.sprite.x = (int)entity.position.x
					entity.text.sprite.y = (int)entity.position.y

