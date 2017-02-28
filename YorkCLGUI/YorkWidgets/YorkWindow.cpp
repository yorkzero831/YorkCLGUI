//
//  YorkWindow.cpp
//  YorkCLGUI
//
//  Created by coly30 on 2016/12/27.
//  Copyright © 2016年 Zero. All rights reserved.
//

#include "YorkWindow.h"
#include "YorkResourceManager.h"
#include "YorkWidgetsManager.h"

#include "YorkImageButton.h"

using namespace YorkManager;

namespace YorkWidget {
    
    YorkWindow::YorkWindow(ImVec2 pos, ImVec2 size, ImColor wbc, ImColor wmc)
    {
        _pos                = pos;
        _size               = size;
        _windowBgColor      = wbc;
        _windowMenuColor    = wmc;
    }

    
    void YorkWindow::SetTitile(std::string title)
    {
        _title = title;
    }
    
    void YorkWindow::AddWidget(YorkWidget::YorkWidgets *one)
    {
        _widgetsInWindow.push_back(one);
    }
    
    
    void YorkWindow::DrawView()
    {
        ImGui::SetNextWindowSize(_size);
        ImGui::SetNextWindowPos(_pos);
        bool opened = true;
        
        //Menu Color
        ImGui::PushStyleColor(ImGuiCol_MenuBarBg, _windowMenuColor);
        
        //Bg Color
        ImGui::PushStyleColor(ImGuiCol_WindowBg, _windowBgColor);
        
        // WindowStyle
        ImGuiWindowFlags window_flags = 0;
        window_flags |= ImGuiWindowFlags_NoTitleBar;
        window_flags |= ImGuiWindowFlags_ShowBorders;
        window_flags |= ImGuiWindowFlags_NoResize;
        window_flags |= ImGuiWindowFlags_NoMove;
        window_flags |= ImGuiWindowFlags_NoScrollbar;
        window_flags |= ImGuiWindowFlags_NoCollapse;
        window_flags |= ImGuiWindowFlags_MenuBar;
        window_flags |= ImGuiWindowFlags_ChildMenu;
        if (!ImGui::Begin("YorkView", &opened, window_flags))
        {
            ImGui::End();
            return;
        }
        
        //ImGui::Image(tex_id, ImVec2(tex_w, tex_h), ImVec2(0,0), ImVec2(1,1), ImColor(255,255,255,255), ImColor(255,255,255,128));
        
        ImGui::SameLine();
        ImGui::BeginGroup();
        
        
        ImDrawList* draw_list = ImGui::GetWindowDrawList();
        
        draw_list->ChannelsSplit(2);
        
        ImVec2 windowPos = ImGui::GetWindowPos();
        
        //bt1.DrawWidget(draw_list, windowPos);
        int64_t countOfWidgets = _widgetsInWindow.size();
        LOOP(countOfWidgets)
        {
            if(_widgetsInWindow.at(ii)->GetVisable())
                _widgetsInWindow.at(ii)->DrawWidget(draw_list, windowPos);
        }
        //YorkManager::YorkTextFieldManager::Instance()->FocusTextField();
        
        
        ImGui::EndGroup();
        ImGui::End();
        
        ImGui::PopStyleColor(2);
    }
    
    
    
    void YorkWindow::DrawWindow()
    {
        // Setup window
        //glfwSetErrorCallback(error_callback);
        if (!glfwInit())
            exit(1);
        
        
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
#if __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
       
        GLFWwindow* window = glfwCreateWindow(_size.x, _size.y, _title.c_str(), NULL, NULL);
        
        glfwMakeContextCurrent(window);
        gl3wInit();
        
        // Setup ImGui binding
        ImGui_ImplGlfwGL3_Init(window, true);
        
        
        ImVec4 clear_color = ImColor(255, 255, 255);

        YorkResourceManager::Instance()->BindImages();
        
        // Main loop
        while (!glfwWindowShouldClose(window))
        {
            
            ImGuiIO& io = ImGui::GetIO();
            glfwPollEvents();
            ImGui_ImplGlfwGL3_NewFrame();

            //
            DrawView();
            
            //
            
            
            // Rendering
            glViewport(0, 0, (int)io.DisplaySize.x, (int)io.DisplaySize.y);
            glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
            glClear(GL_COLOR_BUFFER_BIT);
            
            ImGui::Render();
            
            
            glfwSwapBuffers(window);
        }
        
//        // Cleanup
//        ImGui_ImplGlfwGL3_Shutdown();
//        glfwTerminate();
        
    }
    
    void YorkWindow::DrawWindow_multiThread()
    {
        runingThread = std::thread(&YorkWindow::DrawWindow,this);
        runingThread.detach();
    }
}



