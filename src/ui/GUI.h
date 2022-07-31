#pragma once

#include "interfaces/IUI.h"

#include "../lib/imgui/imgui.h"
#include "../lib/imgui/imgui_impl_glfw.h"
#include "../lib/imgui/imgui_impl_opengl3.h"
#include <GLFW/glfw3.h>

class GUI : public IUI {
    private:
        GLFWwindow* window = NULL;

    public:
        ~GUI() = default;
        void SetUp() override;
        void CheckWindowForChanges() override;
        void DrawDemoWindow() override;
        bool WindowOpen() override;
        GameSettings DisplayGameOptions() override;
        void DisplayGameResults(GameResults) override;
        void Render() override;
        void Cleanup() override;
};