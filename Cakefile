#
# generate the build task for vscode
#
valac = [
    "valac"
    "-C"
    "--save-temps"
    "--disable-warnings"
    "--vapidir ./vapis" 
    "--pkg posix" 
    "--pkg sdl2" 
    "--pkg SDL2_image" 
    "--pkg SDL2_ttf" 
    "--pkg SDL2_mixer"
    "--pkg emscripten"
]
emcc = [
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
task 'configure', 'configure the build scrpt', ->

    walk('src')

    cmd = [
        "cp -rf src build"
        "tools/valac.coffee"
        valac.concat(vala_code).join(" ")
        "tools/emcc.coffee"
        emcc.concat(c_code).join(" ")
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

##
## Task: update the build script
## set the build cycle to 'test'
##
task 'test', 'configure the test build scrpt', ->

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

