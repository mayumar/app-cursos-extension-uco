################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/estadisticas/estadisticas.cpp 

OBJS += \
./src/estadisticas/estadisticas.o 

CPP_DEPS += \
./src/estadisticas/estadisticas.d 


# Each subdirectory must supply rules for building sources it contributes
src/estadisticas/%.o: ../src/estadisticas/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


