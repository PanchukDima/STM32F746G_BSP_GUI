#include "mbed.h"
#include "ui_bsp.hpp"
#include "stm32746g_discovery_lcd.h"
#include <cstdio>
#include <stdio.h>
// main() runs in its own thread in the OS
void print_hello()
{
    printf("Hello World");
    
}

int main()
{    
    ui_bsp *ui = new ui_bsp();
    Button *btn = new Button(10,10, 50,50);
    //btn->setBackgroundColor(LCD_COLOR_BLACK);
    //btn->setBorderColor(LCD_COLOR_RED);
    void (*message) ();
    message = print_hello;
    btn->connect(*message);
    Button *btn2 = new Button(62,10,50,50);
    btn2->setBackgroundColor(LCD_COLOR_BLACK);
    btn2->setBorderColor(LCD_COLOR_BLUE);
    btn2->connect(*message);
    ui->setBackgroundColor(LCD_COLOR_WHITE);

    ui->addWidget(*btn);
    ui->addWidget(*btn2);
    ui->init();
    while (1) {  
        ui->touchEvents();
        //printf("WORK\n");
        /*ui->setBackgroundColor(LCD_COLOR_WHITE);        
        Button *btn = new Button(100,100,50,50);
        btn->setColor(LCD_COLOR_BLUE);
        ui->addWidget(*btn);
        ui->init();
        //btn->show();     */
        
        
    }
}



