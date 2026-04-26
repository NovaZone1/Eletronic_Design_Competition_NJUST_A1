################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
freertos/croutine.o: C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/Source/croutine.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Arm Compiler - building file: "$<"'
	"D:/Software_App/CSS/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/bin/tiarmclang.exe" -c -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -I"D:/Project/MSPM0_Project/MSPM0_Engineering_Template/freertos_builds_LP_MSPM0G3507_release_ticlang" -I"C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/Source/include" -I"C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/Source/portable/TI_ARM_CLANG/ARM_CM0" -I"C:/TI/mspm0_sdk_2_10_00_04/source/third_party/CMSIS/Core/Include" -I"C:/TI/mspm0_sdk_2_10_00_04/source/ti/posix/ticlang" -I"C:/TI/mspm0_sdk_2_10_00_04/source" -I"D:/Software_App/CSS/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/include" -D__MSPM0G3507__ -gdwarf-3 -MMD -MP -MF"freertos/$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

freertos/event_groups.o: C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/Source/event_groups.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Arm Compiler - building file: "$<"'
	"D:/Software_App/CSS/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/bin/tiarmclang.exe" -c -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -I"D:/Project/MSPM0_Project/MSPM0_Engineering_Template/freertos_builds_LP_MSPM0G3507_release_ticlang" -I"C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/Source/include" -I"C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/Source/portable/TI_ARM_CLANG/ARM_CM0" -I"C:/TI/mspm0_sdk_2_10_00_04/source/third_party/CMSIS/Core/Include" -I"C:/TI/mspm0_sdk_2_10_00_04/source/ti/posix/ticlang" -I"C:/TI/mspm0_sdk_2_10_00_04/source" -I"D:/Software_App/CSS/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/include" -D__MSPM0G3507__ -gdwarf-3 -MMD -MP -MF"freertos/$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

freertos/heap_4.o: C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/Source/portable/MemMang/heap_4.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Arm Compiler - building file: "$<"'
	"D:/Software_App/CSS/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/bin/tiarmclang.exe" -c -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -I"D:/Project/MSPM0_Project/MSPM0_Engineering_Template/freertos_builds_LP_MSPM0G3507_release_ticlang" -I"C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/Source/include" -I"C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/Source/portable/TI_ARM_CLANG/ARM_CM0" -I"C:/TI/mspm0_sdk_2_10_00_04/source/third_party/CMSIS/Core/Include" -I"C:/TI/mspm0_sdk_2_10_00_04/source/ti/posix/ticlang" -I"C:/TI/mspm0_sdk_2_10_00_04/source" -I"D:/Software_App/CSS/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/include" -D__MSPM0G3507__ -gdwarf-3 -MMD -MP -MF"freertos/$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

freertos/list.o: C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/Source/list.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Arm Compiler - building file: "$<"'
	"D:/Software_App/CSS/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/bin/tiarmclang.exe" -c -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -I"D:/Project/MSPM0_Project/MSPM0_Engineering_Template/freertos_builds_LP_MSPM0G3507_release_ticlang" -I"C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/Source/include" -I"C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/Source/portable/TI_ARM_CLANG/ARM_CM0" -I"C:/TI/mspm0_sdk_2_10_00_04/source/third_party/CMSIS/Core/Include" -I"C:/TI/mspm0_sdk_2_10_00_04/source/ti/posix/ticlang" -I"C:/TI/mspm0_sdk_2_10_00_04/source" -I"D:/Software_App/CSS/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/include" -D__MSPM0G3507__ -gdwarf-3 -MMD -MP -MF"freertos/$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

freertos/queue.o: C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/Source/queue.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Arm Compiler - building file: "$<"'
	"D:/Software_App/CSS/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/bin/tiarmclang.exe" -c -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -I"D:/Project/MSPM0_Project/MSPM0_Engineering_Template/freertos_builds_LP_MSPM0G3507_release_ticlang" -I"C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/Source/include" -I"C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/Source/portable/TI_ARM_CLANG/ARM_CM0" -I"C:/TI/mspm0_sdk_2_10_00_04/source/third_party/CMSIS/Core/Include" -I"C:/TI/mspm0_sdk_2_10_00_04/source/ti/posix/ticlang" -I"C:/TI/mspm0_sdk_2_10_00_04/source" -I"D:/Software_App/CSS/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/include" -D__MSPM0G3507__ -gdwarf-3 -MMD -MP -MF"freertos/$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

freertos/stream_buffer.o: C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/Source/stream_buffer.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Arm Compiler - building file: "$<"'
	"D:/Software_App/CSS/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/bin/tiarmclang.exe" -c -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -I"D:/Project/MSPM0_Project/MSPM0_Engineering_Template/freertos_builds_LP_MSPM0G3507_release_ticlang" -I"C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/Source/include" -I"C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/Source/portable/TI_ARM_CLANG/ARM_CM0" -I"C:/TI/mspm0_sdk_2_10_00_04/source/third_party/CMSIS/Core/Include" -I"C:/TI/mspm0_sdk_2_10_00_04/source/ti/posix/ticlang" -I"C:/TI/mspm0_sdk_2_10_00_04/source" -I"D:/Software_App/CSS/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/include" -D__MSPM0G3507__ -gdwarf-3 -MMD -MP -MF"freertos/$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

freertos/tasks.o: C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/Source/tasks.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Arm Compiler - building file: "$<"'
	"D:/Software_App/CSS/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/bin/tiarmclang.exe" -c -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -I"D:/Project/MSPM0_Project/MSPM0_Engineering_Template/freertos_builds_LP_MSPM0G3507_release_ticlang" -I"C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/Source/include" -I"C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/Source/portable/TI_ARM_CLANG/ARM_CM0" -I"C:/TI/mspm0_sdk_2_10_00_04/source/third_party/CMSIS/Core/Include" -I"C:/TI/mspm0_sdk_2_10_00_04/source/ti/posix/ticlang" -I"C:/TI/mspm0_sdk_2_10_00_04/source" -I"D:/Software_App/CSS/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/include" -D__MSPM0G3507__ -gdwarf-3 -MMD -MP -MF"freertos/$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

freertos/timers.o: C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/Source/timers.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Arm Compiler - building file: "$<"'
	"D:/Software_App/CSS/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/bin/tiarmclang.exe" -c -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -I"D:/Project/MSPM0_Project/MSPM0_Engineering_Template/freertos_builds_LP_MSPM0G3507_release_ticlang" -I"C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/Source/include" -I"C:/TI/mspm0_sdk_2_10_00_04/kernel/freertos/Source/portable/TI_ARM_CLANG/ARM_CM0" -I"C:/TI/mspm0_sdk_2_10_00_04/source/third_party/CMSIS/Core/Include" -I"C:/TI/mspm0_sdk_2_10_00_04/source/ti/posix/ticlang" -I"C:/TI/mspm0_sdk_2_10_00_04/source" -I"D:/Software_App/CSS/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/include" -D__MSPM0G3507__ -gdwarf-3 -MMD -MP -MF"freertos/$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


