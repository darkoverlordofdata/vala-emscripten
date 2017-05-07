uses SDL
uses Emscripten
uses entitas
namespace systems


	/**
	* game systems
	*/
	
	class RemoveSystem : Object

		game		: Game
		world		: Factory
		movable		: Group	

		construct(game:Game, world:Factory)
			this.game = game
			this.world = world

		def initialize()
			movable = world.getGroup(Matcher.AllOf({Components.PositionComponent}))
		/**
		 * Remove entities that have gone off-screen
		 */
		def execute(delta:double)
			for entity in movable.entities do if entity.isActive() 
				case entity.pool
					when Pool.ENEMY1
						if entity.position.y > game.height do world.deleteEntity(entity)
						
					when Pool.ENEMY2
						if entity.position.y > game.height do world.deleteEntity(entity)
						
					when Pool.ENEMY3
						if entity.position.y > game.height do world.deleteEntity(entity)
						
					when Pool.BULLET
						if entity.position.y < 0 do world.deleteEntity(entity)


