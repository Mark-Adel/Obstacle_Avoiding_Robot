################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DC_motor_program.c \
../DIO_fun.c \
../EXTI_progr.c \
../LCD_program.c \
../TIM_Prog.c \
../globel_int.c \
../main.c \
../ultrasonic_prog.c 

OBJS += \
./DC_motor_program.o \
./DIO_fun.o \
./EXTI_progr.o \
./LCD_program.o \
./TIM_Prog.o \
./globel_int.o \
./main.o \
./ultrasonic_prog.o 

C_DEPS += \
./DC_motor_program.d \
./DIO_fun.d \
./EXTI_progr.d \
./LCD_program.d \
./TIM_Prog.d \
./globel_int.d \
./main.d \
./ultrasonic_prog.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


