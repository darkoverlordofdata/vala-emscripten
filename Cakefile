###

generate the build task & launch configration for vscode
access via crtrl-B / F5

    cake em                   # set vscode to build & run the emscripten version
    cake test                 # set vscode to build & run the tests
    cake desktop              # set vscode to build & run the desktop version
    cake gobject              # set vscode to build & run the gobject version

preprocessing checks for Object superclass to inject reference counting into the class definition.
2nd pass is done to fix missing forward references when multiple files are used

assumptions:
one class per file
namespace must mirror folder structure
other classes should be unchanged.

###
PROFILING = '--define=PROFILING'
DEPS=[
        "--vapidir ./vapis"
        "--pkg sdl2"
        "--pkg SDL2_image"
        "--pkg SDL2_ttf"
        "--pkg SDL2_mixer"
        "--pkg posix"
        "--pkg emscripten"  
        "--pkg mt19937ar"
    ]

fs = require 'fs'
path = require 'path'
Makefile = require './Makefile.coffee'

C_CODE = []     # list of *.c source files
VALA_CODE = []  # list of *.vala source files

##
## find all of the source files
##
walk = (src, namespace = '') ->
    source = if namespace is "" then src else "#{src}/#{namespace}"
    for file in fs.readdirSync(source)
        switch path.extname(file)

            when '.gs' 
                VALA_CODE.push "build/#{source}/#{file}"
                C_CODE.push "build/#{source}/#{file}".replace(/\.gs$/mg, ".c")

            when '.vala' 
                VALA_CODE.push "build/#{source}/#{file}"
                C_CODE.push "build/#{source}/#{file}".replace(/\.vala$/mg, ".c")

            else # recurse down the tree
                f = namespace+(if namespace is "" then "" else '/')+file
                if f.indexOf('.') is -1 then walk(src, f)

##
## Task: update the build script
## set the build cycle to 'em'
##
valac_em = [ 
    "valac"
    "-C"
    "#{PROFILING}"
    "--save-temps"
    "--disable-warnings"
    "--vapidir ./vapis" 
    "--pkg mt19937ar"
    "--pkg posix" 
    "--pkg sdl2" 
    "--pkg SDL2_image" 
    "--pkg SDL2_ttf" 
    "--pkg SDL2_mixer"
    "--pkg emscripten"
]
emcc_em = [
    "emcc"
    "--preload-file assets" 
    "-Iinclude" 
    "-O2" 
    "-s WASM=1"
    "-s USE_SDL=2" 
    "-s USE_SDL_IMAGE=2" 
    "-s USE_SDL_TTF=2" 
    "-s SDL2_IMAGE_FORMATS='[\"png\"]'" 
    "-s EXPORTED_FUNCTIONS='[\"_game\"]'" 
    "-s ASSERTIONS=1"  
    "-o web/shmupwarz.html" 
]
task 'em', 'set vscode to build & run the emscripten version', ->

    walk('src')

    cmd = [
        "cp -rf src build"
        "tools/valac.coffee"
        valac_em.concat(VALA_CODE).join(" ")
        "tools/emcc.coffee"
        emcc_em.concat(C_CODE).join(" ")
    ].join(" && ")

    tasks = {
        "version": "0.1.0",
        "command": "/bin/sh",
        "cwd": "${workspaceRoot}",
        "isShellCommand": true,
        "args": ["-c"],
        "showOutput": "always",
        "echoCommand": true,
        "suppressTaskName": true,
        "tasks": [
            {
                "isBuildCommand": true,
                "taskName": "build",
                "args": [cmd]
            }
        ]
    }

    fs.writeFileSync('./.vscode/tasks.json', JSON.stringify(tasks, null, 2))

    launch =  {
        "version": "0.2.0",
        "configurations": [
            {
                "name": "Launch localhost",
                "type": "chrome",
                "request": "launch",
                "url": "http://localhost:8088",
                "webRoot": "${workspaceRoot}/web"
            },
        ]
    }

    fs.writeFileSync('./.vscode/launch.json', JSON.stringify(launch, null, 2))

##
## Task: update the build script
## set the build cycle to 'test'
##
valac_test = [
    "valac"
    "-C"
    "#{PROFILING}"
    "--save-temps"
    "--disable-warnings"
    "--vapidir ./vapis" 
    "--pkg posix" 
    "--pkg emscripten"
]
emcc_test = [
    "emcc"
    "--preload-file assets" 
    "-Iinclude" 
    "-O2" 
    "-s WASM=1"
    "-s ASSERTIONS=1"  
    "-o web/shmupwarz.html" 
]
task 'test', 'set vscode to build & run the tests', ->

    walk('test')

    cmd = [
        "cp -rf test build"
        "tools/valac.coffee test"
        valac_test.concat(VALA_CODE).join(" ")
        "tools/emcc.coffee test"
        emcc_test.concat(C_CODE).join(" ")
    ].join(" && ")

    tasks = {
        "version": "0.1.0",
        "command": "/bin/sh",
        "cwd": "${workspaceRoot}",
        "isShellCommand": true,
        "args": ["-c"],
        "showOutput": "always",
        "echoCommand": true,
        "suppressTaskName": true,
        "tasks": [
            {
                "isBuildCommand": true,
                "taskName": "build",
                "args": [cmd]
            }
        ]
    }

    fs.writeFileSync('./.vscode/tasks.json', JSON.stringify(tasks, null, 2))
    launch =  {
        "version": "0.2.0",
        "configurations": [
            {
                "name": "Launch localhost",
                "type": "chrome",
                "request": "launch",
                "url": "http://localhost:8088/shmupwarz.html",
                "webRoot": "${workspaceRoot}/web"
            },
        ]
    }

    fs.writeFileSync('./.vscode/launch.json', JSON.stringify(launch, null, 2))

##
## Task: update the build script
## set the build cycle to 'desktop'
##
valac_desktop = [
    "valac "
    "-C"
    "--save-temps"
    "--define=DESKTOP"
    "#{PROFILING}"
    "--disable-warnings"
    "--vapidir ./vapis"
    "--pkg mt19937ar"
    "--pkg posix"
    "--pkg sdl2"
    "--pkg SDL2_image"
    "--pkg SDL2_ttf"
]            #.replace("src/main.vala", "desktop.vala")

cc_desktop = [
    "clang"
    "-lm"
    "-lSDL2"
    "-lSDL2_image"
    "-lSDL2_ttf"
    "-Iinclude" 
    "-I/usr/include/SDL2"
    "-O3" 
    "-o build/shmupwarz"
]
task 'desktop', 'set vscode to build & run the desktop compact class version', ->

    walk('src')

    cmd = [
        "cp -rf src build"
        "tools/valac.coffee src"
        valac_desktop.concat(VALA_CODE).join(" ")
        "tools/emcc.coffee src"
        cc_desktop.concat(C_CODE).join(" ")
    ].join(" && ")

    tasks = {
        "version": "0.1.0",
        "command": "/bin/sh",
        "cwd": "${workspaceRoot}",
        "isShellCommand": true,
        "args": ["-c"],
        "showOutput": "always",
        "echoCommand": true,
        "suppressTaskName": true,
        "tasks": [
            {
                "isBuildCommand": true,
                "taskName": "build",
                "args": [cmd]
            }
        ]
    }

    fs.writeFileSync('./.vscode/tasks.json', JSON.stringify(tasks, null, 2))

    launch =  {
        "version": "0.2.0",
        "configurations": [
            {
                "name": "Debug",
                "type": "lldb",
                "request": "launch",
                "cwd": "${workspaceRoot}/build",
                "program": "${workspaceRoot}/build/shmupwarz",
                "args": []
            }
        ]
    }

    fs.writeFileSync('./.vscode/launch.json', JSON.stringify(launch, null, 2))

    fs.writeFileSync './Makefile', Makefile.profile.compact
        valac: 'valac'
        flags: '--save-temps --disable-warnings'
        defines: "--define=DESKTOP #{PROFILING}"
        dependancies: DEPS.join(" \\\n")
        code: VALA_CODE.join(" \\\n")
        cc: 'clang'
        c_code: C_CODE.join(" \\\n")
        optimize: '-O3'
        include: '-Iinclude'
        libraries: '-lm'
        resources: ''
        exporting: ''
        src: 'src'
        output: '-o build/shmupwarz'


##
## Task: update the build script
## set the build cycle to 'gobject'
##
gobject = [
    "valac "
    "--cc=clang"
    "#{PROFILING}"
    "--define=DESKTOP"
    "--disable-warnings"
    "--vapidir ./vapis"
    "--pkg mt19937ar"
    "--pkg posix"
    "--pkg sdl2"
    "--pkg SDL2_image"
    "--pkg SDL2_ttf"
    "--pkg SDL2_mixer"
    "-X -lm"
    "-X -g"
    "-X -O3"
    "-X -Wno-everything"
    "-X -Iinc"
    "-o build/shmupwarz"
]

task 'gobject', 'set vscode to build & run the gobject version', ->

    walk('src')

    cmd = [
        gobject.concat(VALA_CODE).join(" ")
            .replace(/build\/src/g, "src")
    ].join("")

    tasks = {
        "version": "0.1.0",
        "command": "/bin/sh",
        "cwd": "${workspaceRoot}",
        "isShellCommand": true,
        "args": ["-c"],
        "showOutput": "always",
        "echoCommand": true,
        "suppressTaskName": true,
        "tasks": [
            {
                "isBuildCommand": true,
                "taskName": "build",
                "args": [cmd]
            }
        ]
    }

    fs.writeFileSync('./.vscode/tasks.json', JSON.stringify(tasks, null, 2))

    launch =  {
        "version": "0.2.0",
        "configurations": [
            {
                "name": "Debug",
                "type": "lldb",
                "request": "launch",
                "cwd": "${workspaceRoot}/build",
                "program": "${workspaceRoot}/build/shmupwarz",
                "args": []
            }
        ]
    }

    fs.writeFileSync('./.vscode/launch.json', JSON.stringify(launch, null, 2))

    fs.writeFileSync './Makefile', Makefile.profile.gobject
        valac: 'valac --cc=clang'
        flags: '--disable-warnings'
        defines: "--define=DESKTOP #{PROFILING}"
        dependancies: DEPS.join(" \\\n")
        code: VALA_CODE.join(" \\\n").replace(/build\/src/g, "src")
        optimize: '-X -O3'
        include: '-X -Iinc'
        libraries: '-X -lm'
        resources: ''
        exporting: ''
        src: 'src'
        output: '-o build/shmupwarz'



