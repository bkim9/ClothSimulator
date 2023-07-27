#include "imgui_impl_glfw.h"
#include <gtest/gtest.h>

TEST(ImGuiTests, whTest) {
    ImGui_ImplGlfw_Data* bd =  ImGui::GetCurrentContext() ? (ImGui_ImplGlfw_Data*)ImGui::GetIO().BackendPlatformUserData: nullptr;
    EXPECT_NE(nullptr, bd);
}
