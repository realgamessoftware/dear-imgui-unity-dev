using UnityEngine;
using ImGuiNET;

public class DearImGuiDemo : MonoBehaviour
{
    void OnEnable()
    {
        ImGuiUn.Layout += OnLayout;
    }

    void OnDisable()
    {
        ImGuiUn.Layout -= OnLayout;
    }

    void OnLayout()
    {
        ImGui.ShowDemoWindow();
    }
}
