# STM32F411RE E Paper NG
 
 ![Visitors](https://visitor-badge.laobi.icu/badge?page_id=ArvoreDosSaberes.STM32F411RE-E-Paper)
 [![License: CC BY 4.0](https://img.shields.io/badge/License-CC%20BY%204.0-lightgrey.svg)](https://creativecommons.org/licenses/by/4.0/)
 [![C](https://img.shields.io/badge/Language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
 [![Build: CMake](https://img.shields.io/badge/Build-CMake-064F8C.svg)](https://cmake.org/)
 [![STM32F4](https://img.shields.io/badge/STM32F4-Supported-green.svg)](https://www.st.com/en/microcontrollers-microprocessors/stm32f4-series.html)
 [![Nucleo-F411RE](https://img.shields.io/badge/Board-Nucleo--F411RE-green.svg)](https://www.st.com/en/evaluation-tools/nucleo-f411re.html)
 [![GitHub](https://img.shields.io/github/stars/ArvoreDosSaberes/STM32F411RE-E-Paper?style=social)](https://github.com/ArvoreDosSaberes/STM32F411RE-E-Paper)
 [![GitHub Issues](https://img.shields.io/github/issues/ArvoreDosSaberes/STM32F411RE-E-Paper)](https://github.com/ArvoreDosSaberes/STM32F411RE-E-Paper/issues)
 
 ## Visão geral
 
 Este repositório contém um firmware para **STM32F411RE (Nucleo-F411RE)** com integração de um display **e-Paper** via **SPI**.
 
 O projeto é baseado em código gerado pelo **STM32CubeMX** (HAL) e tem suporte de build via **CMake** (com *presets*) e *toolchain* `arm-none-eabi`.
 
 ## Documentação (passo a passo)
 
 A documentação completa (em PT-BR) está em `./docs/`:
 
 - `docs/README.md`
 - `docs/how-to/build-cmake.md`
 - `docs/how-to/debug-openocd.md`
 - `docs/how-to/debug-stutil.md`
 - `docs/how-to/troubleshooting.md`
 
 ## Pré-requisitos
 
 - **Toolchain ARM**: `arm-none-eabi-gcc`, `arm-none-eabi-gdb`
 - **Build**: `cmake (>= 3.22)`, `ninja`
 - **Depuração** (uma opção):
   - **OpenOCD** (recomendado)
   - **stlink/st-util** (alternativo)
 
 ## Como compilar (CMake Presets)
 
 1. Configurar (Debug):
 
    ```bash
    cmake --preset Debug
    ```
 
 2. Compilar (Debug):
 
    ```bash
    cmake --build --preset Debug
    ```
 
 3. Artefato gerado:
 
    - `build/Debug/STM32F411RE-E-Paper-NG.elf`
 
 > Observação: o *toolchain file* usado pelos presets é `cmake/gcc-arm-none-eabi.cmake`.
 
 ## Como depurar
 
 - **OpenOCD + GDB**: ver `docs/how-to/debug-openocd.md`
 - **st-util + GDB**: ver `docs/how-to/debug-stutil.md`
 
 ## Bibliotecas e componentes
 
 - **STM32 HAL / CMSIS** (disponível em `Drivers/`)
 - **Código gerado pelo STM32CubeMX** (principalmente em `Core/`)
 
 As *include dirs* e fontes principais podem ser vistas em:
 
 - `CMakeLists.txt`
 - `cmake/stm32cubemx/CMakeLists.txt`
 
 ## Referências
 
 Primeiros passos (referências externas que motivaram o setup inicial):
 
 - https://blog.embeddedexpert.io/?p=3809
 - https://blog.embeddedexpert.io/?p=3807
 
 ## Mantenedor
 
 - **Carlos Delfino Carvalho Pinheiro**
 - Site: https://carlosdelfino.eti.br
 - E-mail: consultoria@carlosdelfino.eti.br
 - Referência: https://mcu.tec.br (artigos relevantes sobre MCU e FPGA)
