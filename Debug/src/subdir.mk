################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/BasicAudioTest.c \
../src/Filter.c \
../src/FisOrdAllPassErr.c \
../src/FisOrdHigPassErr.c \
../src/FisOrdLowPassErr.c \
../src/Limiter.c \
../src/RecoPara.c \
../src/SecOrdAllPassErr.c \
../src/SecOrdHigPassErr.c \
../src/SecOrdLowPassErr.c \
../src/SecOrdLowShelfErr.c \
../src/Transfunc.c \
../src/Volume.c \
../src/WhiteNoise.c \
../src/peakingErr.c 

SRC_OBJS += \
./src/BasicAudioTest.doj \
./src/Filter.doj \
./src/FisOrdAllPassErr.doj \
./src/FisOrdHigPassErr.doj \
./src/FisOrdLowPassErr.doj \
./src/Limiter.doj \
./src/RecoPara.doj \
./src/SecOrdAllPassErr.doj \
./src/SecOrdHigPassErr.doj \
./src/SecOrdLowPassErr.doj \
./src/SecOrdLowShelfErr.doj \
./src/Transfunc.doj \
./src/Volume.doj \
./src/WhiteNoise.doj \
./src/peakingErr.doj 

C_DEPS += \
./src/BasicAudioTest.d \
./src/Filter.d \
./src/FisOrdAllPassErr.d \
./src/FisOrdHigPassErr.d \
./src/FisOrdLowPassErr.d \
./src/Limiter.d \
./src/RecoPara.d \
./src/SecOrdAllPassErr.d \
./src/SecOrdHigPassErr.d \
./src/SecOrdLowPassErr.d \
./src/SecOrdLowShelfErr.d \
./src/Transfunc.d \
./src/Volume.d \
./src/WhiteNoise.d \
./src/peakingErr.d 


# Each subdirectory must supply rules for building sources it contributes
src/BasicAudioTest.doj: ../src/BasicAudioTest.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="BasicAudioTest" -proc ADSP-21565 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG @includes-a3bede4f847818f3c632e1ccea8b6e89.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -char-size-8 -swc -gnu-style-dependencies -MD -Mo "src/BasicAudioTest.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/Filter.doj: ../src/Filter.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="BasicAudioTest" -proc ADSP-21565 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG @includes-a3bede4f847818f3c632e1ccea8b6e89.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -char-size-8 -swc -gnu-style-dependencies -MD -Mo "src/Filter.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/FisOrdAllPassErr.doj: ../src/FisOrdAllPassErr.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="BasicAudioTest" -proc ADSP-21565 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG @includes-a3bede4f847818f3c632e1ccea8b6e89.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -char-size-8 -swc -gnu-style-dependencies -MD -Mo "src/FisOrdAllPassErr.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/FisOrdHigPassErr.doj: ../src/FisOrdHigPassErr.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="BasicAudioTest" -proc ADSP-21565 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG @includes-a3bede4f847818f3c632e1ccea8b6e89.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -char-size-8 -swc -gnu-style-dependencies -MD -Mo "src/FisOrdHigPassErr.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/FisOrdLowPassErr.doj: ../src/FisOrdLowPassErr.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="BasicAudioTest" -proc ADSP-21565 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG @includes-a3bede4f847818f3c632e1ccea8b6e89.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -char-size-8 -swc -gnu-style-dependencies -MD -Mo "src/FisOrdLowPassErr.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/Limiter.doj: ../src/Limiter.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="BasicAudioTest" -proc ADSP-21565 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG @includes-a3bede4f847818f3c632e1ccea8b6e89.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -char-size-8 -swc -gnu-style-dependencies -MD -Mo "src/Limiter.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/RecoPara.doj: ../src/RecoPara.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="BasicAudioTest" -proc ADSP-21565 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG @includes-a3bede4f847818f3c632e1ccea8b6e89.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -char-size-8 -swc -gnu-style-dependencies -MD -Mo "src/RecoPara.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/SecOrdAllPassErr.doj: ../src/SecOrdAllPassErr.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="BasicAudioTest" -proc ADSP-21565 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG @includes-a3bede4f847818f3c632e1ccea8b6e89.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -char-size-8 -swc -gnu-style-dependencies -MD -Mo "src/SecOrdAllPassErr.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/SecOrdHigPassErr.doj: ../src/SecOrdHigPassErr.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="BasicAudioTest" -proc ADSP-21565 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG @includes-a3bede4f847818f3c632e1ccea8b6e89.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -char-size-8 -swc -gnu-style-dependencies -MD -Mo "src/SecOrdHigPassErr.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/SecOrdLowPassErr.doj: ../src/SecOrdLowPassErr.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="BasicAudioTest" -proc ADSP-21565 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG @includes-a3bede4f847818f3c632e1ccea8b6e89.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -char-size-8 -swc -gnu-style-dependencies -MD -Mo "src/SecOrdLowPassErr.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/SecOrdLowShelfErr.doj: ../src/SecOrdLowShelfErr.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="BasicAudioTest" -proc ADSP-21565 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG @includes-a3bede4f847818f3c632e1ccea8b6e89.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -char-size-8 -swc -gnu-style-dependencies -MD -Mo "src/SecOrdLowShelfErr.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/Transfunc.doj: ../src/Transfunc.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="BasicAudioTest" -proc ADSP-21565 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG @includes-a3bede4f847818f3c632e1ccea8b6e89.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -char-size-8 -swc -gnu-style-dependencies -MD -Mo "src/Transfunc.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/Volume.doj: ../src/Volume.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="BasicAudioTest" -proc ADSP-21565 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG @includes-a3bede4f847818f3c632e1ccea8b6e89.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -char-size-8 -swc -gnu-style-dependencies -MD -Mo "src/Volume.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/WhiteNoise.doj: ../src/WhiteNoise.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="BasicAudioTest" -proc ADSP-21565 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG @includes-a3bede4f847818f3c632e1ccea8b6e89.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -char-size-8 -swc -gnu-style-dependencies -MD -Mo "src/WhiteNoise.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/peakingErr.doj: ../src/peakingErr.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="BasicAudioTest" -proc ADSP-21565 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG @includes-a3bede4f847818f3c632e1ccea8b6e89.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -char-size-8 -swc -gnu-style-dependencies -MD -Mo "src/peakingErr.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


