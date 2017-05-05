uses SDL
uses Emscripten
uses entitas
namespace systems


	/**
	* game systems
	*/
	[Pseudo]
	class Animation

		game		: Game
		factory		: Factory
		tweens		: Group

		construct(game:Game, factory:Factory)
			this.game = game
			this.factory = factory

		def initialize()
			tweens = factory.getGroup(Matcher.AllOf({Components.TweenComponent}))


		/**
		* physics system
		* model movement
		*/
		def execute(delta:double)

			for entity in tweens.entities do if entity.isActive() 
				var x = entity.scale.x + (entity.tween.speed * delta)
				var y = entity.scale.y + (entity.tween.speed * delta)
				var active = entity.tween.active

				if x > entity.tween.max 
					x = entity.tween.max
					y = entity.tween.max
					active = false
				else if x < entity.tween.min
					x = entity.tween.min
					y = entity.tween.min
					active = false
				
				entity.scale.x = x 
				entity.scale.y = y 
				entity.tween.active = active 




