################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
dpl/AppHooks_freertos.o: C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/dpl/AppHooks_freertos.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Arm Compiler - building file: "$<"'
	"D:/Software_App/CSS/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/bin/tiarmclang.exe" -c -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -I"D:/Project/MSPM0_Project/MSPM0_Engineering_Template/freertos_builds_LP_MSPM0G3507_release_ticlang" -I"C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/Source/include" -I"C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/Source/portable/TI_ARM_CLANG/ARM_CM0" -I"C:/TI/mspm0_sdk_2_10_00_04/source/third_party/CMSIS/Core/Include" -I"C:/TI/mspm0_sdk_2_10_00_04/source/ti/posix/ticlang" -I"C:/TI/mspm0_sdk_2_10_00_04/source" -I"D:/Software_App/CSS/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/include" -D__MSPM0G3507__ -gdwarf-3 -MMD -MP -MF"dpl/$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

dpl/ClockP_freertos.o: C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/dpl/ClockP_freertos.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Arm Compiler - building file: "$<"'
	"D:/Software_App/CSS/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/bin/tiarmclang.exe" -c -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -I"D:/Project/MSPM0_Project/MSPM0_Engineering_Template/freertos_builds_LP_MSPM0G3507_release_ticlang" -I"C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/Source/include" -I"C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/Source/portable/TI_ARM_CLANG/ARM_CM0" -I"C:/TI/mspm0_sdk_2_10_00_04/source/third_party/CMSIS/Core/Include" -I"C:/TI/mspm0_sdk_2_10_00_04/source/ti/posix/ticlang" -I"C:/TI/mspm0_sdk_2_10_00_04/source" -I"D:/Software_App/CSS/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/include" -D__MSPM0G3507__ -gdwarf-3 -MMD -MP -MF"dpl/$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

dpl/DebugP_freertos.o: C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/dpl/DebugP_freertos.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Arm Compiler - building file: "$<"'
	"D:/Software_App/CSS/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/bin/tiarmclang.exe" -c -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -I"D:/Project/MSPM0_Project/MSPM0_Engineering_Template/freertos_builds_LP_MSPM0G3507_release_ticlang" -I"C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/Source/include" -I"C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/Source/portable/TI_ARM_CLANG/ARM_CM0" -I"C:/TI/mspm0_sdk_2_10_00_04/source/third_party/CMSIS/Core/Include" -I"C:/TI/mspm0_sdk_2_10_00_04/source/ti/posix/ticlang" -I"C:/TI/mspm0_sdk_2_10_00_04/source" -I"D:/Software_App/CSS/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/include" -D__MSPM0G3507__ -gdwarf-3 -MMD -MP -MF"dpl/$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

dpl/HwiPMSPM0_freertos.o: C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/dpl/HwiPMSPM0_freertos.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Arm Compiler - building file: "$<"'
	"D:/Software_App/CSS/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/bin/tiarmclang.exe" -c -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -I"D:/Project/MSPM0_Project/MSPM0_Engineering_Template/freertos_builds_LP_MSPM0G3507_release_ticlang" -I"C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/Source/include" -I"C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/Source/portable/TI_ARM_CLANG/ARM_CM0" -I"C:/TI/mspm0_sdk_2_10_00_04/source/third_party/CMSIS/Core/Include" -I"C:/TI/mspm0_sdk_2_10_00_04/source/ti/posix/ticlang" -I"C:/TI/mspm0_sdk_2_10_00_04/source" -I"D:/Software_App/CSS/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/include" -D__MSPM0G3507__ -gdwarf-3 -MMD -MP -MF"dpl/$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

dpl/MutexP_freertos.o: C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/dpl/MutexP_freertos.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Arm Compiler - building file: "$<"'
	"D:/Software_App/CSS/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/bin/tiarmclang.exe" -c -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -I"D:/Project/MSPM0_Project/MSPM0_Engineering_Template/freertos_builds_LP_MSPM0G3507_release_ticlang" -I"C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/Source/include" -I"C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/Source/portable/TI_ARM_CLANG/ARM_CM0" -I"C:/TI/mspm0_sdk_2_10_00_04/source/third_party/CMSIS/Core/Include" -I"C:/TI/mspm0_sdk_2_10_00_04/source/ti/posix/ticlang" -I"C:/TI/mspm0_sdk_2_10_00_04/source" -I"D:/Software_App/CSS/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/include" -D__MSPM0G3507__ -gdwarf-3 -MMD -MP -MF"dpl/$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

dpl/SemaphoreP_freertos.o: C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/dpl/SemaphoreP_freertos.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Arm Compiler - building file: "$<"'
	"D:/Software_App/CSS/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/bin/tiarmclang.exe" -c -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -I"D:/Project/MSPM0_Project/MSPM0_Engineering_Template/freertos_builds_LP_MSPM0G3507_release_ticlang" -I"C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/Source/include" -I"C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/Source/portable/TI_ARM_CLANG/ARM_CM0" -I"C:/TI/mspm0_sdk_2_10_00_04/source/third_party/CMSIS/Core/Include" -I"C:/TI/mspm0_sdk_2_10_00_04/source/ti/posix/ticlang" -I"C:/TI/mspm0_sdk_2_10_00_04/source" -I"D:/Software_App/CSS/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/include" -D__MSPM0G3507__ -gdwarf-3 -MMD -MP -MF"dpl/$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

dpl/StaticAllocs_freertos.o: C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/dpl/StaticAllocs_freertos.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Arm Compiler - building file: "$<"'
	"D:/Software_App/CSS/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/bin/tiarmclang.exe" -c -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -I"D:/Project/MSPM0_Project/MSPM0_Engineering_Template/freertos_builds_LP_MSPM0G3507_release_ticlang" -I"C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/Source/include" -I"C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/Source/portable/TI_ARM_CLANG/ARM_CM0" -I"C:/TI/mspm0_sdk_2_10_00_04/source/third_party/CMSIS/Core/Include" -I"C:/TI/mspm0_sdk_2_10_00_04/source/ti/posix/ticlang" -I"C:/TI/mspm0_sdk_2_10_00_04/source" -I"D:/Software_App/CSS/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/include" -D__MSPM0G3507__ -gdwarf-3 -MMD -MP -MF"dpl/$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

dpl/SystemP_freertos.o: C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/dpl/SystemP_freertos.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Arm Compiler - building file: "$<"'
	"D:/Software_App/CSS/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/bin/tiarmclang.exe" -c -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -I"D:/Project/MSPM0_Project/MSPM0_Engineering_Template/freertos_builds_LP_MSPM0G3507_release_ticlang" -I"C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/Source/include" -I"C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/Source/portable/TI_ARM_CLANG/ARM_CM0" -I"C:/TI/mspm0_sdk_2_10_00_04/source/third_party/CMSIS/Core/Include" -I"C:/TI/mspm0_sdk_2_10_00_04/source/ti/posix/ticlang" -I"C:/TI/mspm0_sdk_2_10_00_04/source" -I"D:/Software_App/CSS/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/include" -D__MSPM0G3507__ -gdwarf-3 -MMD -MP -MF"dpl/$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

dpl/TaskP_freertos.o: C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/dpl/TaskP_freertos.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Arm Compiler - building file: "$<"'
	"D:/Software_App/CSS/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/bin/tiarmclang.exe" -c -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -I"D:/Project/MSPM0_Project/MSPM0_Engineering_Template/freertos_builds_LP_MSPM0G3507_release_ticlang" -I"C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/Source/include" -I"C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/Source/portable/TI_ARM_CLANG/ARM_CM0" -I"C:/TI/mspm0_sdk_2_10_00_04/source/third_party/CMSIS/Core/Include" -I"C:/TI/mspm0_sdk_2_10_00_04/source/ti/posix/ticlang" -I"C:/TI/mspm0_sdk_2_10_00_04/source" -I"D:/Software_App/CSS/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/include" -D__MSPM0G3507__ -gdwarf-3 -MMD -MP -MF"dpl/$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


