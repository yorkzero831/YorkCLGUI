//
//  YorkImageButton.hpp
//  YorkCLGUI
//
//  Created by sakailabmacproA on 2017/1/16.
//  Copyright © 2017年 Zero. All rights reserved.
//

#pragma once

#include "YorkWidgets.h"
#include "YorkImage.h"
namespace YorkWidget
{
    class YorkImageButton:public YorkWidgets
    {
    public:
        YorkImageButton();
        YorkImageButton(const ImVec2 position, const ImVec2 size, YorkImage *img);
        
        void SetImg(YorkImage *img);
        
        void SetClickedFunc(void (*DoClick)(YorkWidgets*));
        
        virtual void DrawWidget(ImDrawList* drawList, ImVec2 offset);
        
    protected:
        YorkImage* _img;
        void (*_DoClick)(YorkWidgets*) = nullptr;
        
        
    };
}
