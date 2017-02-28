//
//  YorkWidgetsManager.h
//  YorkCLGUI
//
//  Created by sakailabmacproA on 2017/1/17.
//  Copyright © 2017年 Zero. All rights reserved.
//

#pragma once

#include "YorkWindow.h"
#include "YorkButton.h"
#include "YorkTextField.h"
#include "YorkImage.h"
#include "YorkImageButton.h"
#include "YorkImagePlane.h"


#include "YorkResourceManager.h"

#include <Add_in/rapidjson/document.h>
#include <Add_in/rapidjson/writer.h>
#include <Add_in/rapidjson/stringbuffer.h>

namespace YorkManager
{
    class YorkWidgetManager
    {
        
    };
    
    class YorkTextFieldManager
    {
    public:
        void Registe(YorkTextField* one)
        {
            this->textFields->push_back(one);
        }
        
        void RegisteShowed(YorkTextField* one)
        {
            //this->showedTextFields->push_back(one);
        }
        void UnRegisteShowed(YorkTextField* one)
        {
            /*
            std::vector<YorkTextField*>::iterator itor;
            for(itor = showedTextFields->begin(); itor != showedTextFields->end(); itor++)
            {
                if(*itor == one)
                {
                    showedTextFields->erase(itor);
                    return;
                }
            }
             */
        }
        
        int GetTheID_Offset(YorkTextField* one)
        {
            //std::vector<YorkTextField*>showedTextField = std::vector<YorkTextField*>();
            long count = showedTextFields->size();
            
            int outPutOffset = -1;
            int counter = -1;
            //Get the showed TextFields list
            LOOP(count)
            {
                YorkTextField* tempOne = showedTextFields->at(ii);
                if(tempOne->GetVisable())
                {
                    counter ++;
                    if(tempOne == one) outPutOffset = counter;
                    //showedTextField.push_back(tempOne);
                }
            }
            
            //int showedTextFieldCount = counter - outPutOffset;
            if(counter >= 1)
            {
                if(outPutOffset == 0)
                    outPutOffset = 0;
            }
            
            return outPutOffset;
        }
        
        int GetTheID_Offset2(YorkTextField* one)
        {
            std::vector<YorkTextField*>showedTextField = std::vector<YorkTextField*>();
            long count = textFields->size();
            LOOP(count)
            {
                YorkTextField* tempOne = textFields->at(ii);
                if(tempOne->GetVisable())
                {
                    showedTextField.push_back(tempOne);
                }
            }
            
            int outPutOffset = -1;
            count = showedTextField.size();
            LOOP(count)
            {
                YorkTextField* tempOne = showedTextField.at(ii);
                if(tempOne == one) outPutOffset = (int)ii;
            }
            
            return outPutOffset;
        }
        
        long GetTextFiledsCount()
        {
            return textFields->size();
        }
        
        static YorkTextFieldManager* Instance()
        {
            static YorkTextFieldManager* _instance = new YorkTextFieldManager();
            return _instance;
        }
        
        void SetFocus(YorkTextField* ins)
        {
            _nextFocusOne = ins;
        }
        
        void FocusTextField()
        {
            if(_nextFocusOne == NULL) return;
            
            std::vector<YorkTextField*>showedTextField = std::vector<YorkTextField*>();
            long count = textFields->size();
            int index = -1;
            LOOP(count)
            {
                YorkTextField* tempOne = textFields->at(ii);
                if(tempOne->GetVisable())
                {
                    index++;
                    if(tempOne == _nextFocusOne)
                    {
                        YorkLog("ID::::%d\n",index);
                        ImGui::SetKeyboardFocusHere(++index);
                        _nextFocusOne = NULL;
                        return;
                    }
                }
            }
        }
        
    protected:
        std::vector<YorkTextField*> *textFields;
        std::vector<YorkTextField*> *showedTextFields;
        YorkTextField *_nextFocusOne = NULL;
        YorkTextFieldManager()
        {
            textFields       = new std::vector<YorkTextField*>();
            showedTextFields = new std::vector<YorkTextField*>();
        }
        
    };
}




//// 1. 把 JSON 解析至 DOM。
//const char* json = "{\"project\":\"rapidjson\",\"stars\":10}";
//Document d;
//d.Parse(json);
//// 2. 利用 DOM 作出修改。
//Value& s = d["stars"];
//s.SetInt(s.GetInt() + 1);
//// 3. 把 DOM 转换（stringify）成 JSON。
//StringBuffer buffer;
//Writer<StringBuffer> writer(buffer);
//d.Accept(writer);
