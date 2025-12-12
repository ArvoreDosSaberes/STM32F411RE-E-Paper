# Conexão de pinos do e-Paper no STM32F411RE

Este documento descreve como conectar um módulo e-Paper (Waveshare) ao **STM32F411RE** usando **SPI1** e sinais auxiliares (CS/DC/RST/BUSY).

## 1. Requisitos e premissas

1. O projeto está configurado para usar **SPI1**.
2. O driver e os exemplos usam os sinais definidos em `Inc/main.h` e `User/Config/DEV_Config.h`.
3. A alimentação do e-Paper é **3,3V** (não use 5V).

## 2. Tabela de conexão (ajustada para STM32F411RE)

A tabela abaixo foi baseada na tabela original do STM32F1xx, mas **validada e ajustada** para o mapeamento atual deste projeto no **STM32F411RE**.

| e-Paper (no módulo) | Nome equivalente (no código) | STM32F411RE      | Observação        |
| -------------------- | ----------------------------- | ---------------- | ------------------- |
| VCC                  | (power)                       | 3.3V             | Alimentação 3,3V  |
| GND                  | (power)                       | GND              | Terra comum         |
| D/C                  | `DC`                        | PA2 (GPIO)       | `DC_Pin`          |
| SDI                  | `DIN` / MOSI                | PA7 (SPI1_MOSI)  | Dados do SPI (MOSI) |
| CS                   | `CS`                        | PB6 (GPIO / D10) | `SPI_CS_Pin`      |
| CLK                  | `CLK` / SCK                 | PA5 (SPI1_SCK)   | Clock do SPI        |
| BUSY                 | `BUSY`                      | PA3 (GPIO input) | `BUSY_Pin`        |
| RST                  | `RST`                       | PA1 (GPIO)       | `RST_Pin`         |

### 2.1 Notas sobre nomenclatura (para evitar divergências)

- **D/C** no módulo corresponde ao sinal **DC** (Data/Command) no código.
- **SDI** no módulo corresponde ao **DIN/MOSI** (Serial Data In) no código.
- **BUSI** no módulo corresponde ao **BUSY** (pino de status/ocupado) no código.

## 3. Onde isso está definido no código

- `Inc/main.h`

  - `RST_Pin` = `PA1`
  - `DC_Pin` = `PA2`
  - `BUSY_Pin` = `PA3`
  - `SPI_CS_Pin` = `PB6` (Arduino `D10`)
- `User/Config/DEV_Config.h`

  - `EPD_MOSI_PIN` aponta para `PA7` (fallback), coerente com `SPI1_MOSI`.
  - `EPD_SCLK_PIN` aponta para `PA5` (fallback), coerente com `SPI1_SCK`.

> Importante: no projeto atual, o **SPI hardware** é usado (ver `Src/main.c` / `MX_SPI1_Init`). Os pinos `SDI`/`CLK` não aparecem como GPIOs em `main.h` porque são do periférico SPI.

## 4. Observações elétricas e de confiabilidade

1. **Níveis lógicos**: garanta que o módulo e-Paper seja compatível com 3,3V nos sinais SPI e GPIO.
2. **GND comum**: o GND do e-Paper deve estar ligado ao mesmo GND do STM32.
3. **Cabos curtos**: para evitar ruído no SPI, use fios curtos, especialmente em `CLK` e `SDI`.
4. **BUSY**: é a entrada; não aplique tensão externa nesse pino.

## 5. Checklist rápido

1. Conferir se `PA5` e `PA7` estão configurados como `SPI1_SCK` e `SPI1_MOSI` no `.ioc`.
2. Conferir se `PA1/PA2/PB6` estão como `GPIO_Output` e `PA3` como `GPIO_Input`.
3. Alimentar o módulo com 3,3V.
4. Compilar e rodar um exemplo, selecionando o modelo correto via CMake (`EPD_MODEL`).
