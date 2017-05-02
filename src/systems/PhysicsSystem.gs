uses SDL
uses Emscripten
uses entitas


/**
 * game systems
 */
[Compact]
class PhysicsSystem

	game		: Game
	factory		: Factory
	physics		: Group

	construct(game:Game, factory:Factory)
		this.game = game
		this.factory = factory

	def initialize()
		physics 	= factory.getGroup(Matcher.AllOf({Components.VelocityComponent}))


	/**
	 * physics system
	 * model movement
	 */
	def execute(entity:Entity*, delta:double)
		if entity.isActive() 

			var x = entity.position.x + entity.velocity.x * delta
			var y = entity.position.y + entity.velocity.y * delta

			entity.setPosition(x, y)
			entity.bounds.x = (int)x
			entity.bounds.y = (int)y

