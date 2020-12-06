################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../LEDCube/led_cube.cpp 

OBJS += \
./LEDCube/led_cube.o 

CPP_DEPS += \
./LEDCube/led_cube.d 


# Each subdirectory must supply rules for building sources it contributes
LEDCube/%.o: ../LEDCube/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C++ Compiler'
	arm-none-eabi-g++ -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DCPU_MKE06Z128VLD4_cm0plus -DCPU_MKE06Z128VLD4 -I../CMSIS -I../board -I../drivers -I../utilities -std=gnu++11 -fabi-version=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


