.PHONY: build
VALAC=posixvalac
DEPS=--vapidir ./vapis \
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

#-I/usr/local/include/SDL2 -I/usr/include/SDL2

SOURCE=build/src/main.gs \
	build/src/Game.gs \
	build/src/components.gs \
	build/src/Factory.gs \
	build/src/systems/Collision.gs \
	build/src/systems/Expire.gs \
	build/src/systems/Input.gs \
	build/src/systems/Physics.gs \
	build/src/systems/Remove.gs \
	build/src/systems/Spawn.gs \
	build/src/systems/Animation.gs \
	build/src/entitas/entitas.gs \
	build/src/entitas/World.gs \
	build/src/entitas/Stack.gs \
	build/src/entitas/Group.gs \
	build/src/entitas/Matcher.gs \
	build/src/sdx/Font.gs \
	build/src/sdx/Sprite.gs \
	build/src/sdx/Surface.gs 

CCODE=build/src/main.c \
	build/src/Game.c \
	build/src/components.c \
	build/src/Factory.c \
	build/src/systems/Collision.c \
	build/src/systems/Expire.c \
	build/src/systems/Input.c \
	build/src/systems/Physics.c \
	build/src/systems/Remove.c \
	build/src/systems/Spawn.c \
	build/src/systems/Animation.c \
	build/src/entitas/entitas.c \
	build/src/entitas/World.c \
	build/src/entitas/Stack.c \
	build/src/entitas/Group.c \
	build/src/entitas/Matcher.c \
	build/src/sdx/Font.c \
	build/src/sdx/Sprite.c \
	build/src/sdx/Surface.c 


build:
	cp -rf src build
	./pseudo.coffee
	$(VALAC) -C --save-temps --disable-warnings $(DEPS) $(SOURCE)
	./ccode.coffee
	$(CC) -s WASM=1 $(INCLUDE) -O2 $(RESOURCES) $(EXPORTS) -s ASSERTIONS=1  -o web/shmupwarz.html $(CCODE)

emcc:
	$(CC) -s WASM=1 $(INCLUDE) -O2 $(RESOURCES) $(EXPORTS) -s ASSERTIONS=1  -o web/shmupwarz.html $(CCODE)

clean:
	rm -rf web/index.data
	rm -rf web/index.js
	rm -rf web/index.wasm
	rm -rf web/index.html

