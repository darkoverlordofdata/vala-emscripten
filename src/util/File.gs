namespace util

	const pathSeparator : string  = "/"
	const pathSeparatorChar : char  = '/'
	/**
	 * Simple File handler
	 * 
	 */
	
	class File : Object

		buf__		: uint8[4096]
		stat__		: Posix.Stat?
		path__		: string
		files__		: array of string
		ioBuff__	: array of char
		fileList__	: List of String 

		construct(path: string)
			this.path__ = (string)Posix.realpath(path, buf__) 

		def getPath():string
			return path__

		/**
		 * the name is everything after the final separator
		 */
		def getName():string
			for var i=(path__.length-1) downto 0
				if path__[i] == pathSeparatorChar do return path__.substring(i+1)
			return path__

		/**
		 * the parent is everything prior to the final separator
		 */
		def getParent():string
			for var i=(path__.length-1) downto 0
				if path__[i] == pathSeparatorChar do return path__.substring(0, i-1)
			return ""

		/**
		 * check if the represented struture exists on the virtual disk
		 */
		def exists():bool
			return Posix.stat(path__, out stat__) == 0 

		/**
		 * is it a file?
		 */
		def isFile():bool
			return exists() ? Posix.S_ISREG(stat__.st_mode) : false

		/**
		 * is it a folder?
		 */
		def isDirectory():bool
			return exists() ? Posix.S_ISDIR(stat__.st_mode) : false

		def length():int
			return exists() ? (int)stat__.st_size : 0
		
		def read(): string
			if !isFile() do return ""
			var l = length()
			ioBuff__ = new array of char[l+1]
			ioBuff__[l] = 0
			f:Posix.FILE = Posix.FILE.open(path__, "r")
			return f.gets(ioBuff__)

		/**
		 * return the list of files in the folder
		 */
		def @list(): array of string
			if !isDirectory()
				files__ = new array of string[0]
				return files__

			dp: Posix.Dir?
			ep: unowned Posix.DirEnt?

			fileList__ = new List of String
			if (dp = Posix.opendir(path__)) != null
				while (ep = Posix.readdir(dp)) != null
					var s = new String((string)ep.d_name)
					fileList__.append(s)

			files__ = new array of string[fileList__.length()]
			var i = 0
			for var s in fileList__	do files__[i++] = s.to_string()
			return files__
