#include "mbed.h"
#include "ui_bsp.hpp"
#include "Button.hpp"
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
    void (*message) ();
    message = print_hello;
    btn->connect(*message);
    Button *btn2 = new Button(62,10,50,50);
    btn2->connect(*message);
    ui->setBackgroundColor(LCD_COLOR_WHITE);

    ui->addWidget(*btn);
    ui->addWidget(*btn2);
    ui->init();
    while (1) {  
        ui->touchEvents();
               
    }
}



