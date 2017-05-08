uses entitas
namespace systems


	/**
	* game systems
	*/
	
	class PhysicsSystem : Object

		game		: Game
		world		: Factory
		physics		: Group

		construct(game:Game, world:Factory)
			this.game = game
			this.world = world

		def initialize()
			physics = world.getGroup(Matcher.AllOf({Components.VelocityComponent}))


		/**
		* physics system
		* model movement
		*/
		def execute(delta:double)

			for entity in physics.entities do if entity.isActive() 

				var x = entity.position.x + entity.velocity.x * delta
				var y = entity.position.y + entity.velocity.y * delta

				entity.setPosition(x, y)
				entity.bounds.x = (int)x
				entity.bounds.y = (int)y



