uses SDL
uses Emscripten
uses entitas
namespace systems


	/**
	* game systems
	*/
	
	class ExpireSystem : Object

		game		: Game
		world		: Factory
		expiring	: Group

		construct(game:Game, world:Factory)
			this.game = game
			this.world = world

		def initialize()
			expiring = world.getGroup(Matcher.AllOf({Components.ExpiresComponent}))


		/**
		 * Remove exired entities
		 */
		def execute(delta:double)
			for entity in expiring.entities do if entity.isActive() 
				var exp = entity.expires.value - delta
				entity.expires.value = exp
				if entity.expires.value < 0 do world.deleteEntity(entity)


