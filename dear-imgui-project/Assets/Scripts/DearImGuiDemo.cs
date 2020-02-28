using UnityEngine;
using ImGuiNET;
using ImGuiNET.Unity;

public class DearImGuiDemo : MonoBehaviour
{
    void OnEnable()
    {
        ImGuiUn.OnLayout += Layout;
    }

    void OnDisable()
    {
        ImGuiUn.OnLayout -= Layout;
    }

    void Layout()
    {
        ImGui.ShowDemoWindow();
    }
}
