#ifndef __EPAPER_PARAMETERS_H
#define __EPAPER_PARAMETERS_H

#define B1_Pin             GPIO_PIN_13
#define B1_GPIO_Port       GPIOC
#define PWR_Pin            GPIO_PIN_1
#define PWR_GPIO_Port      GPIOC
#define CS_Pin             GPIO_PIN_0
#define CS_GPIO_Port       GPIOA
#define DC_Pin             GPIO_PIN_1
#define DC_GPIO_Port       GPIOA
#define USART_TX_Pin       GPIO_PIN_2
#define USART_TX_GPIO_Port GPIOA
#define USART_RX_Pin       GPIO_PIN_3
#define USART_RX_GPIO_Port GPIOA
#define RST_Pin            GPIO_PIN_4
#define RST_GPIO_Port      GPIOA
#define LD2_Pin            GPIO_PIN_5
#define LD2_GPIO_Port      GPIOA
#define BUSY_Pin           GPIO_PIN_0
#define BUSY_GPIO_Port     GPIOB
#define TMS_Pin            GPIO_PIN_13
#define TMS_GPIO_Port      GPIOA
#define TCK_Pin            GPIO_PIN_14
#define TCK_GPIO_Port      GPIOA
#define SWO_Pin            GPIO_PIN_3
#define SWO_GPIO_Port      GPIOB

#endif /* __EPAPER_PARAMETERS_H */