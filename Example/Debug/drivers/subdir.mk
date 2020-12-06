################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/fsl_acmp.c \
../drivers/fsl_adc.c \
../drivers/fsl_clock.c \
../drivers/fsl_common.c \
../drivers/fsl_flash.c \
../drivers/fsl_ftm.c \
../drivers/fsl_gpio.c \
../drivers/fsl_i2c.c \
../drivers/fsl_irq.c \
../drivers/fsl_kbi.c \
../drivers/fsl_mscan.c \
../drivers/fsl_pit.c \
../drivers/fsl_port.c \
../drivers/fsl_pwt.c \
../drivers/fsl_rtc.c \
../drivers/fsl_spi.c \
../drivers/fsl_tpm.c \
../drivers/fsl_uart.c \
../drivers/fsl_wdog8.c 

OBJS += \
./drivers/fsl_acmp.o \
./drivers/fsl_adc.o \
./drivers/fsl_clock.o \
./drivers/fsl_common.o \
./drivers/fsl_flash.o \
./drivers/fsl_ftm.o \
./drivers/fsl_gpio.o \
./drivers/fsl_i2c.o \
./drivers/fsl_irq.o \
./drivers/fsl_kbi.o \
./drivers/fsl_mscan.o \
./drivers/fsl_pit.o \
./drivers/fsl_port.o \
./drivers/fsl_pwt.o \
./drivers/fsl_rtc.o \
./drivers/fsl_spi.o \
./drivers/fsl_tpm.o \
./drivers/fsl_uart.o \
./drivers/fsl_wdog8.o 

C_DEPS += \
./drivers/fsl_acmp.d \
./drivers/fsl_adc.d \
./drivers/fsl_clock.d \
./drivers/fsl_common.d \
./drivers/fsl_flash.d \
./drivers/fsl_ftm.d \
./drivers/fsl_gpio.d \
./drivers/fsl_i2c.d \
./drivers/fsl_irq.d \
./drivers/fsl_kbi.d \
./drivers/fsl_mscan.d \
./drivers/fsl_pit.d \
./drivers/fsl_port.d \
./drivers/fsl_pwt.d \
./drivers/fsl_rtc.d \
./drivers/fsl_spi.d \
./drivers/fsl_tpm.d \
./drivers/fsl_uart.d \
./drivers/fsl_wdog8.d 


# Each subdirectory must supply rules for building sources it contributes
drivers/%.o: ../drivers/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DCPU_MKE06Z128VLD4_cm0plus -DCPU_MKE06Z128VLD4 -I../CMSIS -I../board -I../drivers -I../utilities -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


