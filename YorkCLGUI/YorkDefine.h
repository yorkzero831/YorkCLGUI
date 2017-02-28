//
//  YorkDefine.h
//  YorkCLGUI
//
//  Created by coly30 on 2016/12/27.
//  Copyright © 2016年 Zero. All rights reserved.
//

#pragma once

#define LOOP(n) for(long ii = 0; ii < n; ++ ii)

#define IS_DUBEG 1;

#include <stdio.h>
#include <string>


namespace YorkWidget
{
    static inline void YorkLog(const std::string &ins)
    {
#ifdef IS_DUBEG
        printf("%s", ins.c_str());
#endif
    }
    static inline void YorkLog(const char* ins , ...)
    {
#ifdef IS_DUBEG
        va_list args;
        va_start(args, ins);
        vprintf(ins, args);
        va_end(args);
#endif
    }
    
    
    
}
