#ifndef __EPAPER_H
#define __EPAPER_H

#include "main.h"
#include "stm32f4xx_hal.h"
#include "spi.h"

#define ePaper_WIDTH 200
#define ePaper_HEIGHT 200

typedef enum{
    IDLE = 0,
    BUSY = 1
} StateTypedef;

void ePaper_Init(void);
void ePaper_Clear(void);
void ePaper_Clear_Black(void);
void ePaper_Clear_Red(void);
void ePaper_Sleep(void);

#endif /* __EPAPER_H */