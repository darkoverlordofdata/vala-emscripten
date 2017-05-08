namespace util

	/**
	 * Not a replacement for string type
     *
     * String holds on to a char buffer for strings
     * returned from Posix calls so that their memory
     * will not be reclaimed.
     * @see utils.File 
	 * 
	 */
	
	class String : Object

		buf__: array of char

		construct(str: string)
			buf__ = new array of char[str.length]
			for var i=0 to (str.length-1) do buf__[i] = str[i]

		def to_string(): string
			return (string)buf__


