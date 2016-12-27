//
//  YorkWindowsManager.h
//  YorkCLGUI
//
//  Created by coly30 on 2016/12/27.
//  Copyright © 2016年 Zero. All rights reserved.
//

#pragma once

#include "YorkWindow.h"

namespace YorkWidget {
    
    static int _windowID = 0;
    static std::map<int, YorkWindow*> _windows = std::map<int, YorkWindow*>();
    static YorkWindow* _mainWindow = NULL;
    static GLFWwindow* _mainGLFWWinfow = NULL;
    class YorkWindowManager
    {
    public:
        YorkWindowManager();
        void RegsitWindow(YorkWindow* win);
        void UnregistWindow(YorkWindow* win);
        
        void DrawWindows();
        
        void SetMainWindow(YorkWindow* win);
        
    protected:
        
    private:
        void DrawMainWindow(YorkWindow *one);
        
        void DrawOhterWindow(YorkWindow *one);
        
    };
    
    static YorkWindowManager WindowManager;
    
    
    
}

