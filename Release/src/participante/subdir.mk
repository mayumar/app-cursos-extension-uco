################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/participante/participante.cpp 

OBJS += \
./src/participante/participante.o 

CPP_DEPS += \
./src/participante/participante.d 


# Each subdirectory must supply rules for building sources it contributes
src/participante/%.o: ../src/participante/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


