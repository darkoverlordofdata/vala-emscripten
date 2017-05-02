uses SDL
uses Emscripten
uses entitas
namespace systems


	/**
	* game systems
	*/
	[Pseudo]
	class Expire

		game		: Game
		factory		: Factory
		expiring	: Group

		construct(game:Game, factory:Factory)
			this.game = game
			this.factory = factory

		def initialize()
			expiring = factory.getGroup(Matcher.AllOf({Components.ExpiresComponent}))


		/**
		* physics system
		* model movement
		*/
		def execute(delta:double)
			for entity in expiring.entities
				if entity.isActive() 
					var exp = entity.expires.value - delta
					entity.expires.value = exp
					if entity.expires.value < 0 do factory.deleteEntity(entity)


