/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "spi.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "epaper.h"

#include "fonts/FreeSans9pt7b.h"
#include "fonts/FreeSans12pt7b.h"
#include "fonts/FreeSans18pt7b.h"
#include "fonts/FreeSans24pt7b.h"
#include "fonts/FreeSansBold12pt7b.h"
#include "fonts/FreeSansBold9pt7b.h"
#include "fonts/FreeSansBold18pt7b.h"
#include "fonts/FreeSansBold24pt7b.h"
#include "fonts/FreeSansOblique9pt7b.h"
#include "fonts/FreeSansOblique12pt7b.h"
#include "fonts/FreeSansOblique18pt7b.h"
#include "fonts/FreeSansOblique24pt7b.h"
#include "fonts/FreeSansBoldOblique9pt7b.h"
#include "fonts/FreeSansBoldOblique12pt7b.h"
#include "fonts/FreeSansBoldOblique18pt7b.h"
#include "fonts/FreeSansBoldOblique24pt7b.h"

#include "fonts/FreeSerif9pt7b.h"
#include "fonts/FreeSerif12pt7b.h"
#include "fonts/FreeSerif18pt7b.h"
#include "fonts/FreeSerif24pt7b.h"
#include "fonts/FreeSerifBold9pt7b.h"
#include "fonts/FreeSerifBold12pt7b.h"
#include "fonts/FreeSerifBold18pt7b.h"
#include "fonts/FreeSerifBold24pt7b.h"
#include "fonts/FreeSerifItalic9pt7b.h"
#include "fonts/FreeSerifItalic12pt7b.h"
#include "fonts/FreeSerifItalic18pt7b.h"
#include "fonts/FreeSerifItalic24pt7b.h"
#include "fonts/FreeSerifBoldItalic9pt7b.h"
#include "fonts/FreeSerifBoldItalic12pt7b.h"
#include "fonts/FreeSerifBoldItalic18pt7b.h"
#include "fonts/FreeSerifBoldItalic24pt7b.h"

#include "fonts/FreeMono9pt7b.h"
#include "fonts/FreeMono12pt7b.h"
#include "fonts/FreeMono18pt7b.h"
#include "fonts/FreeMono24pt7b.h"
#include "fonts/FreeMonoBold9pt7b.h"
#include "fonts/FreeMonoBold12pt7b.h"
#include "fonts/FreeMonoBold18pt7b.h"
#include "fonts/FreeMonoBold24pt7b.h"
#include "fonts/FreeMonoOblique9pt7b.h"
#include "fonts/FreeMonoOblique12pt7b.h"
#include "fonts/FreeMonoOblique18pt7b.h"
#include "fonts/FreeMonoOblique24pt7b.h"
#include "fonts/FreeMonoBoldOblique9pt7b.h"
#include "fonts/FreeMonoBoldOblique12pt7b.h"
#include "fonts/FreeMonoBoldOblique18pt7b.h"
#include "fonts/FreeMonoBoldOblique24pt7b.h"

#include "fonts/TomThumb.h"
#include "fonts/Org_01.h"
#include "fonts/Picopixel.h"
#include "fonts/Tiny3x3a2pt7b.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  MX_SPI2_Init();
  /* USER CODE BEGIN 2 */
  //HAL_GPIO_WritePin(PWR_GPIO_Port, PWR_Pin, 1);
  ePaper_Init();

  ePaper_FrameBufferClear(EPAPER_COLOR_WHITE);
  ePaper_Refresh();

  const GFXfont *fonts[] = {
		&FreeSans9pt7b,
		&FreeSans12pt7b,
		&FreeSans18pt7b,
		&FreeSans24pt7b,
		&FreeSansBold9pt7b,
		&FreeSansBold12pt7b,
		&FreeSansBold18pt7b,
		&FreeSansBold24pt7b,
		&FreeSansOblique9pt7b,
		&FreeSansOblique12pt7b,
		&FreeSansOblique18pt7b,
		&FreeSansOblique24pt7b,
		&FreeSansBoldOblique9pt7b,
		&FreeSansBoldOblique12pt7b,
		&FreeSansBoldOblique18pt7b,
		&FreeSansBoldOblique24pt7b,
		&FreeSerif9pt7b,
		&FreeSerif12pt7b,
		&FreeSerif18pt7b,
		&FreeSerif24pt7b,
		&FreeSerifBold9pt7b,
		&FreeSerifBold12pt7b,
		&FreeSerifBold18pt7b,
		&FreeSerifBold24pt7b,
		&FreeSerifItalic9pt7b,
		&FreeSerifItalic12pt7b,
		&FreeSerifItalic18pt7b,
		&FreeSerifItalic24pt7b,
		&FreeSerifBoldItalic9pt7b,
		&FreeSerifBoldItalic12pt7b,
		&FreeSerifBoldItalic18pt7b,
		&FreeSerifBoldItalic24pt7b,
		&FreeMono9pt7b,
		&FreeMono12pt7b,
		&FreeMono18pt7b,
		&FreeMono24pt7b,
		&FreeMonoBold9pt7b,
		&FreeMonoBold12pt7b,
		&FreeMonoBold18pt7b,
		&FreeMonoBold24pt7b,
		&FreeMonoOblique9pt7b,
		&FreeMonoOblique12pt7b,
		&FreeMonoOblique18pt7b,
		&FreeMonoOblique24pt7b,
		&FreeMonoBoldOblique9pt7b,
		&FreeMonoBoldOblique12pt7b,
		&FreeMonoBoldOblique18pt7b,
		&FreeMonoBoldOblique24pt7b,
		&TomThumb,
		&Org_01,
		&Picopixel,
		&Tiny3x3a2pt7b,
  };

  const char *fontNames[] = {
		"FreeSans9pt7b",
		"FreeSans12pt7b",
		"FreeSans18pt7b",
		"FreeSans24pt7b",
		"FreeSansBold9pt7b",
		"FreeSansBold12pt7b",
		"FreeSansBold18pt7b",
		"FreeSansBold24pt7b",
		"FreeSansOblique9pt7b",
		"FreeSansOblique12pt7b",
		"FreeSansOblique18pt7b",
		"FreeSansOblique24pt7b",
		"FreeSansBoldOblique9pt7b",
		"FreeSansBoldOblique12pt7b",
		"FreeSansBoldOblique18pt7b",
		"FreeSansBoldOblique24pt7b",
		"FreeSerif9pt7b",
		"FreeSerif12pt7b",
		"FreeSerif18pt7b",
		"FreeSerif24pt7b",
		"FreeSerifBold9pt7b",
		"FreeSerifBold12pt7b",
		"FreeSerifBold18pt7b",
		"FreeSerifBold24pt7b",
		"FreeSerifItalic9pt7b",
		"FreeSerifItalic12pt7b",
		"FreeSerifItalic18pt7b",
		"FreeSerifItalic24pt7b",
		"FreeSerifBoldItalic9pt7b",
		"FreeSerifBoldItalic12pt7b",
		"FreeSerifBoldItalic18pt7b",
		"FreeSerifBoldItalic24pt7b",
		"FreeMono9pt7b",
		"FreeMono12pt7b",
		"FreeMono18pt7b",
		"FreeMono24pt7b",
		"FreeMonoBold9pt7b",
		"FreeMonoBold12pt7b",
		"FreeMonoBold18pt7b",
		"FreeMonoBold24pt7b",
		"FreeMonoOblique9pt7b",
		"FreeMonoOblique12pt7b",
		"FreeMonoOblique18pt7b",
		"FreeMonoOblique24pt7b",
		"FreeMonoBoldOblique9pt7b",
		"FreeMonoBoldOblique12pt7b",
		"FreeMonoBoldOblique18pt7b",
		"FreeMonoBoldOblique24pt7b",
		"TomThumb",
		"Org_01",
		"Picopixel",
		"Tiny3x3a2pt7b",
  };

  const uint32_t fontsCount = (uint32_t)(sizeof(fonts) / sizeof(fonts[0]));

  uint32_t fontIndex = 0;
  uint32_t nextTick = HAL_GetTick();

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  uint32_t now = HAL_GetTick();
	  if ((int32_t)(now - nextTick) >= 0) {
		  uint32_t index = (uint32_t)(fontIndex % fontsCount);
		  const GFXfont *font = fonts[index];
		  const char *fontName = fontNames[index];
		  fontIndex++;

		  ePaper_FrameBufferClear(EPAPER_COLOR_WHITE);

		  ePaper_SetFont(EPAPER_FONT_DEFAULT_8X8);
		  ePaper_SetGfxFont(NULL);
		  ePaper_DrawString(0, 0, "Font demo:", EPAPER_COLOR_BLACK);
		  ePaper_DrawString(0, 10, fontName, EPAPER_COLOR_BLACK);

		  ePaper_SetGfxFont(font);
		  ePaper_DrawString(0, 40, "AaBbCcDdEe", EPAPER_COLOR_BLACK);
		  ePaper_DrawString(0, 40 + (font->yAdvance ? font->yAdvance : 8u), "0123456789", EPAPER_COLOR_BLACK);
		  ePaper_DrawString(0, 40 + (font->yAdvance ? (uint16_t)(2u * font->yAdvance) : 16u), "RAPPORT", EPAPER_COLOR_BLACK);

		  ePaper_Refresh();
		  nextTick += 2000u;
	  }
    
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 16;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}
#ifdef USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
