# Como usar a biblioteca E-Paper neste projeto (STM32F411RE)

Este guia explica, de forma prática, como compilar e utilizar o driver **E-Paper** disponível em `Drivers/E-Paper` dentro deste firmware.

## 1. O que é este driver

O driver disponibiliza uma API mínima (arquivo `Drivers/E-Paper/epaper.h`) para:

- Inicializar o display (`ePaper_Init`)
- Limpar a tela (branco/preto/vermelho) (`ePaper_Clear`, `ePaper_Clear_Black`, `ePaper_Clear_Red`)
- Colocar em baixo consumo (`ePaper_Sleep`)

Ele opera via **SPI + GPIO** com **STM32 HAL**.

## 2. Pré-requisitos

- Projeto gerado/configurado via **STM32CubeMX** (HAL habilitado)
- SPI configurado no `.ioc`
- GPIOs configurados para os sinais do display:

  - `DC` (Data/Command)
  - `CS` (Chip Select)
  - `RST` (Reset)
  - `BUSY` (status do display)

## 3. Pinagem (hardware)

A pinagem recomendada para este repositório está documentada em:

- `docs/pinout-epaper-stm32f411re.md`

Importante:

- Alimente o módulo e-Paper em **3,3V**
- Mantenha cabos curtos no SPI (principalmente `SCK` e `MOSI`)

## 4. Como compilar (CMake)

A biblioteca expõe o target:

- `E-Paper` (STATIC)

Em geral, basta garantir que o CMake do projeto principal adicionou/consumiu `Drivers/E-Paper` e que o executável final linkou contra `E-Paper`.

Se você estiver criando um target novo, o padrão esperado é:

- O executável linka `E-Paper`
- O include `Drivers/E-Paper` fica disponível automaticamente via `target_include_directories(E-Paper PUBLIC ...)`

## 5. Como usar no firmware (exemplo de fluxo)

Fluxo típico no `main`:

1. Inicialize HAL/periféricos (GPIO, SPI)
2. Chame `ePaper_Init()`
3. Opcional: limpe a tela (`ePaper_Clear()` ou variantes)
4. Quando terminar, chame `ePaper_Sleep()`

Observação importante sobre bloqueio:

- O driver faz **busy-wait** no pino `BUSY`.
- **Não há timeout**: se o módulo estiver desconectado ou com falha, o firmware pode ficar preso nos loops de espera.

## 6. Depuração

Para depurar problemas comuns:

- Verifique se `BUSY` muda de estado durante o refresh
- Confirme se `CS/DC/RST` estão com a polaridade correta
- Confira o SPI (modo, clock, MOSI) conforme o módulo

## 7. Créditos e licenças

Este diretório referencia a biblioteca no repositório:

- `git@github.com:ArvoreDosSaberes/E-Paper-Library.git`

Ao redistribuir/alterar, mantenha os créditos e respeite as licenças aplicáveis do repositório original.

## 8. Autores

- Carlos Delfino — consultoria@carlosdelfino.eti.br — GitHub: @carlosdelfino — Sites: [Carlos Delfino](https://carlosdelfino.eti.br "Site de Carlos Delfino Especilaista em TI, IoT e AIoT") e [MCU.TEC.BR](https://mcu.tec.br "Artigos sobre MCU e FPGA")
