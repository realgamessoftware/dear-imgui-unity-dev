// Compile time options for Dear ImGui for Unity

#pragma once
#include "plugin_custom_assert.h" // PluginLogAssert, PluginDebugBreak

// Define assertion handler

#ifdef NDEBUG // Uncomment to limit assertions to Debug builds
    #define _PLUGIN_ASSERT(expression) ((void)0)
#else
    #define _PLUGIN_ASSERT(expression) (void)(                                 \
        (!!(expression)) ||                                                    \
        (PluginLogAssert(#expression, __FILE__, __LINE__), 0)                  \
    )
#endif
#define IM_ASSERT(_EXPR) _PLUGIN_ASSERT(_EXPR)

// Macro to break in Debugger

#define IM_DEBUG_BREAK() PluginDebugBreak();
