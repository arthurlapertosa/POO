################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Banco.cpp \
../Cliente.cpp \
../Conta.cpp \
../Interface.cpp \
../Movimentacao.cpp \
../main.cpp 

OBJS += \
./Banco.o \
./Cliente.o \
./Conta.o \
./Interface.o \
./Movimentacao.o \
./main.o 

CPP_DEPS += \
./Banco.d \
./Cliente.d \
./Conta.d \
./Interface.d \
./Movimentacao.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


