uses SDL
uses Emscripten
uses entitas
namespace systems


	/**
	* game systems
	*/
	[Compact, CCode ( /** reference counting */
		ref_function = "systems_physics_addRef", 
		unref_function = "systems_physics_release"
	)]
	class Physics
		refCount: int = 1
		def addRef() : unowned Physics
			GLib.AtomicInt.add (ref refCount, 1)
			return this
		def release() 
			if GLib.AtomicInt.dec_and_test (ref refCount) do this.free ()
		def extern free()

		game		: Game
		factory		: Factory
		physics		: Group

		construct(game:Game, factory:Factory)
			this.game = game
			this.factory = factory

		def initialize()
			physics = factory.getGroup(Matcher.AllOf({Components.VelocityComponent}))


		/**
		* physics system
		* model movement
		*/
		def execute(delta:double)

			for entity in physics.entities
				if entity.isActive() 

					var x = entity.position.x + entity.velocity.x * delta
					var y = entity.position.y + entity.velocity.y * delta

					entity.setPosition(x, y)
					entity.bounds.x = (int)x
					entity.bounds.y = (int)y



