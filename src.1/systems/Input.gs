uses SDL
uses Emscripten
uses entitas
namespace systems


	/**
	* game systems
	*/
	[Pseudo]
	class Input

		game		: Game
		factory		: Factory
		player		: Entity*
		FireRate	: double = 0.1
		timeToFire  : double = 0.0
		shoot	   	: bool

		construct(game:Game, factory:Factory)
			this.game = game
			this.factory = factory

		def initialize()
			player = factory.createPlayer()


		/**
		 * get player input
		 */
		def execute(delta:double)
			var x = (int)game.mouseX
			var y = (int)game.mouseY
			player.setPosition(x, y)
			player.bounds.x = x
			player.bounds.y = y
			shoot = game.mouseDown || (game.keys[122] == 1)
			if shoot do timeToFire -= delta
			if timeToFire < 0.0
				var e1 = factory.newBullet(x + 27, y + 2)
				var e2 = factory.newBullet(x - 27, y + 2)
				timeToFire = FireRate


