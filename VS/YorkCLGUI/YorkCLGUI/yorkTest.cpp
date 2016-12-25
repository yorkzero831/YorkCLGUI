

#include "YorkButton.h"

#include "imgui_impl_glfw_gl3.h"
#include <GL/gl3w.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>

using namespace YorkWidget;

static void error_callback(int error, const char* description)
{
	fprintf(stderr, "Error %d: %s\n", error, description);
}

YorkButton bt1 = YorkButton(ImVec2(0, 0), ImVec2(100, 100), "AAAAAAAA");

void showYorkTest()
{	
	int wX, wY;
	glfwGetWindowSize(glfwGetCurrentContext(), &wX, &wY);;
	
	ImGui::SetNextWindowSize(ImVec2(wX, wY));
	ImGui::SetNextWindowPos(ImVec2(0, 0));
	bool opened = true;
	ImGuiWindowFlags window_flags = 0;
	window_flags |= ImGuiWindowFlags_NoTitleBar;
	window_flags |= ImGuiWindowFlags_ShowBorders;
	window_flags |= ImGuiWindowFlags_NoResize;
	window_flags |= ImGuiWindowFlags_NoMove;
	window_flags |= ImGuiWindowFlags_NoScrollbar;
	window_flags |= ImGuiWindowFlags_NoCollapse;
	window_flags |= ImGuiWindowFlags_MenuBar;
	if (!ImGui::Begin("YorkNodeGraph", &opened, window_flags))
	{
		ImGui::End();
		return;
	}

	ImGui::SameLine();
	ImGui::BeginGroup();

	ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(1, 1));
	ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));
	ImGui::PushStyleColor(ImGuiCol_ChildWindowBg, ImColor(40, 40, 40, 200));

	ImGui::BeginChild("scrolling_region", ImVec2(0, 0), true, ImGuiWindowFlags_NoMove);
	ImGui::PushItemWidth(120.0f);

	ImDrawList* draw_list = ImGui::GetWindowDrawList();
	draw_list->ChannelsSplit(2);

	ImVec2 windowPos = ImGui::GetWindowPos();

	//printf_s("x:%f y:%f \n",windowPos.x, windowPos.y);

	bt1.DrawWidget(draw_list, windowPos);


	ImGui::PopItemWidth();
	ImGui::EndChild();
	ImGui::PopStyleColor();
	ImGui::PopStyleVar(2);
	ImGui::EndGroup();

	ImGui::End();

}

int main(int, char**)
{

	// Setup window
	glfwSetErrorCallback(error_callback);
	if (!glfwInit())
		exit(1);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
#if __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
	GLFWwindow* window = glfwCreateWindow(500, 320, "York Test", NULL, NULL);

	glfwMakeContextCurrent(window);
	gl3wInit();

	// Setup ImGui binding
	ImGui_ImplGlfwGL3_Init(window, true);

	/*
	s_emitter = createNodeFromName(ImVec2(500.0f, 100.0f), "Emitter");
	s_emittable = createNodeFromName(ImVec2(500.0f, 300.0f), "Emittable");
	s_quad = createNodeFromName(ImVec2(500.0f, 600.0f), "Quad");
	*/

	bool show_test_window = true;
	//bool show_another_window = false;
	ImVec4 clear_color = ImColor(114, 144, 154);

	// Main loop
	while (!glfwWindowShouldClose(window))
	{
		ImGuiIO& io = ImGui::GetIO();
		glfwPollEvents();
		ImGui_ImplGlfwGL3_NewFrame();

		//ImGui::Text("WWWW");

		//ShowExampleAppCustomNodeGraph(&show_test_window);
		showYorkTest();

		// Rendering
		glViewport(0, 0, (int)io.DisplaySize.x, (int)io.DisplaySize.y);
		glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
		glClear(GL_COLOR_BUFFER_BIT);
		ImGui::Render();
		glfwSwapBuffers(window);
	}

	// Cleanup
	ImGui_ImplGlfwGL3_Shutdown();
	glfwTerminate();

	return 0;
}

#ifdef _WIN32

int CALLBACK WinMain(
	_In_  HINSTANCE hInstance,
	_In_  HINSTANCE hPrevInstance,
	_In_  LPSTR lpCmdLine,
	_In_  int nCmdShow)
{
	return main(0, 0);
}

#endif