#include "cimgui_freetype.h"
#include "imgui_freetype.h"

using namespace ImGuiFreeType;

CFREETYPE_API bool frBuildFontAtlas(ImFontAtlas* atlas, unsigned int extra_flags)
{
    return BuildFontAtlas(atlas, extra_flags);
}
