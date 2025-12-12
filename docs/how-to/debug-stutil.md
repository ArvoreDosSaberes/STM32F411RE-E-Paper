# Depuração com st-util + GDB (ST-LINK)

Este guia mostra como depurar usando **st-util** (do pacote stlink) e `arm-none-eabi-gdb`.

## 1. Pré-requisitos

1. Ter o build `Debug` gerado (ver `build-cmake.md`).
2. Instalar:

   1. `st-util`
   2. `arm-none-eabi-gdb`

## 2. Iniciar o st-util

1. Em um terminal, executar:

   ```bash
   st-util
   ```

2. Por padrão, o `st-util` expõe o servidor GDB em:

- `:4242`

## 3. Conectar com o GDB

1. Em outro terminal:

   ```bash
   arm-none-eabi-gdb build/Debug/STM32F411RE-E-Paper-NG.elf
   ```

2. No console do GDB:

   1. Conectar:

      ```gdb
      target extended-remote :4242
      ```

   2. Reset + halt:

      ```gdb
      monitor reset halt
      ```

   3. Gravar firmware:

      ```gdb
      load
      ```

   4. Executar:

      ```gdb
      continue
      ```

## 4. Finalização graciosa

1. Encerrar debug no GDB:

   1. `Ctrl+C`
   2. `quit`

2. Encerrar `st-util`:

   - `Ctrl+C`
