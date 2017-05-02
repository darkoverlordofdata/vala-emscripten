uses SDL
uses Emscripten
uses entitas
namespace systems


	/**
	* game systems
	*/
	[Compact, CCode ( /** reference counting */
		ref_function = "systems_collisionsystem_addRef", 
		unref_function = "systems_collisionsystem_release"
	)]
	class CollisionSystem

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
		def execute(entity:Entity*, delta:double)
            pass

		/**
		* Implement reference counting
		*/
		refCount: int = 1
		def addRef() : unowned CollisionSystem
			GLib.AtomicInt.add (ref refCount, 1)
			return this
		def release() 
			if GLib.AtomicInt.dec_and_test (ref refCount) do this.free ()
		def extern free()
