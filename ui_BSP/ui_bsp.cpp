#include "ui_bsp.hpp"
#include <cstdint>

ui_bsp::ui_bsp()
{
    uint8_t status;
    _currentIndexWidget = 0;
    BSP_LCD_Init();
    BSP_LCD_LayerDefaultInit(LTDC_ACTIVE_LAYER, LCD_FB_START_ADDRESS);
    BSP_LCD_SelectLayer(LTDC_ACTIVE_LAYER);
    
    status = BSP_TS_Init(BSP_LCD_GetXSize(), BSP_LCD_GetYSize());
    if (status != TS_OK) 
        {
            _touchLock = true;
        } 
    else 
        {
            _touchLock = false;
        }
}

void ui_bsp::init()
{
    BSP_LCD_Clear(_backgroundColor);
    for (int i = 0; i< _currentIndexWidget; i++)
        {
            _Widgets[i]->show();
        }
}

void ui_bsp::setBackgroundColor(uint32_t p_color)
{
    _backgroundColor = p_color;
}
void ui_bsp::touchEvents()
{
    if(!_touchLock)
    {
        
        BSP_TS_GetState(&TS_State);
        if (TS_State.touchDetected) {
            // Clear lines corresponding to old touches coordinates
            if (TS_State.touchDetected < prev_nb_touches) {
                for (idx = (TS_State.touchDetected + 1); idx <= 5; idx++) {
                    //BSP_LCD_ClearStringLine(idx);
                }
            }
            prev_nb_touches = TS_State.touchDetected;

            cleared = 0;

            //printf((char*)text, "Touches: %d", TS_State.touchDetected);
            //BSP_LCD_DisplayStringAt(0, LINE(0), (uint8_t *)&text, LEFT_MODE);

            for (idx = 0; idx < TS_State.touchDetected; idx++) {
                x = TS_State.touchX[idx];
                y = TS_State.touchY[idx];
                //printf("%d:%d ", x, y);
                for(int i = 0; i<_currentIndexWidget; i++)
                {
                    _Widgets[i]->pointInObject(x,y);
                }

                //sprintf((char*)text, "Touch %d: x=%d y=%d    ", idx+1, x, y);
                //BSP_LCD_DisplayStringAt(0, LINE(idx+1), (uint8_t *)&text, LEFT_MODE);
            }

            //BSP_LCD_DrawPixel(TS_State.touchX[0], TS_State.touchY[0], LCD_COLOR_ORANGE);
        } else {
            if (!cleared) {
                for(int i = 0; i<_currentIndexWidget; i++)
                {
                    _Widgets[i]->release();
                }
                //BSP_LCD_Clear(LCD_COLOR_BLUE);
                //sprintf((char*)text, "Touches: 0");
                //BSP_LCD_DisplayStringAt(0, LINE(0), (uint8_t *)&text, LEFT_MODE);
                cleared = 1;
            }
        }
    }
}
