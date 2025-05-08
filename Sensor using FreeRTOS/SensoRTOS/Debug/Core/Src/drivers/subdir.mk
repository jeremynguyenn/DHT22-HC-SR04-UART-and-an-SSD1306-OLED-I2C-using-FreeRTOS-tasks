################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/drivers/delay.c \
../Core/Src/drivers/dht22-driver.c \
../Core/Src/drivers/gpio-driver.c \
../Core/Src/drivers/hc_sr04-driver.c \
../Core/Src/drivers/ssd1306-i2c-driver.c \
../Core/Src/drivers/ssd1306_font6x8.c \
../Core/Src/drivers/systemclock_config.c \
../Core/Src/drivers/uart-driver.c 

OBJS += \
./Core/Src/drivers/delay.o \
./Core/Src/drivers/dht22-driver.o \
./Core/Src/drivers/gpio-driver.o \
./Core/Src/drivers/hc_sr04-driver.o \
./Core/Src/drivers/ssd1306-i2c-driver.o \
./Core/Src/drivers/ssd1306_font6x8.o \
./Core/Src/drivers/systemclock_config.o \
./Core/Src/drivers/uart-driver.o 

C_DEPS += \
./Core/Src/drivers/delay.d \
./Core/Src/drivers/dht22-driver.d \
./Core/Src/drivers/gpio-driver.d \
./Core/Src/drivers/hc_sr04-driver.d \
./Core/Src/drivers/ssd1306-i2c-driver.d \
./Core/Src/drivers/ssd1306_font6x8.d \
./Core/Src/drivers/systemclock_config.d \
./Core/Src/drivers/uart-driver.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/drivers/%.o Core/Src/drivers/%.su Core/Src/drivers/%.cyclo: ../Core/Src/drivers/%.c Core/Src/drivers/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I"D:/Firmware/STM32/Project_Res/SensoRTOS/Core/Inc/tasks" -I"D:/Firmware/STM32/Project_Res/SensoRTOS/Core/Inc/drivers" -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM3 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-drivers

clean-Core-2f-Src-2f-drivers:
	-$(RM) ./Core/Src/drivers/delay.cyclo ./Core/Src/drivers/delay.d ./Core/Src/drivers/delay.o ./Core/Src/drivers/delay.su ./Core/Src/drivers/dht22-driver.cyclo ./Core/Src/drivers/dht22-driver.d ./Core/Src/drivers/dht22-driver.o ./Core/Src/drivers/dht22-driver.su ./Core/Src/drivers/gpio-driver.cyclo ./Core/Src/drivers/gpio-driver.d ./Core/Src/drivers/gpio-driver.o ./Core/Src/drivers/gpio-driver.su ./Core/Src/drivers/hc_sr04-driver.cyclo ./Core/Src/drivers/hc_sr04-driver.d ./Core/Src/drivers/hc_sr04-driver.o ./Core/Src/drivers/hc_sr04-driver.su ./Core/Src/drivers/ssd1306-i2c-driver.cyclo ./Core/Src/drivers/ssd1306-i2c-driver.d ./Core/Src/drivers/ssd1306-i2c-driver.o ./Core/Src/drivers/ssd1306-i2c-driver.su ./Core/Src/drivers/ssd1306_font6x8.cyclo ./Core/Src/drivers/ssd1306_font6x8.d ./Core/Src/drivers/ssd1306_font6x8.o ./Core/Src/drivers/ssd1306_font6x8.su ./Core/Src/drivers/systemclock_config.cyclo ./Core/Src/drivers/systemclock_config.d ./Core/Src/drivers/systemclock_config.o ./Core/Src/drivers/systemclock_config.su ./Core/Src/drivers/uart-driver.cyclo ./Core/Src/drivers/uart-driver.d ./Core/Src/drivers/uart-driver.o ./Core/Src/drivers/uart-driver.su

.PHONY: clean-Core-2f-Src-2f-drivers

