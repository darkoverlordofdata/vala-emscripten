uses sdx.files

namespace sdx

	enum FileType
		Internal
		Resource
		External
		Absolute
		Local
	/**
	 * a reference counted wrapper for surface
	 * prevents the surface memory from being reclaimed 
	 * 
	 */
	
	class Files : Object

		isResource: bool
		resourcePath: string

		construct(resourcePath: string)
			this.resourcePath = resourcePath

		def getHandle(path: string, type: FileType): FileHandle
			return new FileHandle(path, type)

		def @internal(path: string): FileHandle
			return new FileHandle(path, FileType.Internal)

		def resource(path: string): FileHandle
			return new FileHandle(path, FileType.Resource)

		def external(path: string): FileHandle
			return new FileHandle(path, FileType.External)

		def absolute(path: string): FileHandle
			return new FileHandle(path, FileType.Absolute)

		def local(path: string): FileHandle
			return new FileHandle(path, FileType.Local)
