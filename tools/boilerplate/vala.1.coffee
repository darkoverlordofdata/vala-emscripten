#!/usr/bin/env coffee
###
##
##  inject vala boilerplate
##
## Injects reference counting boilerplate into classes declared as:
##
##  <ClassName> : Object
##
###
fs = require 'fs'
path = require 'path'
lcfirst = (str) -> str.charAt(0).toLowerCase() + str.substr(1)
snakeCase = (str) ->  str.replace(/([A-Z])/g, ($0) -> "_"+$0.toLowerCase())

##
## inject the reference counting code
##
module.exports = (file, options) ->


    klass = options.class
    name = options.name
    # fix namespace
    namespace = options.namespace.replace(/\//g, "_")
    # fix name
    name = snakeCase(lcfirst(klass))

    src = fs.readFileSync(file, 'utf8')

    if /^	public\s+class\s+\w*\s*:\s*Object\s{*/mg.test src
        src = src.replace(/^	public\s+class\s+(\w*)\s*:\s*(Object)\s*{/mg, ($0, $1, $2) ->
            """
\t[Compact, CCode ( /** reference counting */
\t\tref_function = "#{namespace}_#{name}_addRef", 
\t\tunref_function = "#{namespace}_#{name}_release"
\t)]
\tpublic class #{klass} {
\t\tpublic int refCount = 1;
\t\tpublic unowned #{klass} addRef() {
\t\t\tGLib.AtomicInt.add (ref refCount, 1);
\t\t\treturn this;
\t\t}
\t\tpublic void release() { 
\t\t\tif (GLib.AtomicInt.dec_and_test (ref refCount)) this.free ();
\t\t}
\t\tpublic extern void free();\n\t\t
        """)
        fs.writeFileSync(file, src)
    else if /^public\s+class\s+\w*\s*:\s*Object\s*{/mg.test src
        src = src.replace(/^public\s+class\s+(\w*)\s*:\s*(Object)\s*{/mg, ($0, $1, $2) ->
            """
[Compact, CCode ( /** reference counting */
	ref_function = "#{name}_addRef", 
	unref_function = "#{name}_release"
)]
public class #{klass} {
	public int refCount = 1;
	public unowned #{klass} addRef() {
		GLib.AtomicInt.add (ref refCount, 1);
		return this;
    }
	public void release() { 
		if (GLib.AtomicInt.dec_and_test (ref refCount)) this.free ();
    }
	public extern void free();\n\t
        """)
        fs.writeFileSync(file, src)

    else if /^	public\s+class\s+\w*\s*:\s*\w+\s*{/mg.test src
        src = src.replace(/^	public\s+class\s+(\w*)\s*:\s*(\w+)\s*{/mg, ($0, $1, $2) ->
            """
\t[Compact]
\tpublic class #{klass} : #{$2} {\n\t\t
        """)
        fs.writeFileSync(file, src)

    else if /^class\s+\w*\s*:\s*\w+\s*/mg.test src
        src = src.replace(/^class\s+(\w*)\s*:\s*(\w+)\s*/mg, ($0, $1, $2) ->
            """
[Compact]
public class #{klass} : #{$2} {\n\t
        """)
        fs.writeFileSync(file, src)


