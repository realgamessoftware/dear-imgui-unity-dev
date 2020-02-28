#include "imgui.h"
#include "plugin_custom_assert.h"

struct CustomAssertData
{
    void (*LogAssertFn)(const char* condition, const char* file, int line);
    void (*DebugBreakFn)(void);
};

CustomAssertData& GetCustomAssertData()
{
    ImGuiIO& io = ImGui::GetIO();
    if (io.BackendPlatformUserData == NULL)
        io.BackendPlatformUserData = new CustomAssertData();
    return *(CustomAssertData*)io.BackendPlatformUserData;
}

PLUGIN_API void PluginLogAssert(const char* condition, const char* file, int line)
{
    GetCustomAssertData().LogAssertFn(condition, file, line);
}

PLUGIN_API void PluginDebugBreak()
{
    GetCustomAssertData().DebugBreakFn();
}
