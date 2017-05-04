uses SDL
uses Emscripten
uses entitas
namespace systems


	/**
	* game systems
	*/
	[Compact, CCode ( /** reference counting */
		ref_function = "systems_remove_addRef", 
		unref_function = "systems_remove_release"
	)]
	class Remove
		refCount: int = 1
		def addRef() : unowned Remove
			GLib.AtomicInt.add (ref refCount, 1)
			return this
		def release() 
			if GLib.AtomicInt.dec_and_test (ref refCount) do this.free ()
		def extern free()

		game		: Game
		factory		: Factory
		movable		: Group	

		construct(game:Game, factory:Factory)
			this.game = game
			this.factory = factory

		def initialize()
			movable = factory.getGroup(Matcher.AllOf({Components.PositionComponent}))
		/**
		 * Remove entities that have gone off-screen
		 */
		def execute(delta:double)
			for entity in movable.entities do if entity.isActive() 
				case entity.pool
					when Pool.ENEMY1
						if entity.position.y > game.height do factory.deleteEntity(entity)
						
					when Pool.ENEMY2
						if entity.position.y > game.height do factory.deleteEntity(entity)
						
					when Pool.ENEMY3
						if entity.position.y > game.height do factory.deleteEntity(entity)
						
					when Pool.BULLET
						if entity.position.y < 0 do factory.deleteEntity(entity)


