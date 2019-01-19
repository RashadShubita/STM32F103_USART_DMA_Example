################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/main.c 

OBJS += \
./src/main.o 

C_DEPS += \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	arm-atollic-eabi-gcc -c "$<" -mthumb -mcpu=cortex-m3 -std=gnu11 -DSTM32F10X_MD -DHSE_VALUE=8000000 -I"C:\IoT\STM32\Blue Pill - STM32F103C8T6\USART_DAM_HFC_Example\src\inc" -I"C:\IoT\STM32\Blue Pill - STM32F103C8T6\USART_DAM_HFC_Example\Libraries\System_stm32f10x\inc" -I../Libraries/CMSIS/Include -I"C:\Program Files (x86)\Atollic\TrueSTUDIO for STM32 9.0.1\ARMTools\arm-atollic-eabi\include" -O0 -ffunction-sections -fdata-sections -g -fstack-usage -Wall -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -specs=nano.specs -o "$@"

