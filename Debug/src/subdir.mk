################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/BasicAudioTest.c \
../src/Limiter.c \
../src/WhiteNoise.c 

SRC_OBJS += \
./src/BasicAudioTest.doj \
./src/Limiter.doj \
./src/WhiteNoise.doj 

C_DEPS += \
./src/BasicAudioTest.d \
./src/Limiter.d \
./src/WhiteNoise.d 


# Each subdirectory must supply rules for building sources it contributes
src/BasicAudioTest.doj: ../src/BasicAudioTest.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="BasicAudioTest" -proc ADSP-21565 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG @includes-a3bede4f847818f3c632e1ccea8b6e89.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -char-size-8 -swc -gnu-style-dependencies -MD -Mo "src/BasicAudioTest.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/Limiter.doj: ../src/Limiter.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="BasicAudioTest" -proc ADSP-21565 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG @includes-a3bede4f847818f3c632e1ccea8b6e89.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -char-size-8 -swc -gnu-style-dependencies -MD -Mo "src/Limiter.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/WhiteNoise.doj: ../src/WhiteNoise.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="BasicAudioTest" -proc ADSP-21565 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG @includes-a3bede4f847818f3c632e1ccea8b6e89.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -char-size-8 -swc -gnu-style-dependencies -MD -Mo "src/WhiteNoise.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


