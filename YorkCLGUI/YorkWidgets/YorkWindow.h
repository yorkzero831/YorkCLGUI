//
//  Header.h
//  YorkCLGUI
//
//  Created by coly30 on 2016/12/27.
//  Copyright © 2016年 Zero. All rights reserved.
//

#pragma once

#include "YorkDefine.h"
#include "YorkWidgets.h"
#include <thread>

#include "imgui_impl_glfw_gl3.h"
#include <GL/gl3w.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>


namespace YorkWidget {
    
    class YorkWindow
    {
    public:
        YorkWindow(ImVec2 pos = ImVec2(0,0),
                   ImVec2 size = ImVec2(500,320),
                   ImColor wbc = ImColor(255,255,255),
                   ImColor wmc = ImColor(69,184,209,255));
        
        void SetTitile(std::string title = "window");
        
        virtual void DrawWindow();
        
        virtual void DrawView();
        
        void DrawWindow_multiThread();
        
        void AddWidget(YorkWidgets* one);
        
        ImVec2 getSize(){ return _size; };
        
        ImVec2 getPosition(){ return _pos; };
        
        std::string getTitle(){ return _title; };
        
    protected:
        ImVec2  _pos;
        ImVec2  _size;
        ImColor _windowBgColor;
        ImColor _windowMenuColor;
        std::string _title;
        std::vector<YorkWidgets*> _widgetsInWindow = std::vector<YorkWidgets*>();
        
        GLFWwindow *_window;
        
        std::thread runingThread;
        
        
        
    };
}
