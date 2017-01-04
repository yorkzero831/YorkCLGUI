//
//  YorkTextField.hpp
//  YorkCLGUI
//
//  Created by coly30 on 2017/01/04.
//  Copyright © 2017年 Zero. All rights reserved.
//

#pragma once

#include "YorkWidgets.h"

namespace YorkWidget
{
    class YorkTextField: public YorkWidgets
    {
    public:
        YorkTextField(ImVec2 pos, ImVec2 size, std::string context = "");
        ~YorkTextField();
        
        virtual void DrawWidget(ImDrawList* drawList, ImVec2 offset);
        
        void SetEnterKeyFunc();
        
        void SetValue(std::string value);
        
        void SetIsNumOnly(bool v){ _isNumOnly = v; }
        void SetIsReadOnly(bool v){ _isReadOnly = v; }
        
        bool GetIsNumOnly(){ return _isNumOnly; }
        bool GetIsReadOnly(){ return _isReadOnly; }
        
        void SetEnterKeyFunc(void (*DoEnterKey)(YorkWidgets*)){ _DoEnterKey = DoEnterKey; }
        
    protected:
        char _context[512];
        bool _isNumOnly = false;
        bool _isReadOnly = false;
        
        void (*_DoEnterKey)(YorkWidgets*) = nullptr;
    };
}

