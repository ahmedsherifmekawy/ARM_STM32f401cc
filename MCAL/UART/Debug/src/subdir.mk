################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Gpio.c \
../src/Led.c \
../src/Led_cfg.c \
../src/NVIC.c \
../src/RCC.c \
../src/Uart.c \
../src/_write.c \
../src/main.c 

OBJS += \
./src/Gpio.o \
./src/Led.o \
./src/Led_cfg.o \
./src/NVIC.o \
./src/RCC.o \
./src/Uart.o \
./src/_write.o \
./src/main.o 

C_DEPS += \
./src/Gpio.d \
./src/Led.d \
./src/Led_cfg.d \
./src/NVIC.d \
./src/RCC.d \
./src/Uart.d \
./src/_write.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F401xC -DUSE_HAL_DRIVER -DHSE_VALUE=25000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f4-hal" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


