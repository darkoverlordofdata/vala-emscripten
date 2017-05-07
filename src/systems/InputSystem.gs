uses SDL
uses Emscripten
uses entitas
namespace systems


	/**
	* game systems
	*/
	
	class InputSystem : Object

		game		: Game
		world		: Factory
		player		: Entity*
		FireRate	: double = 0.1
		timeToFire  : double = 0.0
		shoot	   	: bool

		construct(game:Game, world:Factory)
			this.game = game
			this.world = world

		def initialize()
			player = world.createPlayer()


		/**
		 * get player input
		 */
		def execute(delta:double)
			var x = (int)sdx.mouseX
			var y = (int)sdx.mouseY
			player.setPosition(x, y)
			player.bounds.x = x
			player.bounds.y = y
			shoot = sdx.mouseDown || (sdx.keys[122] == 1)
			if shoot do timeToFire -= delta
			if timeToFire < 0.0
				world.bullet(x + 27, y + 2)
				world.bullet(x - 27, y + 2)
				timeToFire = FireRate


