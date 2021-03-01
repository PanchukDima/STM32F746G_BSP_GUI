#include "Widget.hpp"


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
}
void Button::release()
{
    BSP_LCD_SetTextColor(_backgroundColor);
    BSP_LCD_FillRect(_x, _y, _width, _height);
}
bool Button::pointInObject(uint32_t p_x, uint32_t p_y)
{
    if(_x < p_x < _x +_width && _y < p_y < _y + _height)
    {
        return true;
    }
    else 
    {
        return true;
    }
    return false;
}