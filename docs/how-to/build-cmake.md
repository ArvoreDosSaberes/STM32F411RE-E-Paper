# Como compilar com CMake (Linux)

Este guia explica como compilar o firmware usando CMake + Ninja e o *toolchain* `arm-none-eabi`.

## 1. Pré-requisitos

1. Instalar ferramentas de build:

   1. `cmake` (>= 3.22)
   2. `ninja`

2. Instalar toolchain ARM:

   1. `arm-none-eabi-gcc`
   2. `arm-none-eabi-gdb`
   3. `arm-none-eabi-objcopy` (geralmente vem junto do GCC)

> Importante: o CMake do projeto assume que `arm-none-eabi-*` está disponível no `PATH`.

## 2. Entendendo o que o projeto gera

- O alvo principal é um ELF:

  - `STM32F411RE-E-Paper-NG.elf`

- O *linker script* usado é:

  - `STM32F411XX_FLASH.ld`

- O *toolchain file* usado pelos *presets* é:

  - `cmake/gcc-arm-none-eabi.cmake`

## 3. Build usando CMake Presets

O repositório já inclui `CMakePresets.json` com dois presets principais:

- `Debug`
- `Release`

### 3.1 Configurar (Debug)

1. Executar a configuração do CMake:

   ```bash
   cmake --preset Debug
   ```

2. Verificar a pasta de build:

   - `build/Debug/`

### 3.2 Compilar (Debug)

1. Compilar:

   ```bash
   cmake --build --preset Debug
   ```

2. Artefato esperado:

   - `build/Debug/STM32F411RE-E-Paper-NG.elf`

### 3.3 Compilar (Release)

1. Configurar:

   ```bash
   cmake --preset Release
   ```

2. Build:

   ```bash
   cmake --build --preset Release
   ```

## 4. Dicas para IDE (clangd)

O projeto habilita `CMAKE_EXPORT_COMPILE_COMMANDS=TRUE`, então o arquivo abaixo pode ser usado pelo `clangd`:

- `build/<preset>/compile_commands.json`

Se sua IDE precisar do arquivo na raiz, você pode criar um link simbólico (opcional).

## 5. Próximos passos

Após compilar:

1. Para **gravar e depurar com OpenOCD**, siga `debug-openocd.md`.
2. Para **depurar com st-util**, siga `debug-stutil.md`.
