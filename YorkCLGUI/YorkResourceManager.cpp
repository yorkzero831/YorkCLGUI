//
//  YorkResourceManager.cpp
//  YorkCLGUI
//
//  Created by sakailabmacproA on 2017/1/16.
//  Copyright © 2017年 Zero. All rights reserved.
//

#include "YorkResourceManager.h"

namespace YorkManager
{
    
    void YorkResourceManager::AddImage(YorkWidget::YorkImage *img)
    {
        _YorkImageList->push_back(img);
    }
    
    void YorkResourceManager::BindImages()
    {
        int64_t size = _YorkImageList->size();
        for (int i = 0; i < size; i++)
        {
            //_YorkImageList->at(i)->BindImage();
            YorkImage *thisOne = _YorkImageList->at(i);
            GLuint texID;
            glGenTextures(1, &texID);
            glBindTexture(GL_TEXTURE_2D, texID);
            
            thisOne->SetImageID(texID);
            
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, thisOne->width, thisOne->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, thisOne->GetImageData());
            glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
            
            SOIL_free_image_data(thisOne->GetImageData());
        }
    }
}
