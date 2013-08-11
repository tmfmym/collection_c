################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../binary_tree.c \
../hash_map.c \
../list.c \
../list2.c \
../main.c \
../queue_array.c \
../queue_list.c \
../stack_array.c \
../stack_list.c \
../tree_map.c 

OBJS += \
./binary_tree.o \
./hash_map.o \
./list.o \
./list2.o \
./main.o \
./queue_array.o \
./queue_list.o \
./stack_array.o \
./stack_list.o \
./tree_map.o 

C_DEPS += \
./binary_tree.d \
./hash_map.d \
./list.d \
./list2.d \
./main.d \
./queue_array.d \
./queue_list.d \
./stack_array.d \
./stack_list.d \
./tree_map.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -std=c99 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


