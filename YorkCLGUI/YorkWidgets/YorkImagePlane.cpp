//
//  YorkImagePlane.cpp
//  YorkCLGUI
//
//  Created by sakailabmacproA on 2017/1/17.
//  Copyright © 2017年 Zero. All rights reserved.
//

#include "YorkImagePlane.h"

namespace YorkWidget
{
    YorkImagePlane::YorkImagePlane()
    {
        _id      = widget_id++;
    }
    
    YorkImagePlane::YorkImagePlane(ImVec2 position, ImVec2 size, YorkImage *img)
    {
        _id      = widget_id++;
        _pos = position;
        _size = size;
        _img = img;
        
    }
    
    void YorkImagePlane::DrawWidget(ImDrawList *drawList, ImVec2 offset)
    {
        ImGui::PushID((int)this->_id);
        
        ImGui::SetCursorScreenPos(_pos);
        ImGui::Image((void*)_img->GetImageID(), _size);
        
        ImGui::PopID();
    }
}
