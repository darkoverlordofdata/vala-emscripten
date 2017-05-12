.PHONY: build
C1=valac
FLAGS=--save-temps --disable-warnings
DEF=--define=DESKTOP --define=PROFILING
DEP=--vapidir ./vapis \
--pkg sdl2 \
--pkg SDL2_image \
--pkg SDL2_ttf \
--pkg SDL2_mixer \
--pkg posix \
--pkg emscripten \
--pkg mt19937ar
CODE=build/src/Factory.vala \
build/src/Game.vala \
build/src/components.gs \
build/src/entitas/Cache.vala \
build/src/entitas/Group.vala \
build/src/entitas/Matcher.vala \
build/src/entitas/World.vala \
build/src/entitas/entitas.vala \
build/src/main.vala \
build/src/sdx/Color.gs \
build/src/sdx/Files.vala \
build/src/sdx/Font.vala \
build/src/sdx/files/FileHandle.vala \
build/src/sdx/graphics/Sprite.vala \
build/src/sdx/graphics/Surface.vala \
build/src/sdx/sdx.vala \
build/src/systems/AnimationSystem.vala \
build/src/systems/CollisionSystem.vala \
build/src/systems/DisplaySystem.vala \
build/src/systems/ExpireSystem.vala \
build/src/systems/InputSystem.vala \
build/src/systems/PhysicsSystem.vala \
build/src/systems/RemoveSystem.vala \
build/src/systems/ScoreSystem.vala \
build/src/systems/SpawnSystem.vala \
build/src/util/Cache.vala \
build/src/util/File.vala \
build/src/util/String.vala 

CC=clang
OPT=-O3
INC=-Iinclude 
RES=
EXP=
OUT=-o build/shmupwarz
IR=build/src/Factory.c \
build/src/Game.c \
build/src/components.c \
build/src/entitas/Cache.c \
build/src/entitas/Group.c \
build/src/entitas/Matcher.c \
build/src/entitas/World.c \
build/src/entitas/entitas.c \
build/src/main.c \
build/src/sdx/Color.c \
build/src/sdx/Files.c \
build/src/sdx/Font.c \
build/src/sdx/files/FileHandle.c \
build/src/sdx/graphics/Sprite.c \
build/src/sdx/graphics/Surface.c \
build/src/sdx/sdx.c \
build/src/systems/AnimationSystem.c \
build/src/systems/CollisionSystem.c \
build/src/systems/DisplaySystem.c \
build/src/systems/ExpireSystem.c \
build/src/systems/InputSystem.c \
build/src/systems/PhysicsSystem.c \
build/src/systems/RemoveSystem.c \
build/src/systems/ScoreSystem.c \
build/src/systems/SpawnSystem.c \
build/src/util/Cache.c \
build/src/util/File.c \
build/src/util/String.c

SRC=src

build: clean  all 

all:
	cp -rf $(SRC) build
	tools/valac.coffee
	$(C1) -C --save-temps $(FLAGS) $(DEF) $(DEP) $(CODE)
	tools/emcc.coffee
	$(CC) $(INC) $(OPT) $(RES) $(EXP) $(OUT) $(IR)

emcc:
	$(CC) $(INC) $(OPT) $(RES) $(EXP) $(OUT) $(IR)

clean:
	rm -rf build/$(SRC)
