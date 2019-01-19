################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Libraries/System_stm32f10x/src/startup_stm32f10x_md.s 

C_SRCS += \
../Libraries/System_stm32f10x/src/stm32f1xx_it.c \
../Libraries/System_stm32f10x/src/system_stm32f10x.c 

OBJS += \
./Libraries/System_stm32f10x/src/startup_stm32f10x_md.o \
./Libraries/System_stm32f10x/src/stm32f1xx_it.o \
./Libraries/System_stm32f10x/src/system_stm32f10x.o 

C_DEPS += \
./Libraries/System_stm32f10x/src/stm32f1xx_it.d \
./Libraries/System_stm32f10x/src/system_stm32f10x.d 


# Each subdirectory must supply rules for building sources it contributes
Libraries/System_stm32f10x/src/%.o: ../Libraries/System_stm32f10x/src/%.s
	arm-atollic-eabi-gcc -c -mthumb -mcpu=cortex-m3 -DSTM32F10X_MD -DUSE_STDPERIPH_DRIVER -I../Libraries/CMSIS/Include -I"C:\IoT\STM32\Blue Pill - STM32F103C8T6\USART_DAM_HFC_Example\src\inc" -I"C:\IoT\STM32\Blue Pill - STM32F103C8T6\USART_DAM_HFC_Example\Libraries\System_stm32f10x\inc" -I"C:\Program Files (x86)\Atollic\TrueSTUDIO for STM32 9.0.1\ARMTools\arm-atollic-eabi\include" -g -Wa,--warn -x assembler-with-cpp -specs=nano.specs -o "$@" "$<"
Libraries/System_stm32f10x/src/%.o: ../Libraries/System_stm32f10x/src/%.c
	arm-atollic-eabi-gcc -c "$<" -mthumb -mcpu=cortex-m3 -std=gnu11 -DSTM32F10X_MD -DHSE_VALUE=8000000 -I"C:\Program Files (x86)\Atollic\TrueSTUDIO for STM32 9.0.1\ARMTools\arm-atollic-eabi\include" -I"C:\IoT\STM32\Blue Pill - STM32F103C8T6\USART_DAM_HFC_Example\src\inc" -I"C:\IoT\STM32\Blue Pill - STM32F103C8T6\USART_DAM_HFC_Example\Libraries\System_stm32f10x\inc" -I../Libraries/CMSIS/Include -O0 -ffunction-sections -fdata-sections -g -fstack-usage -Wall -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -specs=nano.specs -o "$@"

