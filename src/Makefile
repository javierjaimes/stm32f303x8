CC=arm-none-eabi-gcc
OBJ=arm-none-eabi-objcopy
CFLAGS=

startup.s:  
	$(CC) -Wall -mcpu=cortex-m4 -mlittle-endian -mthumb -Os -c startup_stm32f303x8.s -o startup.o
	$(CC) -Wall -mcpu=cortex-m4 -mlittle-endian -mthumb -Os -c main.c -o main.o

linker.ld: startup.s
	$(CC) -T STM32F303K8Tx_FLASH.ld -Wl,--gc-sections main.o startup.o -o main.elf
	$(OBJ) -O ihex main.elf main.hex

default: linker.ld
