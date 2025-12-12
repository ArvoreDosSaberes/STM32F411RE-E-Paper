#include "epaper.h"

static void ePaper_WriteData(uint8_t data)
{
	HAL_GPIO_WritePin(DC_GPIO_Port, DC_Pin,1);

	HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin, 0);

	HAL_SPI_Transmit(&hspi2, &data, 1, 10);

	HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin, 1);
}

static void ePaper_WriteCmd(uint8_t cmd)
{
	HAL_GPIO_WritePin(DC_GPIO_Port, DC_Pin,0);

	HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin, 0);

	HAL_SPI_Transmit(&hspi2, &cmd, 1, 10);

	HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin, 1);

}

static void ePaper_Reset(void)
{
	HAL_GPIO_WritePin(RST_GPIO_Port, RST_Pin, 1);

	HAL_Delay(200);

	HAL_GPIO_WritePin(RST_GPIO_Port, RST_Pin, 0);

	HAL_Delay(10);

	HAL_GPIO_WritePin(RST_GPIO_Port, RST_Pin, 1);

	HAL_Delay(200);

}

static StateTypedef ePaper_State(void)
{
	return HAL_GPIO_ReadPin(BUSY_GPIO_Port, BUSY_Pin);
}

static void ePaper_Display_On(void)
{
	ePaper_WriteCmd(0x20);
	while(ePaper_State()==BUSY)
	{
		HAL_Delay(1);
	}

}

static void ePaper_SetWindows(uint16_t Xstart, uint16_t Ystart, uint16_t Xend, uint16_t Yend)
{
	ePaper_WriteCmd(0x44); // SET_RAM_X_ADDRESS_START_END_POSITION
	ePaper_WriteData((Xstart>>3) & 0x1F);
	ePaper_WriteData((Xend>>3) & 0x1F);

    ePaper_WriteCmd(0x45); // SET_RAM_Y_ADDRESS_START_END_POSITION
    ePaper_WriteData(Ystart & 0xFF);
    ePaper_WriteData((Ystart >> 8) & 0x01);
    ePaper_WriteData(Yend & 0xFF);
    ePaper_WriteData((Yend >> 8) & 0x01);
}

static void ePaper_SetCursor(uint16_t Xstart, uint16_t Ystart)
{
	ePaper_WriteCmd(0x4E); // SET_RAM_X_ADDRESS_COUNTER
	ePaper_WriteData(Xstart & 0x1F);

    ePaper_WriteCmd(0x4F); // SET_RAM_Y_ADDRESS_COUNTER
    ePaper_WriteData(Ystart & 0xFF);
    ePaper_WriteData((Ystart >> 8) & 0x01);
}

void ePaper_Init(void)
{
	ePaper_Reset();
	while(ePaper_State()==BUSY)
	{
		HAL_Delay(1);
	}
	ePaper_WriteCmd(0x12);
	while(ePaper_State()==BUSY)
	{
		HAL_Delay(1);
	}
   	ePaper_WriteCmd(0x11);
	ePaper_WriteData(0x03);
    ePaper_SetWindows(0,0,ePaper_WIDTH-1,ePaper_HEIGHT-1);
   	ePaper_WriteCmd(0x3C);	//0x00
	ePaper_WriteData(0x00);
    ePaper_SetCursor(0,0);
	while(ePaper_State()==BUSY)
	{
		HAL_Delay(1);
	}
}

void ePaper_Clear(void)
{
    uint16_t Width, Height;
    Width = (ePaper_WIDTH % 8 == 0)? (ePaper_WIDTH / 8 ): (ePaper_WIDTH / 8 + 1);
    Height = ePaper_HEIGHT;

    ePaper_WriteCmd(0x24);
    for (uint16_t j = 0; j < Height; j++) {
        for (uint16_t i = 0; i < Width; i++) {
        	ePaper_WriteData(0xff);
        }
    }
    ePaper_WriteCmd(0x26);
    for (uint16_t j = 0; j < Height; j++) {
        for (uint16_t i = 0; i < Width; i++) {
        	ePaper_WriteData(0x00);
        }
    }
    ePaper_Display_On();
}

void ePaper_Clear_Black(void)
{

    uint16_t Width, Height;
    Width = (ePaper_WIDTH % 8 == 0)? (ePaper_WIDTH / 8 ): (ePaper_WIDTH / 8 + 1);
    Height = ePaper_HEIGHT;

    ePaper_WriteCmd(0x24);
    for (uint16_t j = 0; j < Height; j++) {
        for (uint16_t i = 0; i < Width; i++) {
        	ePaper_WriteData(0x00);
        }
    }
    ePaper_WriteCmd(0x26);
    for (uint16_t j = 0; j < Height; j++) {
        for (uint16_t i = 0; i < Width; i++) {
        	ePaper_WriteData(0x00);
        }
    }
    ePaper_Display_On();
}

void ePaper_Clear_Red(void)
{
	uint16_t Width, Height;
    Width = (ePaper_WIDTH % 8 == 0)? (ePaper_WIDTH / 8 ): (ePaper_WIDTH / 8 + 1);
    Height = ePaper_HEIGHT;

    ePaper_WriteCmd(0x24);
    for (uint16_t j = 0; j < Height; j++) {
        for (uint16_t i = 0; i < Width; i++) {
        	ePaper_WriteData(0x00);
        }
    }
    ePaper_WriteCmd(0x26);
    for (uint16_t j = 0; j < Height; j++) {
        for (uint16_t i = 0; i < Width; i++) {
        	ePaper_WriteData(0xFF);
        }
    }
    ePaper_Display_On();
}

void ePaper_Sleep(void)
{
	ePaper_WriteCmd(0x10); // POWER_OFF
	ePaper_WriteData(0X01);

}

