#!/usr/bin/env coffee
###
##
## replace [Pseudo] with biolerplate
##
##
###
fs = require 'fs'
path = require 'path'
list = []
options = {}
lcfirst = (str) -> str.charAt(0).toLowerCase() + str.substr(1)
snakeCase = (str) ->  str.replace(/([A-Z])/g, ($0) -> "_"+$0.toLowerCase())

##
## inject the bolerplate
##
inject = (file, options) ->
    klass = options.class
    name = options.name
    namespace = options.namespace
    

    src = fs.readFileSync(file, 'utf8')

    if /^	\[Pseudo\]\n	class \w*/mg.test src
        src = src.replace(/^	\[(Pseudo)\]\n	class (\w*)/mg, ($0, $1, $2) ->
            """
\t[Compact, CCode ( /** reference counting */
\t\tref_function = "#{namespace}_#{name}_addRef", 
\t\tunref_function = "#{namespace}_#{name}_release"
\t)]
\tclass #{klass}
\t\trefCount: int = 1
\t\tdef addRef() : unowned #{klass}
\t\t\tGLib.AtomicInt.add (ref refCount, 1)
\t\t\treturn this
\t\tdef release() 
\t\t\tif GLib.AtomicInt.dec_and_test (ref refCount) do this.free ()
\t\tdef extern free()
        """)
        fs.writeFileSync(file, src)
    else if /^\[Pseudo\]\nclass \w*/mg.test src
        src = src.replace(/^\[(Pseudo)\]\nclass (\w*)/mg, ($0, $1, $2) ->
            """
[Compact, CCode ( /** reference counting */
	ref_function = "#{name}_addRef", 
	unref_function = "#{name}_release"
)]
class #{klass}
	refCount: int = 1
	def addRef() : unowned #{klass}
		GLib.AtomicInt.add (ref refCount, 1)
		return this
	def release() 
		if GLib.AtomicInt.dec_and_test (ref refCount) do this.free ()
	def extern free()
        """)
        fs.writeFileSync(file, src)


##
## walk the folder, gather list of files
##
walk = (namespace = '') ->
    source = if namespace is "" then "./build/src" else "./build/src/#{namespace}"
    for file in fs.readdirSync(source)
        if path.extname(file) is '.vala' then continue
        if path.extname(file) is '.c' then continue
        if path.extname(file) isnt '.gs' then walk(file)
        else 
            klass = file.replace('.gs','')
            if klass[0] >='A' && klass[0] <= 'Z'
                list.push "#{source}/#{file}"
                name = klass.toLowerCase()
                options["#{source}/#{file}"] = { 'class': klass, 'name': name, 'namespace': namespace }

##
## fix the valac generated code
##
fix = () -> inject(file, options[file]) for file in list
fix(walk())

