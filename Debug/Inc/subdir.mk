################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Inc/MCP3424.c 

OBJS += \
./Inc/MCP3424.o 

C_DEPS += \
./Inc/MCP3424.d 


# Each subdirectory must supply rules for building sources it contributes
Inc/%.o: ../Inc/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -mfloat-abi=soft '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32L031xx -I"C:/Users/Lenovo/Documents/L031k6_I2C_comparator_test/Inc" -I"C:/Users/Lenovo/Documents/L031k6_I2C_comparator_test/Drivers/STM32L0xx_HAL_Driver/Inc" -I"C:/Users/Lenovo/Documents/L031k6_I2C_comparator_test/Drivers/STM32L0xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Lenovo/Documents/L031k6_I2C_comparator_test/Drivers/CMSIS/Device/ST/STM32L0xx/Include" -I"C:/Users/Lenovo/Documents/L031k6_I2C_comparator_test/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


