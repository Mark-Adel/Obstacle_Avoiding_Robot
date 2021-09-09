################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Obstacle_Avoiding_Robot.lss \

FLASH_IMAGE += \
Obstacle_Avoiding_Robot.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Obstacle_Avoiding_Robot.elf secondary-outputs

# Tool invocations
Obstacle_Avoiding_Robot.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Obstacle_Avoiding_Robot.map -mmcu=atmega32 -o "Obstacle_Avoiding_Robot.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Obstacle_Avoiding_Robot.lss: Obstacle_Avoiding_Robot.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Obstacle_Avoiding_Robot.elf  >"Obstacle_Avoiding_Robot.lss"
	@echo 'Finished building: $@'
	@echo ' '

Obstacle_Avoiding_Robot.hex: Obstacle_Avoiding_Robot.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Obstacle_Avoiding_Robot.elf  "Obstacle_Avoiding_Robot.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Obstacle_Avoiding_Robot.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Obstacle_Avoiding_Robot.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Obstacle_Avoiding_Robot.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
