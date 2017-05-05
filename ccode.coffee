#!/usr/bin/env coffee
###
##
## fix forward references to 
##      <class_name>_release
##      <class_name>_free
##      <class_name>_addRef
##
##  CCode atrribute forward referenes are not propogated to other outputs
##  in the same compilation unit. This fixes the intermediate c files before
##  final compilation.
##
##  Assumptions: 
##      a folder corresponds to a namespace
##      files with PascalCase names contain referece counted classes
##      there is one such class per file
###
fs = require 'fs'
path = require 'path'
list = []
options = {}

lcfirst = (str) -> str.charAt(0).toLowerCase() + str.substr(1)
snakeCase = (str) ->  str.replace(/([A-Z])/g, ($0) -> "_"+$0.toLowerCase())


##
## add missing references
##
patch = (file, options) ->
    src = fs.readFileSync(file, 'utf8').split('\n')
    dst = []
    for line in src 
        for mangled, name of options
            if line.indexOf("#define _#{mangled}_release0") is 0
                flag = true
                console.log "#{file}: #{name}"
                dst.push "void #{mangled}_release (#{name}* self);"
                dst.push "void #{mangled}_free (#{name}* self);"
                dst.push "#{name}* #{mangled}_addRef (#{name}* self);"
            else if line.indexOf("void #{mangled}_free (#{name}* self);") is 0
                flag = true
                console.log "#{file}: #{name}"
                dst.push "void #{mangled}_release (#{name}* self);"
                dst.push "#{name}* #{mangled}_addRef (#{name}* self);"
           dst.push line 
    if flag then fs.writeFileSync(file, dst.join('\n'))

##
## walk the folder, gather list of files, and load mangle options
##
walk = (namespace = '') ->
    source = if namespace is "" then "./build/src" else "./build/src/#{namespace}"
    for file in fs.readdirSync(source)
        if path.extname(file) is '.gs' then continue
        if path.extname(file) is '.vala' then continue
        if path.extname(file) isnt '.c' then walk(file)
        else
            list.push "#{source}/#{file}"
            klass = file.replace('.c','')
            if klass[0] >='A' && klass[0] <= 'Z'
                # name = snakeCase(lcfirst(klass))
                name = klass.toLowerCase()
                name1 = snakeCase(lcfirst(klass))
                mangled = if namespace is "" then name else "#{namespace}_#{name}"
                mangled1 = if namespace is "" then name1 else "#{namespace}_#{name1}"
                options[mangled] = namespace+klass

##
## fix the valac generated code
##
fix = () -> patch(file, options) for file in list
fix(walk())

