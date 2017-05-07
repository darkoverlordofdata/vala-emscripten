uses entitas
namespace systems


	/**
	* game systems
	*/
	
	class SpawnSystem : Object

		game		: Game
		world		: Factory
		enemyT1     : double = 1.0
		enemyT2     : double = 4.0
		enemyT3     : double = 6.0

		construct(game:Game, world:Factory)
			this.game = game
			this.world = world

		def initialize()
			pass


		/**
		 * Spawn enemy ships
		 */
		def execute(delta:double)
			enemyT1 = spawnEnemy(delta, enemyT1, 1)
			enemyT2 = spawnEnemy(delta, enemyT2, 2)
			enemyT3 = spawnEnemy(delta, enemyT3, 3)

		def spawnEnemy(delta:double , t:double , enemy:int):double 
			var d1 = t-delta
			if (d1 < 0.0) 
				case enemy
					when 1
						var x = (int)(nextRand() * (game.width-70)) + 35
						world.enemy1(x, -35)
						return 1.0
					when 2
						var x = (int)(nextRand() * (game.width-172)) + 85
						world.enemy2(x, -85)
						return 4.0
					when 3
						var x = (int)(nextRand() * (game.width-320)) + 160
						world.enemy3(x, -160)
						return 6.0
					default
						return 0.0
				
			else 
				return d1    
