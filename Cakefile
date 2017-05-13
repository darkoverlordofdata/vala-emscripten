###

    cake em                   # build the emscripten version
    cake test                 # build the tests

preprocessing checks for Object superclass to inject reference counting into the class definition.
2nd pass is done to fix missing forward references when multiple files are used

assumptions:
one class per file
namespace must mirror folder structure
other classes should be unchanged.

###

fs = require 'fs'
path = require 'path'
{ exec } = require 'child_process'

PROFILING = '--define=PROFILING'
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
## Check for problem and bail
##
bail = (error, stdout, stderr) ->
    console.log error if error
    console.log stdout if stdout
    console.log stderr if stderr
    process.exit() if error

valac_em = [ 
    "valac"
    "-C"
    "#{PROFILING}"
    "--save-temps"
    "--disable-warnings"
    "--vapidir src/vapis" 
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

##
## Task: update the build script
## set the build cycle to 'em'
##
task 'em', 'set vscode to build & run the emscripten version', ->

    walk 'src'

    ## out of tree build
    exec 'cp -rf src build', (error, stdout, stderr) -> 
        bail error, stdout, stderr

        # pre-process vala 
        exec 'tools/valac.coffee', (error, stdout, stderr) -> 
            bail error, stdout, stderr

            # valac -C ...
            exec valac_em.concat(VALA_CODE).join(' '), (error, stdout, stderr) -> 
                bail error, stdout, stderr

                # pre-process c
                exec 'tools/emcc.coffee', (error, stdout, stderr) -> 
                    bail error, stdout, stderr
                        
                    # emcc ... -o web/shmupwarz.html
                    exec emcc_em.concat(C_CODE).join(' '), (error, stdout, stderr) -> 
                        bail error, stdout, stderr
                        console.log "Ok!"



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

    exec(cmd, puts);

