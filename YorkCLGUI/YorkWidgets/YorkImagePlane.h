//
//  YorkImagePlane.hpp
//  YorkCLGUI
//
//  Created by sakailabmacproA on 2017/1/17.
//  Copyright © 2017年 Zero. All rights reserved.
//

#pragma once
#include "YorkWidgets.h"
#include "YorkImage.h"
namespace YorkWidget
{
    class YorkImagePlane : public YorkWidgets
    {
    public:
        
        YorkImagePlane();
        YorkImagePlane(ImVec2 position, ImVec2 size, YorkImage *img);
        
        virtual void DrawWidget(ImDrawList* drawList, ImVec2 offset);
    protected:
        YorkImage *_img;
    };
}
