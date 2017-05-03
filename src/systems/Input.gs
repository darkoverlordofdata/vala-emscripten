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
		FireRate	: double = 0.1
		timeToFire  : double = 0.0
		shoot	   	: bool

		construct(game:Game, factory:Factory)
			this.game = game
			this.factory = factory

		def initialize()
			pass


		/**
		 * get player input
		 */
		def execute(delta:double)
			var x = (int)game.mouseX
			var y = (int)game.mouseY
			var x1 = x-game.player.bounds.w/2
			var y1 = y-game.player.bounds.h/2
			game.player.setPosition(x1, y1)
			game.player.bounds.x = x1
			game.player.bounds.y = y1
			shoot = game.mouseDown || (game.keys[122] == 1)
			if shoot do timeToFire -= delta
			if timeToFire < 0.0
				factory.newBullet(x - 27, y + 2)
				factory.newBullet(x + 27, y + 2)
				timeToFire = FireRate


