//
//  YorkTextField.cpp
//  YorkCLGUI
//
//  Created by coly30 on 2017/01/04.
//  Copyright © 2017年 Zero. All rights reserved.
//

#include "YorkTextField.h"
#include "YorkWidgetsManager.h"

namespace YorkWidget
{
    int _CharFilterTemp(ImGuiTextEditCallbackData* data)
    {
        int c = (int)data->EventChar;
        YorkTextField *theOne = (YorkTextField*)data->UserData;
        
        //enter key pressed
        if(c == 10)
        {
            
            ((YorkTextField*)data->UserData)->DoEnterKey();
            data->EventChar = '\0';
            //return -1;
        }
        // tap key pressed
        if(c == 9)
        {
            return -1;
        }
        
        if(!data->ReadOnly)
        {
            if(theOne->GetIsNumOnly())
            {
                //if (!(c >= '0' && c <= '9') && (c != '.') && (c != '-') && (c != '+') && (c != '*') && (c != '/'))
                if(!(c >= '0' && c<= '9') && (c != ',' )) return -1;
                else if(c == ','){data->EventChar = '\n';}
            }
            
            
        }
        //YorkLog("key pressed\n");
        return 0;
    }
    YorkTextField::YorkTextField(ImVec2 pos, ImVec2 size, std::string context)
    {
        _id      = widget_id++;
        _pos     = pos;
        _size    = size;
        
        std::strcpy(this->_context, context.c_str());
        _CharFilter = _CharFilterTemp;
        
        YorkManager::YorkTextFieldManager::Instance()->Registe(this);
        
        SetVisable(true);
    
        //_context = context;
    }
    
    YorkTextField::~YorkTextField()
    {
        
    }
    
    void YorkTextField::SetVisable(bool value)
    {
        if(_visable != value)
        {
            _visable = value;
            if(_visable) YorkManager::YorkTextFieldManager::Instance()->RegisteShowed(this);
            else         YorkManager::YorkTextFieldManager::Instance()->UnRegisteShowed(this);
        }
        
    }
    
    void YorkTextField::SetValue(std::string value)
    {
        std::strcpy(this->_context, value.c_str());
    }
    
    std::string YorkTextField::GetValue()
    {
        return this->_context;
    }
    
    long YorkTextField::GetValueLength()
    {
        return std::strlen(_context);
    }
    
    void YorkTextField::SetFocus()
    {
        _focusFlag = true;
        //YorkManager::YorkTextFieldManager::Instance()->SetFocus(this);
    }

    
    
    void YorkTextField::DrawWidget(ImDrawList *drawList, ImVec2 offset)
    {
        ImGui::PushID((int)this->_id);
        
        ImGui::SetCursorScreenPos(this->_pos + offset);
        
        ImGui::PushStyleColor(ImGuiCol_ScrollbarBg, ImColor(0,0,0,0));
        ImGui::PushStyleColor(ImGuiCol_ScrollbarGrab, ImColor(200,200,200,25));
        ImGui::PushStyleColor(ImGuiCol_ScrollbarGrabHovered, ImColor(200,200,200,150));
        ImGui::PushStyleColor(ImGuiCol_ScrollbarGrabActive, ImColor(200,200,200,200));
        ImGui::PushStyleColor(ImGuiCol_Border, ImColor(100,100,100));
        
        ImGui::PushStyleColor(ImGuiCol_Text, ImColor(0,0,0));
        
        
        
        
        
        if( ImGui::InputTextMultiline("", _context, 512, this->_size,   ImGuiInputTextFlags_CallbackCharFilter|
                                                                        /*ImGuiInputTextFlags_CallbackAlways|*/
                                                                        (_isReadOnly? ImGuiInputTextFlags_ReadOnly : 0),
                                                                        _CharFilter,this ) )
        {
            //YorkLog("test\n");
//            if(_DoEnterKey != nullptr)
//                _DoEnterKey(this);
            
        }
        
        
        
        ImGui::PopStyleColor(6);
        
        ImGui::PopID();
        
        if(_focusFlag)
        {
            int tfID = YorkManager::YorkTextFieldManager::Instance()->GetTheID_Offset2(this) ;
            YorkLog("ID:%d\n", tfID );
            ImGui::SetKeyboardFocusHere(tfID);
            _focusFlag = !_focusFlag;
        }
        
    }
}
