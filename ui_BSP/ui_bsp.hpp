#include "stm32746g_discovery_lcd.h"
#include "stm32746g_discovery_ts.h"
#include <stdint.h>
#include <string>
#include <vector>
#include "Widget.hpp"

class ui_bsp
{
    public:
        ui_bsp();
        void init();
        void setBackgroundColor(uint32_t p_color);
        void addWidget(Widget &p_Widget)
        {
            _Widgets[_currentIndexWidget]= &p_Widget;
            _currentIndexWidget +=1;
        }
        void touchEvents();       
        
    private:
        uint32_t _backgroundColor;
        uint32_t _currentIndexWidget;
        bool _touchLock;
        Widget * _Widgets[10]= {};
        TS_StateTypeDef TS_State;
        uint16_t x, y;
        uint8_t idx;
        uint8_t cleared = 0;
        uint8_t prev_nb_touches = 0;
        uint8_t text[30];
};

