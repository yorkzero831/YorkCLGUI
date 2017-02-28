//
//  YorkImage.cpp
//  YorkCLGUI
//
//  Created by coly30 on 2017/01/04.
//  Copyright © 2017年 Zero. All rights reserved.
//

#include "YorkImage.h"
#include <iostream>
#include <fstream>
#include "YorkResourceManager.h"

using namespace YorkManager;

namespace YorkWidget
{
    YorkImage::YorkImage()
    {
        //YorkResourceManager::AddImage(this);
        YorkResourceManager::Instance()->AddImage(this);
    }
    
    YorkImage::YorkImage(std::string filePath)
    {
        YorkResourceManager::Instance()->AddImage(this);
        LoadImageFromFile(filePath);
    }
    
    bool YorkImage::LoadImageFromFile(std::string filePath)
    {
        width = 0;
        height = 0;
        channels = 0;
        
        _imageData = nullptr;
        //glGenTextures(1, &tex);
        //glActiveTexture(GL_TEXTURE0);
        //glGenTextures(GL_TEXTURE_2D, id);
        //const unsigned char* data  = loadFile(filePath.c_str(), size);
        _imageData = SOIL_load_image(filePath.c_str(), &width, &height, &channels, SOIL_LOAD_AUTO);
        
        //glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageData);
        
        //SOIL_free_image_data(imageData);
        if(_imageData != 0) return true;
        else return false;
    }
    
    unsigned char* YorkImage::GetImageData()
    {
        return _imageData;
    }
    
    void YorkImage::BindImage()
    {
        GLuint texID;
        glGenTextures(1, &texID);
        glBindTexture(GL_TEXTURE_2D, texID);
        
        _texID = texID;
        
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, _imageData);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

        SOIL_free_image_data(_imageData);
    }
    
    GLuint YorkImage::GetImageID()
    {
        return _texID;
    }
    
    void YorkImage::SetImageID(const GLuint idV)
    {
        _texID = idV;
    }
    
}

