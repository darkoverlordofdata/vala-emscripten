.PHONY: build
VALAC=posixvalac
DEPS=--vapidir ./vapis --pkg sdl --pkg emscripten
SOURCE=build/src/main.gs \
	build/src/Game.gs \
	build/src/components.gs \
	build/src/Systems.gs \
	build/src/Factory.gs \
	build/src/systems/Collision.gs \
	build/src/systems/Expire.gs \
	build/src/systems/Input.gs \
	build/src/systems/Physics.gs \
	build/src/systems/Remove.gs \
	build/src/systems/Spawn.gs \
	build/src/entitas/entitas.gs \
	build/src/entitas/World.gs \
	build/src/entitas/Group.gs \
	build/src/entitas/Matcher.gs 

CC=emcc
INCLUDE=-Iposix
RESOURCES=--use-preload-plugins --preload-file assets
CCODE=build/src/main.c \
	build/src/Game.c \
	build/src/components.c \
	build/src/Systems.c \
	build/src/systems/Collision.c \
	build/src/systems/Expire.c \
	build/src/systems/Input.c \
	build/src/systems/Physics.c \
	build/src/systems/Remove.c \
	build/src/systems/Spawn.c \
	build/src/Factory.c \
	build/src/entitas/entitas.c \
	build/src/entitas/World.c \
	build/src/entitas/Group.c \
	build/src/entitas/Matcher.c 


build:
	cp -rf src build
	./pseudo.coffee
	$(VALAC) -C --save-temps --disable-warnings $(DEPS) $(SOURCE)
	./ccode.coffee
	$(CC) -s WASM=1 $(INCLUDE) -O2 $(RESOURCES) -o web/index.html $(CCODE)


clean:
	rm -rf web/index.data
	rm -rf web/index.js
	rm -rf web/index.wasm
	rm -rf web/index.html

