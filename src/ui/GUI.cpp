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
    
    const float indent = 79.5;
    int width = 10+fontSize*48;
    int height = 10+fontSize*12;
    static char playerOneName [256] = "Name";
    static char playerTwoName [256] = "Name";
    std::vector<std::string> playerTypes = {"Human","AI"};
    static int playerOneIndex = 0;
    static int playerTwoIndex = 0;

    ImGui::SetNextWindowSize(ImVec2(width, height));
    ImGui::SetNextWindowPos(ImVec2(0.53*windowWidth,0.01*windowHeight));
    ImGuiWindowFlags flags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse;
    ImGui::Begin("Settings",NULL,flags);
    ImGui::Text("Player 1: ");
    ImGui::SameLine();
    ImGui::InputText("Player One Name", playerOneName, IM_ARRAYSIZE(playerOneName));
    ImGui::Indent(indent);
    const char* playerOneType = playerTypes[playerOneIndex].c_str();
    if (ImGui::BeginCombo("Player One Type", playerOneType)) {
        for (int i = 0; i < playerTypes.size(); i++) {
            bool selected = (playerOneType == playerTypes[i].c_str());
            if (ImGui::Selectable(playerTypes[i].c_str(), selected)) {
                playerOneType = playerTypes[i].c_str();
                playerOneIndex = i;
            }
            if (selected) {
                ImGui::SetItemDefaultFocus();
            }
        }
        ImGui::EndCombo();
    };
    ImGui::Unindent(indent);
    ImGui::Text("Player 2: ");
    ImGui::SameLine();
    ImGui::InputText("Player Two Name", playerTwoName, IM_ARRAYSIZE(playerTwoName));
    ImGui::Indent(indent);
    const char* playerTwoType = playerTypes[playerTwoIndex].c_str();
    if (ImGui::BeginCombo("Player Two Type", playerTwoType)) {
        for (int i = 0; i < playerTypes.size(); i++) {
            bool selected = (playerTwoType == playerTypes[i].c_str());
            if (ImGui::Selectable(playerTypes[i].c_str(), selected)) {
                playerTwoType = playerTypes[i].c_str();
                playerTwoIndex = i;
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

std::unique_ptr<Move> GUI::DisplayInteractiveBoard(std::shared_ptr<IBoard>) {
    
}