.PHONY: build
GSCODE=build/src/main.gs \
	build/src/Game.gs \
	build/src/components.gs \
	build/src/Factory.gs \
	build/src/systems/CollisionSystem.gs \
	build/src/systems/DisplaySystem.gs \
	build/src/systems/ExpireSystem.gs \
	build/src/systems/InputSystem.gs \
	build/src/systems/PhysicsSystem.gs \
	build/src/systems/RemoveSystem.gs \
	build/src/systems/ScoreSystem.gs \
	build/src/systems/SpawnSystem.gs \
	build/src/systems/AnimationSystem.gs \
	build/src/entitas/entitas.gs \
	build/src/entitas/World.gs \
	build/src/entitas/Cache.gs \
	build/src/entitas/Group.gs \
	build/src/entitas/Matcher.gs \
	build/src/util/File.gs \
	build/src/util/String.gs \
	build/src/sdx/sdx.gs \
	build/src/sdx/Color.gs \
	build/src/sdx/Files.gs \
	build/src/sdx/Font.gs \
	build/src/sdx/files/FileHandle.gs \
	build/src/sdx/graphics/Sprite.gs \
	build/src/sdx/graphics/Surface.gs 

CCODE=build/src/main.c \
	build/src/Game.c \
	build/src/components.c \
	build/src/Factory.c \
	build/src/systems/CollisionSystem.c \
	build/src/systems/DisplaySystem.c \
	build/src/systems/ExpireSystem.c \
	build/src/systems/InputSystem.c \
	build/src/systems/PhysicsSystem.c \
	build/src/systems/RemoveSystem.c \
	build/src/systems/ScoreSystem.c \
	build/src/systems/SpawnSystem.c \
	build/src/systems/AnimationSystem.c  \
	build/src/entitas/entitas.c \
	build/src/entitas/World.c \
	build/src/entitas/Cache.c \
	build/src/entitas/Group.c \
	build/src/entitas/Matcher.c \
	build/src/util/File.c \
	build/src/util/String.c \
	build/src/sdx/sdx.c \
	build/src/sdx/Color.c \
	build/src/sdx/Files.c \
	build/src/sdx/Font.c \
	build/src/sdx/files/FileHandle.c \
	build/src/sdx/graphics/Sprite.c \
	build/src/sdx/graphics/Surface.c 

C1=valac
DEPS=--vapidir ./vapis \
	--pkg posix \
	--pkg sdl2 \
	--pkg SDL2_image \
	--pkg SDL2_ttf \
	--pkg SDL2_mixer \
	--pkg emscripten
CC=emcc
INCLUDE=-Iposix 
RESOURCES=-s USE_SDL=2 \
	-s USE_SDL_IMAGE=2 \
	-s USE_SDL_TTF=2 \
	-s SDL2_IMAGE_FORMATS='["png"]' \
	--preload-file assets

EXPORTS=-s EXPORTED_FUNCTIONS='["_game"]'

build: clean  all 

all:
	cp -rf src build
	tools/valac.coffee
	$(C1) -C --save-temps --disable-warnings $(DEPS) $(GSCODE)
	tools/emcc.coffee
	$(CC) -s WASM=1 $(INCLUDE) -O2 $(RESOURCES) $(EXPORTS) -s ASSERTIONS=1  -o web/shmupwarz.html $(CCODE)

emcc:
	$(CC) -s WASM=1 $(INCLUDE) -O2 $(RESOURCES) $(EXPORTS) -s ASSERTIONS=1  -o web/shmupwarz.html $(CCODE)

clean:
	rm -rf build/src
	rm -rf web/shmupwarz.data
	rm -rf web/shmupwarz.js
	rm -rf web/shmupwarz.wasm
	rm -rf web/shmupwarz.html

