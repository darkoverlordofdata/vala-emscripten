uses SDL
uses Emscripten
uses entitas
namespace systems


	/**
	* game systems
	*/
	[Compact, CCode ( /** reference counting */
		ref_function = "systems_collision_addRef", 
		unref_function = "systems_collision_release"
	)]
	class Collision
		refCount: int = 1
		def addRef() : unowned Collision
			GLib.AtomicInt.add (ref refCount, 1)
			return this
		def release() 
			if GLib.AtomicInt.dec_and_test (ref refCount) do this.free ()
		def extern free()

		game		: Game
		factory		: Factory
		bullets		: Group
		enemies		: Group

		construct(game:Game, factory:Factory)
			this.game = game
			this.factory = factory

		def initialize()
			bullets = factory.getGroup(Matcher.AllOf({ Components.BulletComponent }))
			enemies = factory.getGroup(Matcher.AnyOf({
				Components.Enemy1Component, 
				Components.Enemy2Component, 
				Components.Enemy3Component
			}))


		/**
		* physics system
		* model movement
		*/
		def execute(delta:double)
			for var enemy in enemies.entities do if enemy.isActive()
				for var bullet in bullets.entities do if bullet.isActive()
					if intersects(enemy.bounds, bullet.bounds)
						handleCollision(ref enemy, ref bullet)
						return


		def intersects(r1:Bounds, r2:Bounds):bool 
			return ((r1.x < r2.x + r2.w) && 
					(r1.x + r1.w > r2.x) && 
					(r1.y < r2.y + r2.h) && 
					(r1.y + r1.h > r2.y)) 
		

		def handleCollision(ref a:Entity*, ref b:Entity*)
			var x = (int)((double)b.position.x - b.bounds.w / 2)
			var y = (int)((double)b.position.y - b.bounds.h / 2)
			//factory.newBang(x, y)
			factory.deleteEntity(b)
			//for var i=0 to 3 do factory.newParticle(x, y)
			if a.health != null
				var current = a.health.current - 2
				if current < 0
					//factory.newExplosion((int)a.position.x, (int)a.position.y)
					factory.deleteEntity(a)
				else 
					a.health.current = current


