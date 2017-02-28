//
//  YorkImage.hpp
//  YorkCLGUI
//
//  Created by coly30 on 2017/01/04.
//  Copyright © 2017年 Zero. All rights reserved.
//

#pragma once

#include "YorkWidgets.h"

#include <Add_in/SOIL/SOIL.h>
#include <GLFW/glfw3.h>

namespace YorkWidget
{
    class YorkImage
    {
    public:
        YorkImage();
        YorkImage(std::string filePath);
        int width;
        int height;
        int channels;
        bool LoadImageFromFile(std::string filePath);
        
        unsigned char* GetImageData();
        
        void BindImage();
        
        GLuint GetImageID();
        
        void SetImageID(const GLuint idV);
        
    protected:
        unsigned char *_imageData;
        
    private:
        GLuint _texID = 0;
    };
}


