project('vala-emscripten',['c','vala'])

PROFILING = (get_option('PROFILING') != '')
DESKTOP = (get_option('DESKTOP') != '')

add_global_arguments('-DGETTEXT_PACKAGE="vala-emscripten"',language: 'c')

SDL2_image_dep = dependency('SDL2_image')
SDL2_ttf_dep = dependency('SDL2_ttf')
gio_2_0_dep = dependency('gio-2.0')
glib_2_0_dep = dependency('glib-2.0')
gobject_2_0_dep = dependency('gobject-2.0')
json_glib_1_0_dep = dependency('json-glib-1.0')
sdl2_dep = dependency('sdl2')
Entitas_dep = dependency('Entitas')
SDL2_mixer_dep = dependency('SDL2_mixer')
gee_0_8_dep = dependency('gee-0.8')
sdx_dep = dependency('sdx')

resources_gresource_xml_generator = generator(find_program('glib-compile-resources'), arguments: [ '--sourcedir=@SOURCE_DIR@/data' , '--generate-source', '--target=@BUILD_DIR@/resources.gresource.xml.c', '@INPUT@'], output: '@PLAINNAME@.c')

resources_gresource_xml_file_c = resources_gresource_xml_generator.process(['data/resources.gresource.xml'])

meson.add_install_script(join_paths(meson.current_source_dir(),'meson_scripts','install_data.sh'),join_paths(get_option('prefix'),get_option('datadir'),'vala-emscripten'),join_paths(meson.current_source_dir(),'data/local','','*'))

meson.add_install_script(join_paths(meson.current_source_dir(),'meson_scripts','install_data.sh'),join_paths(get_option('prefix'),get_option('datadir'),'doc'),join_paths(meson.current_source_dir(),'doc','','*'))

install_data('data/shmupwarz.desktop',install_dir:join_paths(get_option('prefix'),get_option('datadir'),'applications'))
cfg_vala-emscripten = configuration_data()
cfg_vala-emscripten.set('DATADIR', join_paths(get_option('prefix'),get_option('datadir')))
cfg_vala-emscripten.set('PKGDATADIR', join_paths(get_option('prefix'),get_option('datadir'),'vala-emscripten'))
cfg_vala-emscripten.set('GETTEXT_PACKAGE', 'vala-emscripten')
cfg_vala-emscripten.set('RELEASE_NAME', 'vala-emscripten')
cfg_vala-emscripten.set('PREFIX', get_option('prefix'))
cfg_vala-emscripten.set('VERSION', '1.0.0')
cfg_vala-emscripten.set('TESTSRCDIR', meson.current_source_dir())

cfgfile_1 = configure_file(input: 'src/Config.vala.base',output: 'Config_1.vala',configuration: cfg_vala-emscripten)

vala-emscripten_deps = [SDL2_image_dep]
vala-emscripten_deps += [SDL2_ttf_dep]
vala-emscripten_deps += [gio_2_0_dep]
vala-emscripten_deps += [glib_2_0_dep]
vala-emscripten_deps += [gobject_2_0_dep]
vala-emscripten_deps += [json_glib_1_0_dep]
vala-emscripten_deps += [sdl2_dep]
vala-emscripten_deps += [Entitas_dep]
vala-emscripten_deps += [SDL2_mixer_dep]
vala-emscripten_deps += [gee_0_8_dep]
vala-emscripten_deps += [sdx_dep]
vala-emscripten_sources = [cfgfile_1]
vala-emscripten_sources += ['src/Factory.vala']
vala-emscripten_sources += ['src/Game.vala']
vala-emscripten_sources += ['src/components.gs']
vala-emscripten_sources += ['src/entitas/Cache.vala']
vala-emscripten_sources += ['src/entitas/Group.vala']
vala-emscripten_sources += ['src/entitas/Matcher.vala']
vala-emscripten_sources += ['src/entitas/World.vala']
vala-emscripten_sources += ['src/entitas/entitas.vala']
vala-emscripten_sources += ['src/main.vala']
vala-emscripten_sources += ['src/sdx/Color.gs']
vala-emscripten_sources += ['src/sdx/Files.vala']
vala-emscripten_sources += ['src/sdx/Font.vala']
vala-emscripten_sources += ['src/sdx/files/FileHandle.vala']
vala-emscripten_sources += ['src/sdx/graphics/Sprite.vala']
vala-emscripten_sources += ['src/sdx/graphics/Surface.vala']
vala-emscripten_sources += ['src/sdx/graphics/TextureAtlas.vala']
vala-emscripten_sources += ['src/sdx/sdx.vala']
vala-emscripten_sources += ['src/systems/AnimationSystem.vala']
vala-emscripten_sources += ['src/systems/CollisionSystem.vala']
vala-emscripten_sources += ['src/systems/DisplaySystem.vala']
vala-emscripten_sources += ['src/systems/ExpireSystem.vala']
vala-emscripten_sources += ['src/systems/InputSystem.vala']
vala-emscripten_sources += ['src/systems/PhysicsSystem.vala']
vala-emscripten_sources += ['src/systems/RemoveSystem.vala']
vala-emscripten_sources += ['src/systems/ScoreSystem.vala']
vala-emscripten_sources += ['src/systems/SpawnSystem.vala']
vala-emscripten_sources += ['src/util/Cache.vala']
vala-emscripten_sources += ['src/util/File.vala']
vala-emscripten_sources += ['src/util/JsVariant.vala']
vala-emscripten_sources += ['src/util/Json.vala']
vala-emscripten_sources += ['src/util/String.vala']
vala-emscripten_sources += ['src/vala-emscripten.vala']
vala-emscripten_sources += [resources_gresource_xml_file_c]
vala-emscripten_sources += [join_paths(meson.current_source_dir(),'src/vapis/emscripten.vapi')]
vala-emscripten_sources += [join_paths(meson.current_source_dir(),'src/vapis/mt19937ar.vapi')]
vala-emscripten_sources += [join_paths(meson.current_source_dir(),'src/vapis/posix.vapi')]
vala-emscripten_vala_args = ['--vapidir='+join_paths(meson.current_source_dir(),'src/vapis')]
vala-emscripten_vala_args += ['--disable-warnings', '--cc=clang']
vala-emscripten_c_args = ['-g', '-Og']
if PROFILING
  vala-emscripten_vala_args += ['-D', 'PROFILING']
  vala-emscripten_c_args += ['-DPROFILING']
endif
if DESKTOP
  vala-emscripten_vala_args += ['-D', 'DESKTOP']
  vala-emscripten_c_args += ['-DDESKTOP']
endif
vala-emscripten_deps += [meson.get_compiler('c').find_library('m', required : false)]
vala-emscripten_hfolders = [include_directories('include')]

executable('vala-emscripten',vala-emscripten_sources,dependencies: vala-emscripten_deps,vala_args: vala-emscripten_vala_args,c_args: vala-emscripten_c_args,include_directories: vala-emscripten_hfolders,install: true)

