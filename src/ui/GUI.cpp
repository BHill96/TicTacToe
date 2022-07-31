#include "ui/GUI.h"
// #include "../lib/imgui/imgui.h"
// #include "../lib/imgui/imgui_impl_glfw.h"
// #include "../lib/imgui/imgui_impl_opengl3.h"
// #include <GLFW/glfw3.h>

// static void glfw_error_callback(int error, const char* description)
// {
//     fprintf(stderr, "Glfw Error %d: %s\n", error, description);
// }

// void GUI::SetUp() {
//     glfwSetErrorCallback(glfw_error_callback);
//     if (!glfwInit()) {
//         throw;
//     }

//     // GL 3.2 + GLSL 150
//     const char* glsl_version = "#version 150";
//     glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//     glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
//     glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
//     glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // Required on Mac

//     // Create window with graphics context
//     GLFWwindow* window = glfwCreateWindow(1280, 720, "Dear ImGui GLFW+OpenGL3 example", NULL, NULL);
//     if (window == NULL) {
//         throw;
//     }
//     glfwMakeContextCurrent(window);
//     glfwSwapInterval(1); // Enable vsync

//     // Setup Dear ImGui context
//     IMGUI_CHECKVERSION();
//     ImGui::CreateContext();
//     ImGuiIO& io = ImGui::GetIO(); (void)io;

//     // Setup Dear ImGui style
//     ImGui::StyleColorsDark();

//     // Setup Platform/Renderer backends
//     ImGui_ImplGlfw_InitForOpenGL(window, true);
//     ImGui_ImplOpenGL3_Init(glsl_version);

//     // Our state
//     // bool show_demo_window = true;
//     // bool show_another_window = false;
//     // ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
// }

GameSettings GUI::DisplayGameOptions() {
    GameSettings settings;
    return settings;
}

void GUI::DisplayGameResults(GameResults gameResults) {

}