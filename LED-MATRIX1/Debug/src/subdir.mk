################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/EXTI0_program.c \
../src/GPIO.c \
../src/IR_program.c \
../src/LED_MATRIX.c \
../src/NVIC_program.c \
../src/RCC_program.c \
../src/SYSTICK_PROG.c \
../src/main.c 

OBJS += \
./src/EXTI0_program.o \
./src/GPIO.o \
./src/IR_program.o \
./src/LED_MATRIX.o \
./src/NVIC_program.o \
./src/RCC_program.o \
./src/SYSTICK_PROG.o \
./src/main.o 

C_DEPS += \
./src/EXTI0_program.d \
./src/GPIO.d \
./src/IR_program.d \
./src/LED_MATRIX.d \
./src/NVIC_program.d \
./src/RCC_program.d \
./src/SYSTICK_PROG.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F10X_MD -DUSE_STDPERIPH_DRIVER -DHSE_VALUE=8000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f1-stdperiph" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


