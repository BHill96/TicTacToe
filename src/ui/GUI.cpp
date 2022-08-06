#include "ui/GUI.h"
#include <iostream>
#include <vector>

static void glfw_error_callback(int error, const char* description)
{
    fprintf(stderr, "Glfw Error %d: %s\n", error, description);
}

void GUI::SetUp() {
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit()) {
        throw;
    }

    // GL 3.2 + GLSL 150
    const char* glsl_version = "#version 150";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // Required on Mac

    // Create window with graphics context
    window = glfwCreateWindow(windowWidth, windowHeight, "Tic Tac Toe", NULL, NULL);
    if (window == NULL) {
        throw;
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);
}

void GUI::CheckWindowForChanges() {
    glfwPollEvents();
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

void GUI::DrawDemoWindow() {
    ImGui::SetNextWindowPos(ImVec2(650, 650), ImGuiCond_FirstUseEver);
    ImGui::ShowDemoWindow();
}

bool GUI::WindowOpen() {
    return !glfwWindowShouldClose(window);
}

// TODO: It seems the label can actually tether two different ImGui elements
//   together. I don't want to have some elements labeled as double spaces,
//   gotta find a way around this. Can I hide the label of input boxes?
GameSettings GUI::DisplayGameOptions() {
    GameSettings settings;

    int width = 10+fontSize*48;
    int height = 10+fontSize*12;
    static char name0 [256] = "Player 1";
    static char name1 [256] = "Player 2";
    std::vector<std::string> playerTypes = {"Human","AI"};
    static int index0 = 0;
    static int index1 = 0;

    ImGui::SetNextWindowSize(ImVec2(width, height));
    ImGui::SetNextWindowPos(ImVec2(0.5*windowWidth,0.01*windowHeight));
    ImGuiWindowFlags flags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse;
    ImGui::Begin("Settings",NULL,flags);
    ImGui::Text("Name: ");
    ImGui::SameLine();
    ImGui::InputText(" ", name0, IM_ARRAYSIZE(name0));
    ImGui::SameLine();
    const char* playerType0 = playerTypes[index0].c_str();
    if (ImGui::BeginCombo("Player 1 Type", playerType0)) {
        for (int i = 0; i < playerTypes.size(); i++) {
            bool selected = (playerType0 == playerTypes[i].c_str());
            if (ImGui::Selectable(playerTypes[i].c_str(), selected)) {
                playerType0 = playerTypes[i].c_str();
                index0 = i;
            }
            if (selected) {
                ImGui::SetItemDefaultFocus();
            }
        }
        ImGui::EndCombo();
    };
    ImGui::Text("Name: ");
    ImGui::SameLine();
    ImGui::InputText("  ", name1, IM_ARRAYSIZE(name1));
    ImGui::SameLine();
    const char* playerType1 = playerTypes[index1].c_str();
    if (ImGui::BeginCombo("Player 2 Type", playerType1)) {
        for (int i = 0; i < playerTypes.size(); i++) {
            bool selected = (playerType1 == playerTypes[i].c_str());
            if (ImGui::Selectable(playerTypes[i].c_str(), selected)) {
                playerType1 = playerTypes[i].c_str();
                index1 = i;
            }
            if (selected) {
                ImGui::SetItemDefaultFocus();
            }
        }
        ImGui::EndCombo();
    };
    if (ImGui::Button("Start Game!")) {
        // Eventually create players
        settings = GameSettings();
    } else {
        settings = GameSettings();
    }
    ImGui::End();

    return settings;
}

void GUI::DisplayGameResults(GameStatus gameStatus) {

}

void GUI::Render() {
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    ImGui::Render();
    int display_w, display_h;
    glfwGetFramebufferSize(window, &display_w, &display_h);
    glViewport(0, 0, display_w, display_h);
    glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    glfwMakeContextCurrent(window);
    glfwSwapBuffers(window);
}

void GUI::Cleanup() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();
}