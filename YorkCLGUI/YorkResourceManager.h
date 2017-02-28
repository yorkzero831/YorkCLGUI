//
//  YorkResourceManager.hpp
//  YorkCLGUI
//
//  Created by sakailabmacproA on 2017/1/16.
//  Copyright © 2017年 Zero. All rights reserved.
//


#pragma once
#include "YorkImage.h"
#include <vector>

#include <stdio.h>
#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

using namespace YorkWidget;



namespace YorkManager
{
    class YorkResourceManager
    {
    private:
        YorkResourceManager()
        {
            _YorkImageList = new std::vector<YorkImage*>();
        }
        
    protected:
        std::vector<YorkImage*>*_YorkImageList;
        
    public:
        
        static YorkResourceManager* Instance()
        {
            static YorkResourceManager* _instance = new YorkResourceManager();
            return _instance;
        }
        
        void AddImage(YorkImage *img);
        
        void BindImages();
        
        YorkImage* getImage(int num)
        {
            return _YorkImageList->at(num);
        }
        
    };
    
    static std::string GetCurrentPath()
    {
        char buff[FILENAME_MAX];
        GetCurrentDir( buff, FILENAME_MAX );
        std::string current_working_dir(buff);
        return current_working_dir;
    }
}
