################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
posix/PTLS.o: C:/TI/mspm0_sdk_2_10_00_04/source/ti/posix/freertos/PTLS.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Arm Compiler - building file: "$<"'
	"D:/Software_App/CSS/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/bin/tiarmclang.exe" -c -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -I"D:/Project/MSPM0_Project/MSPM0_Engineering_Template/freertos_builds_LP_MSPM0G3507_release_ticlang" -I"C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/Source/include" -I"C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/Source/portable/TI_ARM_CLANG/ARM_CM0" -I"C:/TI/mspm0_sdk_2_10_00_04/source/third_party/CMSIS/Core/Include" -I"C:/TI/mspm0_sdk_2_10_00_04/source/ti/posix/ticlang" -I"C:/TI/mspm0_sdk_2_10_00_04/source" -I"D:/Software_App/CSS/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/include" -D__MSPM0G3507__ -gdwarf-3 -MMD -MP -MF"posix/$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

posix/aeabi_portable.o: C:/TI/mspm0_sdk_2_10_00_04/source/ti/posix/freertos/aeabi_portable.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Arm Compiler - building file: "$<"'
	"D:/Software_App/CSS/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/bin/tiarmclang.exe" -c -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -I"D:/Project/MSPM0_Project/MSPM0_Engineering_Template/freertos_builds_LP_MSPM0G3507_release_ticlang" -I"C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/Source/include" -I"C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/Source/portable/TI_ARM_CLANG/ARM_CM0" -I"C:/TI/mspm0_sdk_2_10_00_04/source/third_party/CMSIS/Core/Include" -I"C:/TI/mspm0_sdk_2_10_00_04/source/ti/posix/ticlang" -I"C:/TI/mspm0_sdk_2_10_00_04/source" -I"D:/Software_App/CSS/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/include" -D__MSPM0G3507__ -gdwarf-3 -MMD -MP -MF"posix/$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

posix/clock.o: C:/TI/mspm0_sdk_2_10_00_04/source/ti/posix/freertos/clock.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Arm Compiler - building file: "$<"'
	"D:/Software_App/CSS/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/bin/tiarmclang.exe" -c -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -I"D:/Project/MSPM0_Project/MSPM0_Engineering_Template/freertos_builds_LP_MSPM0G3507_release_ticlang" -I"C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/Source/include" -I"C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/Source/portable/TI_ARM_CLANG/ARM_CM0" -I"C:/TI/mspm0_sdk_2_10_00_04/source/third_party/CMSIS/Core/Include" -I"C:/TI/mspm0_sdk_2_10_00_04/source/ti/posix/ticlang" -I"C:/TI/mspm0_sdk_2_10_00_04/source" -I"D:/Software_App/CSS/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/include" -D__MSPM0G3507__ -gdwarf-3 -MMD -MP -MF"posix/$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

posix/memory.o: C:/TI/mspm0_sdk_2_10_00_04/source/ti/posix/freertos/memory.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Arm Compiler - building file: "$<"'
	"D:/Software_App/CSS/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/bin/tiarmclang.exe" -c -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -I"D:/Project/MSPM0_Project/MSPM0_Engineering_Template/freertos_builds_LP_MSPM0G3507_release_ticlang" -I"C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/Source/include" -I"C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/Source/portable/TI_ARM_CLANG/ARM_CM0" -I"C:/TI/mspm0_sdk_2_10_00_04/source/third_party/CMSIS/Core/Include" -I"C:/TI/mspm0_sdk_2_10_00_04/source/ti/posix/ticlang" -I"C:/TI/mspm0_sdk_2_10_00_04/source" -I"D:/Software_App/CSS/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/include" -D__MSPM0G3507__ -gdwarf-3 -MMD -MP -MF"posix/$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

posix/mqueue.o: C:/TI/mspm0_sdk_2_10_00_04/source/ti/posix/freertos/mqueue.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Arm Compiler - building file: "$<"'
	"D:/Software_App/CSS/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/bin/tiarmclang.exe" -c -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -I"D:/Project/MSPM0_Project/MSPM0_Engineering_Template/freertos_builds_LP_MSPM0G3507_release_ticlang" -I"C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/Source/include" -I"C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/Source/portable/TI_ARM_CLANG/ARM_CM0" -I"C:/TI/mspm0_sdk_2_10_00_04/source/third_party/CMSIS/Core/Include" -I"C:/TI/mspm0_sdk_2_10_00_04/source/ti/posix/ticlang" -I"C:/TI/mspm0_sdk_2_10_00_04/source" -I"D:/Software_App/CSS/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/include" -D__MSPM0G3507__ -gdwarf-3 -MMD -MP -MF"posix/$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

posix/pthread.o: C:/TI/mspm0_sdk_2_10_00_04/source/ti/posix/freertos/pthread.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Arm Compiler - building file: "$<"'
	"D:/Software_App/CSS/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/bin/tiarmclang.exe" -c -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -I"D:/Project/MSPM0_Project/MSPM0_Engineering_Template/freertos_builds_LP_MSPM0G3507_release_ticlang" -I"C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/Source/include" -I"C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/Source/portable/TI_ARM_CLANG/ARM_CM0" -I"C:/TI/mspm0_sdk_2_10_00_04/source/third_party/CMSIS/Core/Include" -I"C:/TI/mspm0_sdk_2_10_00_04/source/ti/posix/ticlang" -I"C:/TI/mspm0_sdk_2_10_00_04/source" -I"D:/Software_App/CSS/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/include" -D__MSPM0G3507__ -gdwarf-3 -MMD -MP -MF"posix/$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

posix/pthread_barrier.o: C:/TI/mspm0_sdk_2_10_00_04/source/ti/posix/freertos/pthread_barrier.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Arm Compiler - building file: "$<"'
	"D:/Software_App/CSS/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/bin/tiarmclang.exe" -c -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -I"D:/Project/MSPM0_Project/MSPM0_Engineering_Template/freertos_builds_LP_MSPM0G3507_release_ticlang" -I"C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/Source/include" -I"C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/Source/portable/TI_ARM_CLANG/ARM_CM0" -I"C:/TI/mspm0_sdk_2_10_00_04/source/third_party/CMSIS/Core/Include" -I"C:/TI/mspm0_sdk_2_10_00_04/source/ti/posix/ticlang" -I"C:/TI/mspm0_sdk_2_10_00_04/source" -I"D:/Software_App/CSS/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/include" -D__MSPM0G3507__ -gdwarf-3 -MMD -MP -MF"posix/$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

posix/pthread_cond.o: C:/TI/mspm0_sdk_2_10_00_04/source/ti/posix/freertos/pthread_cond.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Arm Compiler - building file: "$<"'
	"D:/Software_App/CSS/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/bin/tiarmclang.exe" -c -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -I"D:/Project/MSPM0_Project/MSPM0_Engineering_Template/freertos_builds_LP_MSPM0G3507_release_ticlang" -I"C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/Source/include" -I"C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/Source/portable/TI_ARM_CLANG/ARM_CM0" -I"C:/TI/mspm0_sdk_2_10_00_04/source/third_party/CMSIS/Core/Include" -I"C:/TI/mspm0_sdk_2_10_00_04/source/ti/posix/ticlang" -I"C:/TI/mspm0_sdk_2_10_00_04/source" -I"D:/Software_App/CSS/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/include" -D__MSPM0G3507__ -gdwarf-3 -MMD -MP -MF"posix/$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

posix/pthread_mutex.o: C:/TI/mspm0_sdk_2_10_00_04/source/ti/posix/freertos/pthread_mutex.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Arm Compiler - building file: "$<"'
	"D:/Software_App/CSS/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/bin/tiarmclang.exe" -c -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -I"D:/Project/MSPM0_Project/MSPM0_Engineering_Template/freertos_builds_LP_MSPM0G3507_release_ticlang" -I"C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/Source/include" -I"C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/Source/portable/TI_ARM_CLANG/ARM_CM0" -I"C:/TI/mspm0_sdk_2_10_00_04/source/third_party/CMSIS/Core/Include" -I"C:/TI/mspm0_sdk_2_10_00_04/source/ti/posix/ticlang" -I"C:/TI/mspm0_sdk_2_10_00_04/source" -I"D:/Software_App/CSS/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/include" -D__MSPM0G3507__ -gdwarf-3 -MMD -MP -MF"posix/$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

posix/pthread_rwlock.o: C:/TI/mspm0_sdk_2_10_00_04/source/ti/posix/freertos/pthread_rwlock.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Arm Compiler - building file: "$<"'
	"D:/Software_App/CSS/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/bin/tiarmclang.exe" -c -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -I"D:/Project/MSPM0_Project/MSPM0_Engineering_Template/freertos_builds_LP_MSPM0G3507_release_ticlang" -I"C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/Source/include" -I"C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/Source/portable/TI_ARM_CLANG/ARM_CM0" -I"C:/TI/mspm0_sdk_2_10_00_04/source/third_party/CMSIS/Core/Include" -I"C:/TI/mspm0_sdk_2_10_00_04/source/ti/posix/ticlang" -I"C:/TI/mspm0_sdk_2_10_00_04/source" -I"D:/Software_App/CSS/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/include" -D__MSPM0G3507__ -gdwarf-3 -MMD -MP -MF"posix/$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

posix/sched.o: C:/TI/mspm0_sdk_2_10_00_04/source/ti/posix/freertos/sched.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Arm Compiler - building file: "$<"'
	"D:/Software_App/CSS/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/bin/tiarmclang.exe" -c -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -I"D:/Project/MSPM0_Project/MSPM0_Engineering_Template/freertos_builds_LP_MSPM0G3507_release_ticlang" -I"C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/Source/include" -I"C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/Source/portable/TI_ARM_CLANG/ARM_CM0" -I"C:/TI/mspm0_sdk_2_10_00_04/source/third_party/CMSIS/Core/Include" -I"C:/TI/mspm0_sdk_2_10_00_04/source/ti/posix/ticlang" -I"C:/TI/mspm0_sdk_2_10_00_04/source" -I"D:/Software_App/CSS/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/include" -D__MSPM0G3507__ -gdwarf-3 -MMD -MP -MF"posix/$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

posix/semaphore.o: C:/TI/mspm0_sdk_2_10_00_04/source/ti/posix/freertos/semaphore.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Arm Compiler - building file: "$<"'
	"D:/Software_App/CSS/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/bin/tiarmclang.exe" -c -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -I"D:/Project/MSPM0_Project/MSPM0_Engineering_Template/freertos_builds_LP_MSPM0G3507_release_ticlang" -I"C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/Source/include" -I"C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/Source/portable/TI_ARM_CLANG/ARM_CM0" -I"C:/TI/mspm0_sdk_2_10_00_04/source/third_party/CMSIS/Core/Include" -I"C:/TI/mspm0_sdk_2_10_00_04/source/ti/posix/ticlang" -I"C:/TI/mspm0_sdk_2_10_00_04/source" -I"D:/Software_App/CSS/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/include" -D__MSPM0G3507__ -gdwarf-3 -MMD -MP -MF"posix/$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

posix/sleep.o: C:/TI/mspm0_sdk_2_10_00_04/source/ti/posix/freertos/sleep.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Arm Compiler - building file: "$<"'
	"D:/Software_App/CSS/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/bin/tiarmclang.exe" -c -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -I"D:/Project/MSPM0_Project/MSPM0_Engineering_Template/freertos_builds_LP_MSPM0G3507_release_ticlang" -I"C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/Source/include" -I"C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/Source/portable/TI_ARM_CLANG/ARM_CM0" -I"C:/TI/mspm0_sdk_2_10_00_04/source/third_party/CMSIS/Core/Include" -I"C:/TI/mspm0_sdk_2_10_00_04/source/ti/posix/ticlang" -I"C:/TI/mspm0_sdk_2_10_00_04/source" -I"D:/Software_App/CSS/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/include" -D__MSPM0G3507__ -gdwarf-3 -MMD -MP -MF"posix/$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

posix/timer.o: C:/TI/mspm0_sdk_2_10_00_04/source/ti/posix/freertos/timer.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Arm Compiler - building file: "$<"'
	"D:/Software_App/CSS/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/bin/tiarmclang.exe" -c -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -I"D:/Project/MSPM0_Project/MSPM0_Engineering_Template/freertos_builds_LP_MSPM0G3507_release_ticlang" -I"C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/Source/include" -I"C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/Source/portable/TI_ARM_CLANG/ARM_CM0" -I"C:/TI/mspm0_sdk_2_10_00_04/source/third_party/CMSIS/Core/Include" -I"C:/TI/mspm0_sdk_2_10_00_04/source/ti/posix/ticlang" -I"C:/TI/mspm0_sdk_2_10_00_04/source" -I"D:/Software_App/CSS/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/include" -D__MSPM0G3507__ -gdwarf-3 -MMD -MP -MF"posix/$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


