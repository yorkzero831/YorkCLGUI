//
//  YorkWindowsManager.cpp
//  YorkCLGUI
//
//  Created by coly30 on 2016/12/27.
//  Copyright © 2016年 Zero. All rights reserved.
//

#include "YorkWindowsManager.h"

#include "imgui_impl_glfw_gl3.h"
#include <GL/gl3w.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>

namespace YorkWidget {
    
    static void error_callback(int error, const char* description)
    {
        fprintf(stderr, "Error %d: %s\n", error, description);
    }
    
    YorkWindowManager::YorkWindowManager()
    {
        _windows = std::map<int, YorkWindow*>();
    }
    
    void YorkWindowManager::RegsitWindow(YorkWidget::YorkWindow* win)
    {
        _windows.insert(std::pair<int, YorkWindow*>(_windowID++, win));
    }
    
    void YorkWindowManager::UnregistWindow(YorkWidget::YorkWindow *win)
    {
        for(auto &one : _windows)
        {
            if(one.second == win)
            {
                _windows.erase(one.first);
                return;
            }
        }
    }
    
    void YorkWindowManager::SetMainWindow(YorkWidget::YorkWindow *win)
    {
        _mainWindow = win;
    }
    
    void YorkWindowManager::DrawWindows()
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
        _mainGLFWWinfow = glfwCreateWindow(_mainWindow->getSize().x, _mainWindow->getSize().y, _mainWindow->getTitle().c_str(), NULL, NULL);
        
        
        for(auto &one : _windows)
        {
            YorkWindow *thisWindow = one.second;
            //DrawOhterWindow(one.second);
            std::thread onethread = std::thread(&YorkWindowManager::DrawOhterWindow, this, thisWindow);
            onethread.detach();
        }
        
        DrawMainWindow(_mainWindow);
        
        // Cleanup
        ImGui_ImplGlfwGL3_Shutdown();
        glfwTerminate();
    }
    
    
    
    void YorkWindowManager::DrawMainWindow(YorkWidget::YorkWindow *one)
    {

    }
    
    void YorkWindowManager::DrawOhterWindow(YorkWidget::YorkWindow *one)
    {

    }
    
    
}

