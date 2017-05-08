namespace sdx.files

	
	class FileHandle : Object
		file: util.File
		path: string
		type: FileType

		construct(path: string, type: FileType)
			this.path = path
			this.type = type
			this.file = new util.File(path)

