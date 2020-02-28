#ifndef CIMGUI_FREETYPE
#define CIMGUI_FREETYPE
#if defined _WIN32 || defined __CYGWIN__
    #ifdef CIMGUI_FREETYPE_NO_EXPORT
        #define API
    #else
        #define API __declspec(dllexport)
    #endif
    #ifndef __GNUC__
        #define snprintf sprintf_s
    #endif
#else
    #define API
#endif

#if defined __cplusplus
    #define EXTERN extern "C"
#else
    #include <stdarg.h>
    #include <stdbool.h>
    #define EXTERN extern
#endif

#define CFREETYPE_API EXTERN API
#define CONST const


#ifdef _MSC_VER
typedef unsigned __int64 ImU64;
#else
//typedef unsigned long long ImU64;
#endif

struct ImFontAtlas;

CFREETYPE_API bool frBuildFontAtlas(ImFontAtlas* atlas, unsigned int extra_flags);

#endif // CIMGUI_FREETYPE
