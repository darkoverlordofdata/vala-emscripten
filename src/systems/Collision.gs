uses SDL
uses Emscripten
uses entitas
namespace systems


	/**
	* game systems
	*/
	[Pseudo]
	class Collision

		game		: Game
		factory		: Factory

		construct(game:Game, factory:Factory)
			this.game = game
			this.factory = factory

		def initialize()
			pass


		/**
		* physics system
		* model movement
		*/
		def execute(delta:double)
			pass

