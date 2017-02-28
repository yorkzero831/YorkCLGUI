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
        
        virtual void SetVisable(bool value);
        
        virtual void DrawWidget(ImDrawList* drawList, ImVec2 offset);
        
        void SetEnterKeyFunc();
        
        void SetValue(std::string value);
        std::string GetValue();
        
        long GetValueLength();
        
        void SetIsNumOnly(bool v){ _isNumOnly = v; }
        void SetIsReadOnly(bool v){ _isReadOnly = v; }
        
        bool GetIsNumOnly(){ return _isNumOnly; }
        bool GetIsReadOnly(){ return _isReadOnly; }
        
        void SetEnterKeyFunc(void (*DoEnterKey)(YorkWidgets*)){ _DoEnterKey = DoEnterKey; }
        
        void SetFocus();
        
        void DoEnterKey(){ if(_DoEnterKey != NULL) _DoEnterKey(this); }
        
    protected:
        char _context[512];
        bool _isNumOnly     = false;
        bool _isReadOnly    = false;
        bool _focusFlag     = false;
        int _maxCharPerLine = 0;
        
        
        void (*_DoEnterKey)(YorkWidgets*) = nullptr;
        
        int (*_CharFilter)(ImGuiTextEditCallbackData *data);
        
        
    };
}

