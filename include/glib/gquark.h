#define GQuark uintptr_t
#define g_quark_from_static_string(x) ((GQuark)(size_t)(x))
