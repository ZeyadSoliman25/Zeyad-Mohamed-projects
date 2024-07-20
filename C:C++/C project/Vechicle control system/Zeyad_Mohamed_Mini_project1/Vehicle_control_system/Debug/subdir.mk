################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Quit_program.c \
../Turn_off.c \
../Turn_on.c \
../engine_temperature.c \
../main.c \
../room_temperature.c \
../traffic_light.c \
../turn_on_menu.c 

C_DEPS += \
./Quit_program.d \
./Turn_off.d \
./Turn_on.d \
./engine_temperature.d \
./main.d \
./room_temperature.d \
./traffic_light.d \
./turn_on_menu.d 

OBJS += \
./Quit_program.o \
./Turn_off.o \
./Turn_on.o \
./engine_temperature.o \
./main.o \
./room_temperature.o \
./traffic_light.o \
./turn_on_menu.o 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean--2e-

clean--2e-:
	-$(RM) ./Quit_program.d ./Quit_program.o ./Turn_off.d ./Turn_off.o ./Turn_on.d ./Turn_on.o ./engine_temperature.d ./engine_temperature.o ./main.d ./main.o ./room_temperature.d ./room_temperature.o ./traffic_light.d ./traffic_light.o ./turn_on_menu.d ./turn_on_menu.o

.PHONY: clean--2e-

