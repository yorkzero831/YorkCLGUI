//
//  YorkImageButton.cpp
//  YorkCLGUI
//
//  Created by sakailabmacproA on 2017/1/16.
//  Copyright © 2017年 Zero. All rights reserved.
//

#include "YorkImageButton.h"
namespace YorkWidget
{
    YorkImageButton::YorkImageButton()
    {
        _id      = widget_id++;
    }
    
    YorkImageButton::YorkImageButton(const ImVec2 position, const ImVec2 size, YorkImage *img)
    {
        _id      = widget_id++;
        _pos = position;
        _size = size;
        _img = img;
    }
    
    void YorkImageButton::SetImg(YorkWidget::YorkImage *img)
    {
        _img = img;
    }
    
    void YorkImageButton::SetClickedFunc(void (*DoClick)(YorkWidget::YorkWidgets *))
    {
        _DoClick = DoClick;
    }
    
    void YorkImageButton::DrawWidget(ImDrawList *drawList, ImVec2 offset)
    {
        ImGui::PushID((int)this->_id);
        
        ImVec2 pos = _pos + offset;
        ImGui::SetCursorScreenPos(pos);
        ImVec2 ImgPos = pos;
        if(ImGui::InvisibleButton("ImgButton", _size))
        {
            if(_DoClick!=NULL)
            {
                _DoClick(this);
            }
            ImgPos = ImgPos + ImVec2(_size.x/20, _size.y/20);
        }
        ImGui::SetCursorScreenPos(ImgPos);
        ImGui::Image((void*)_img->GetImageID(), _size);
        
        ImGui::PopID();
        
    }
    
    
}
