//
//  YorkTextField.cpp
//  YorkCLGUI
//
//  Created by coly30 on 2017/01/04.
//  Copyright © 2017年 Zero. All rights reserved.
//

#include "YorkTextField.h"

namespace YorkWidget
{
    YorkTextField::YorkTextField(ImVec2 pos, ImVec2 size, std::string context)
    {
        _id      = widget_id++;
        _pos     = pos;
        _size    = size;
        
        std::strcpy(this->_context, context.c_str());
        //_context = context;
    }
    
    YorkTextField::~YorkTextField()
    {
        
    }
    
    void YorkTextField::DrawWidget(ImDrawList *drawList, ImVec2 offset)
    {
        ImGui::PushID(this->_id);
        
        ImGui::SetCursorScreenPos(this->_pos + offset);
        
        ImGui::PushStyleColor(ImGuiCol_Text, ImColor(0,0,0));
        
        if( ImGui::InputTextMultiline("", _context, 512, this->_size,   ImGuiInputTextFlags_CtrlEnterForNewLine|
                                                                        ImGuiInputTextFlags_EnterReturnsTrue|
                                                                        (_isNumOnly? ImGuiInputTextFlags_CharsDecimal : 0) |
                                                                        (_isReadOnly? ImGuiInputTextFlags_ReadOnly : 0)) )
        {
            printf("EnterKeyPressed");
            if(_DoEnterKey != nullptr)
                _DoEnterKey(this);
        }
        ImGui::PopStyleColor();
        
        ImGui::PopID();
        
    }
}
