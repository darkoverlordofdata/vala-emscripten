uses SDL
uses Emscripten
uses entitas
uses systems

/**
 * game systems
 */
[Pseudo]
class Systems

	collision	: Collision
	expire		: Expire
	input		: Input
	physics		: Physics
	remove		: Remove
	spawn		: Spawn

	def initialize(game:Game, factory:Factory)
	
		spawn = new Spawn(game, factory)
		input = new Input(game, factory)
		collision = new Collision(game, factory)
		physics = new Physics(game, factory)
		expire = new Expire(game, factory)
		remove = new Remove(game, factory)

		spawn.initialize()
		input.initialize() 
		collision.initialize()
		physics.initialize()
		expire.initialize()
		remove.initialize()


	/**
	 *	update each game frame
	 */
	def update(delta:double)
		spawn.execute(delta)
		input.execute(delta) 
		collision.execute(delta)
		physics.execute(delta)
		expire.execute(delta)
		remove.execute(delta)


