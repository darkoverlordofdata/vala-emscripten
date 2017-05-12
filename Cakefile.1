###

generate the build task & launch configration for vscode
access via crtrl-B / F5


    cake em                   # set vscode to build & run the emscripten version
    cake test                 # set vscode to build & run the test
    cake desktop              # set vscode to build & run the desktop version


preprocessing checks for Object superclass to inject reference counting into the class definition.
2nd pass is done to fix missing forward references when multiple files are used

assumptions:
one class per file
namespace must mirror folder structure
other classes should be unchanged.

###
fs = require 'fs'
path = require 'path'
vala_code = []
c_code = []

##
## find all of the source files
##
walk = (src, namespace = '') ->
    source = if namespace is "" then src else "#{src}/#{namespace}"
    for file in fs.readdirSync(source)
        switch path.extname(file)

            when '.gs' 
                vala_code.push "build/#{source}/#{file}"
                c_code.push "build/#{source}/#{file}".replace(/\.gs$/mg, ".c")

            when '.vala' 
                vala_code.push "build/#{source}/#{file}"
                c_code.push "build/#{source}/#{file}".replace(/\.vala$/mg, ".c")

            else # recurse down the tree
                f = namespace+(if namespace is "" then "" else '/')+file
                if f.indexOf('.') is -1 then walk(src, f)

##
## Task: update the build script
## set the build cycle to 'src'
##
valac_em = [ 
    "valac"
    "-C"
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
        valac_em.concat(vala_code).join(" ")
        "tools/emcc.coffee"
        emcc_em.concat(c_code).join(" ")
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
task 'test', 'set vscode to build & run the test', ->

    walk('test')

    cmd = [
        "cp -rf test build"
        "tools/valac.coffee test"
        valac_test.concat(vala_code).join(" ")
        "tools/emcc.coffee test"
        emcc_test.concat(c_code).join(" ")
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
desktop = [
    "valac "
    "-X -lm"
    "-X -g"
    "-X -O2"
    "-X -Wno-everything"
    "-X -Iinc"
    "--cc=clang"
    "--define=DESKTOP"
    "--disable-warnings"
    "--vapidir ./vapis"
    "--pkg mt19937ar"
    "--pkg posix"
    "--pkg sdl2"
    "--pkg SDL2_image"
    "--pkg SDL2_ttf"
    "--pkg SDL2_mixer"
    "-o build/shmupwarz"
]            #.replace("src/main.vala", "desktop.vala")

task 'desktop', 'set vscode to build & run the desktop version', ->

    walk('src')

    cmd = [
        desktop.concat(vala_code).join(" ")
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
