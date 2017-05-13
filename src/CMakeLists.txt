### CMakeLists automatically created with AutoVala
### Do not edit

set (DATADIR "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_DATAROOTDIR}")
set (PKGDATADIR "${DATADIR}/vala-emscripten")
set (GETTEXT_PACKAGE "vala-emscripten")
set (RELEASE_NAME "vala-emscripten")
set (CMAKE_C_FLAGS "")
set (PREFIX ${CMAKE_INSTALL_PREFIX})
set (VERSION "1.0.0")
set (TESTSRCDIR "${CMAKE_SOURCE_DIR}")
set (DOLLAR "$")

configure_file (${CMAKE_SOURCE_DIR}/src/Config.vala.base ${CMAKE_BINARY_DIR}/src/Config.vala)
add_definitions(-DGETTEXT_PACKAGE=\"${GETTEXT_PACKAGE}\")
set (VERSION "1.0.0")
add_definitions (${DEPS_CFLAGS})
link_libraries ( ${DEPS_LIBRARIES} )
link_directories ( ${DEPS_LIBRARY_DIRS} )
find_package (Vala REQUIRED)
include (ValaVersion)
ensure_vala_version ("0.34" MINIMUM)
include (ValaPrecompile)

set (VALA_PACKAGES ${VALA_PACKAGES} SDL2_image)
set (VALA_PACKAGES ${VALA_PACKAGES} SDL2_ttf)
set (VALA_PACKAGES ${VALA_PACKAGES} glib-2.0)
set (VALA_PACKAGES ${VALA_PACKAGES} gobject-2.0)
set (VALA_PACKAGES ${VALA_PACKAGES} sdl2)

set (APP_SOURCES ${APP_SOURCES} ${CMAKE_CURRENT_BINARY_DIR}/Config.vala)
set (APP_SOURCES ${APP_SOURCES} Factory.vala)
set (APP_SOURCES ${APP_SOURCES} Game.vala)
set (APP_SOURCES ${APP_SOURCES} components.gs)
set (APP_SOURCES ${APP_SOURCES} entitas/Cache.vala)
set (APP_SOURCES ${APP_SOURCES} entitas/Group.vala)
set (APP_SOURCES ${APP_SOURCES} entitas/Matcher.vala)
set (APP_SOURCES ${APP_SOURCES} entitas/World.vala)
set (APP_SOURCES ${APP_SOURCES} entitas/entitas.vala)
set (APP_SOURCES ${APP_SOURCES} main.vala)
set (APP_SOURCES ${APP_SOURCES} sdx/Color.gs)
set (APP_SOURCES ${APP_SOURCES} sdx/Files.vala)
set (APP_SOURCES ${APP_SOURCES} sdx/Font.vala)
set (APP_SOURCES ${APP_SOURCES} sdx/files/FileHandle.vala)
set (APP_SOURCES ${APP_SOURCES} sdx/graphics/Sprite.vala)
set (APP_SOURCES ${APP_SOURCES} sdx/graphics/Surface.vala)
set (APP_SOURCES ${APP_SOURCES} sdx/sdx.vala)
set (APP_SOURCES ${APP_SOURCES} systems/AnimationSystem.vala)
set (APP_SOURCES ${APP_SOURCES} systems/CollisionSystem.vala)
set (APP_SOURCES ${APP_SOURCES} systems/DisplaySystem.vala)
set (APP_SOURCES ${APP_SOURCES} systems/ExpireSystem.vala)
set (APP_SOURCES ${APP_SOURCES} systems/InputSystem.vala)
set (APP_SOURCES ${APP_SOURCES} systems/PhysicsSystem.vala)
set (APP_SOURCES ${APP_SOURCES} systems/RemoveSystem.vala)
set (APP_SOURCES ${APP_SOURCES} systems/ScoreSystem.vala)
set (APP_SOURCES ${APP_SOURCES} systems/SpawnSystem.vala)
set (APP_SOURCES ${APP_SOURCES} util/Cache.vala)
set (APP_SOURCES ${APP_SOURCES} util/File.vala)
set (APP_SOURCES ${APP_SOURCES} util/String.vala)
set (APP_SOURCES ${APP_SOURCES} vala-emscripten.vala)

set (CUSTOM_VAPIS_LIST ${CUSTOM_VAPIS_LIST} ${CMAKE_SOURCE_DIR}/src/vapis/emscripten.vapi)
set (CUSTOM_VAPIS_LIST ${CUSTOM_VAPIS_LIST} ${CMAKE_SOURCE_DIR}/src/vapis/mt19937ar.vapi)
set (CUSTOM_VAPIS_LIST ${CUSTOM_VAPIS_LIST} ${CMAKE_SOURCE_DIR}/src/vapis/posix.vapi)

if (PROFILING)
	set (COMPILE_OPTIONS ${COMPILE_OPTIONS} -D PROFILING)
	set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DPROFILING " )
	set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DPROFILING " )
endif ()
if (DESKTOP)
	set (COMPILE_OPTIONS ${COMPILE_OPTIONS} -D DESKTOP)
	set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DDESKTOP " )
	set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DDESKTOP " )
endif ()
set (COMPILE_OPTIONS ${COMPILE_OPTIONS} --vapidir=${CMAKE_SOURCE_DIR}/src/vapis )

if ((${CMAKE_BUILD_TYPE} STREQUAL "Debug") OR (${CMAKE_BUILD_TYPE} STREQUAL "RelWithDebInfo"))
	set(COMPILE_OPTIONS ${COMPILE_OPTIONS} "-g")
endif()

set (COMPILE_OPTIONS ${COMPILE_OPTIONS} --disable-warnings --cc=clang )

set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -Og" )
include_directories (AFTER include )

vala_precompile(VALA_C vala-emscripten
	${APP_SOURCES}
PACKAGES
	${VALA_PACKAGES}
CUSTOM_VAPIS
	${CUSTOM_VAPIS_LIST}
OPTIONS
	${COMPILE_OPTIONS}
)

add_executable(vala-emscripten ${VALA_C})
target_link_libraries( vala-emscripten m )


install(TARGETS
	vala-emscripten
RUNTIME DESTINATION
	${CMAKE_INSTALL_BINDIR}
)
if(HAVE_VALADOC)
	valadoc(vala-emscripten
		${CMAKE_BINARY_DIR}/valadoc/vala-emscripten
		${APP_SOURCES}
	PACKAGES
		${VALA_PACKAGES}
	CUSTOM_VAPIS
		${CUSTOM_VAPIS_LIST}
	)
	install(DIRECTORY
		${CMAKE_BINARY_DIR}/valadoc
	DESTINATION
		${CMAKE_INSTALL_DATAROOTDIR}/doc/vala-emscripten
	)
endif()
