uses SDL
uses Emscripten
uses entitas
namespace systems


	/**
	* game systems
	*/
	[Compact, CCode ( /** reference counting */
		ref_function = "systems_expire_addRef", 
		unref_function = "systems_expire_release"
	)]
	class Expire
		refCount: int = 1
		def addRef() : unowned Expire
			GLib.AtomicInt.add (ref refCount, 1)
			return this
		def release() 
			if GLib.AtomicInt.dec_and_test (ref refCount) do this.free ()
		def extern free()

		game		: Game
		factory		: Factory
		expiring	: Group

		construct(game:Game, factory:Factory)
			this.game = game
			this.factory = factory

		def initialize()
			expiring = factory.getGroup(Matcher.AllOf({Components.ExpiresComponent}))


		/**
		 * Remove exired entities
		 */
		def execute(delta:double)
			for entity in expiring.entities do if entity.isActive() 
				var exp = entity.expires.value - delta
				entity.expires.value = exp
				if entity.expires.value < 0 do factory.deleteEntity(entity)


