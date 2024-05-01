################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Complejo.cpp \
../Poligono.cpp \
../main.cpp 

CPP_DEPS += \
./Complejo.d \
./Poligono.d \
./main.d 

OBJS += \
./Complejo.o \
./Poligono.o \
./main.o 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean--2e-

clean--2e-:
	-$(RM) ./Complejo.d ./Complejo.o ./Poligono.d ./Poligono.o ./main.d ./main.o

.PHONY: clean--2e-

