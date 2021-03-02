#include "Widget.hpp"
#include <cstdio>
#include <stdio.h>


Button::Button(uint32_t p_x, uint32_t p_y, uint32_t p_height, uint32_t p_width)
{
    _x = p_x;
    _y = p_y;
    _width = p_width;
    _height = p_height;
}

void Button::show() 
{           
            BSP_LCD_SetTextColor(_backgroundColor);
            BSP_LCD_FillRect(_x, _y, _width, _height);
            BSP_LCD_SetTextColor(_borderColor);
            BSP_LCD_DrawRect(_x, _y, _width, _height);
            printf("Button");
}

void Button::setBackgroundColor(uint32_t p_color)
{
    
    _backgroundColor = p_color;
}
void Button::setBorderColor(uint32_t p_color)
{
    _borderColor = p_color;
}
void Button::push()
{
    BSP_LCD_SetTextColor(LCD_COLOR_GREEN);
    BSP_LCD_FillRect(_x, _y, _width, _height);
    _function_connected();
    
}
void Button::release()
{
    BSP_LCD_SetTextColor(_backgroundColor);
    BSP_LCD_FillRect(_x, _y, _width, _height);
    
}
bool Button::pointInObject(uint32_t p_x, uint32_t p_y)
{
    HAL_Delay(100);
    if(_x <p_x && p_x<(_x+_height)&& _y<p_y && p_y<(_y+_width))//Пока только такая реализация, потом может переделаю
    {
        
        push();
        HAL_Delay(50);
        release();        
        return true;
    }
    else 
    {
        release();
        
        return false;
    }
    return false;
}
void Button::connect(void (*function)())
{    
    _function_connected = function;
}