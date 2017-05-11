#!/usr/bin/env bash

valac  \
    -X -lm \
    --cc=clang \
    --save-temps \
    --disable-warnings \
    --vapidir ./vapis \
    --pkg posix \
    --pkg sdl2 \
    --pkg SDL2_image \
    --pkg SDL2_ttf \
    --pkg SDL2_mixer \
    src/Factory.vala \
    src/Game.vala \
    src/components.gs \
    src/entitas/Cache.vala \
    src/entitas/Group.vala \
    src/entitas/Matcher.vala \
    src/entitas/World.vala \
    src/entitas/entitas.vala \
    desktop.vala \
    src/sdx/Color.gs \
    src/sdx/Files.vala \
    src/sdx/Font.vala \
    src/sdx/files/FileHandle.vala \
    src/sdx/graphics/Sprite.vala \
    src/sdx/graphics/Surface.vala \
    src/sdx/sdx.vala \
    src/systems/AnimationSystem.vala \
    src/systems/CollisionSystem.vala \
    src/systems/DisplaySystem.vala \
    src/systems/ExpireSystem.vala \
    src/systems/InputSystem.vala \
    src/systems/PhysicsSystem.vala \
    src/systems/RemoveSystem.vala \
    src/systems/ScoreSystem.vala \
    src/systems/SpawnSystem.vala \
    src/util/Cache.vala \
    src/util/File.vala \
    src/util/String.vala \
    -o build/shmupwarz
    

