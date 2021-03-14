#include "stm32746g_discovery_lcd.h"
#include <cstdint>
#include <stdio.h>

#pragma once
class Widget
{
    public:
        //Widget();
        //virtual ~Widget();
        virtual void show(){printf("Widget");};
        virtual void push(){};
        virtual void release(){};
        virtual bool pointInObject(uint32_t p_x,uint32_t p_y){return false;};
        virtual void connect(void (*function)()){};
};