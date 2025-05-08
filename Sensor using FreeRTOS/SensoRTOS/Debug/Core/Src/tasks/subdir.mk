################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/tasks/task_dht22.c \
../Core/Src/tasks/task_display.c \
../Core/Src/tasks/task_hcsr04.c \
../Core/Src/tasks/task_uart.c 

OBJS += \
./Core/Src/tasks/task_dht22.o \
./Core/Src/tasks/task_display.o \
./Core/Src/tasks/task_hcsr04.o \
./Core/Src/tasks/task_uart.o 

C_DEPS += \
./Core/Src/tasks/task_dht22.d \
./Core/Src/tasks/task_display.d \
./Core/Src/tasks/task_hcsr04.d \
./Core/Src/tasks/task_uart.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/tasks/%.o Core/Src/tasks/%.su Core/Src/tasks/%.cyclo: ../Core/Src/tasks/%.c Core/Src/tasks/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I"D:/Firmware/STM32/Project_Res/SensoRTOS/Core/Inc/tasks" -I"D:/Firmware/STM32/Project_Res/SensoRTOS/Core/Inc/drivers" -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM3 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-tasks

clean-Core-2f-Src-2f-tasks:
	-$(RM) ./Core/Src/tasks/task_dht22.cyclo ./Core/Src/tasks/task_dht22.d ./Core/Src/tasks/task_dht22.o ./Core/Src/tasks/task_dht22.su ./Core/Src/tasks/task_display.cyclo ./Core/Src/tasks/task_display.d ./Core/Src/tasks/task_display.o ./Core/Src/tasks/task_display.su ./Core/Src/tasks/task_hcsr04.cyclo ./Core/Src/tasks/task_hcsr04.d ./Core/Src/tasks/task_hcsr04.o ./Core/Src/tasks/task_hcsr04.su ./Core/Src/tasks/task_uart.cyclo ./Core/Src/tasks/task_uart.d ./Core/Src/tasks/task_uart.o ./Core/Src/tasks/task_uart.su

.PHONY: clean-Core-2f-Src-2f-tasks

