#include "stm32746g_discovery_lcd.h"
#include <stdio.h>
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

class Button: public Widget //вывести в отдельный файл, но пока так работать проще
{
    public:
        Button(uint32_t _x, uint32_t _y, uint32_t _height, uint32_t _width);
        virtual void show();        
        void setBackgroundColor(uint32_t p_color);
        void setBorderColor(uint32_t p_color);
        void repaint(){};
        virtual void push();
        virtual void release();
        virtual bool pointInObject(uint32_t p_x,uint32_t p_y);
        virtual void connect(void (*function)());
    private:
        uint32_t _x;
        uint32_t _y;
        uint32_t _width;
        uint32_t _height;
        uint32_t _backgroundColor;
        uint32_t _borderColor;
        void (*_function_connected) ();

        
};