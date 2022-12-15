################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/admin_recursos/adminrecursos.cpp 

OBJS += \
./src/admin_recursos/adminrecursos.o 

CPP_DEPS += \
./src/admin_recursos/adminrecursos.d 


# Each subdirectory must supply rules for building sources it contributes
src/admin_recursos/%.o: ../src/admin_recursos/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


