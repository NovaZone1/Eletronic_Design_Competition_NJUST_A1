################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := D:/Software_App/CSS/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./dpl/AppHooks_freertos.o" \
"./dpl/ClockP_freertos.o" \
"./dpl/DebugP_freertos.o" \
"./dpl/HwiPMSPM0_freertos.o" \
"./dpl/MutexP_freertos.o" \
"./dpl/SemaphoreP_freertos.o" \
"./dpl/StaticAllocs_freertos.o" \
"./dpl/SystemP_freertos.o" \
"./dpl/TaskP_freertos.o" \
"./freertos/croutine.o" \
"./freertos/event_groups.o" \
"./freertos/heap_4.o" \
"./freertos/list.o" \
"./freertos/queue.o" \
"./freertos/stream_buffer.o" \
"./freertos/tasks.o" \
"./freertos/timers.o" \
"./freertos/portable/TI_ARM_CLANG/ARM_CM0/port.o" \
"./freertos/portable/TI_ARM_CLANG/ARM_CM0/portasm.o" \
"./freertos/startup/startup_mspm0g350x_ticlang.o" \
"./posix/PTLS.o" \
"./posix/aeabi_portable.o" \
"./posix/clock.o" \
"./posix/memory.o" \
"./posix/mqueue.o" \
"./posix/pthread.o" \
"./posix/pthread_barrier.o" \
"./posix/pthread_cond.o" \
"./posix/pthread_mutex.o" \
"./posix/pthread_rwlock.o" \
"./posix/sched.o" \
"./posix/semaphore.o" \
"./posix/sleep.o" \
"./posix/timer.o" \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include dpl/subdir_vars.mk
-include freertos/subdir_vars.mk
-include freertos/portable/TI_ARM_CLANG/ARM_CM0/subdir_vars.mk
-include freertos/startup/subdir_vars.mk
-include posix/subdir_vars.mk
-include dpl/subdir_rules.mk
-include freertos/subdir_rules.mk
-include freertos/portable/TI_ARM_CLANG/ARM_CM0/subdir_rules.mk
-include freertos/startup/subdir_rules.mk
-include posix/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LIB_OUTPUTS += \
freertos_builds_LP_MSPM0G3507_release_ticlang.lib 

LIB_OUTPUTS__QUOTED += \
"freertos_builds_LP_MSPM0G3507_release_ticlang.lib" 


# All Target
all: freertos_builds_LP_MSPM0G3507_release_ticlang.lib

# Tool invocations
freertos_builds_LP_MSPM0G3507_release_ticlang.lib: $(OBJS)
ifneq ($(strip $(ORDERED_OBJS)),)
	@echo 'Arm Archiver - building target: "$@"'
	"D:/Software_App/CSS/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/bin/tiarmar.exe" rc "freertos_builds_LP_MSPM0G3507_release_ticlang.lib" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '
endif

# Other Targets
clean:
	-$(RM) $(LIB_OUTPUTS__QUOTED)
	-$(RM) "dpl\AppHooks_freertos.o" "dpl\ClockP_freertos.o" "dpl\DebugP_freertos.o" "dpl\HwiPMSPM0_freertos.o" "dpl\MutexP_freertos.o" "dpl\SemaphoreP_freertos.o" "dpl\StaticAllocs_freertos.o" "dpl\SystemP_freertos.o" "dpl\TaskP_freertos.o" "freertos\croutine.o" "freertos\event_groups.o" "freertos\heap_4.o" "freertos\list.o" "freertos\queue.o" "freertos\stream_buffer.o" "freertos\tasks.o" "freertos\timers.o" "freertos\portable\TI_ARM_CLANG\ARM_CM0\port.o" "freertos\portable\TI_ARM_CLANG\ARM_CM0\portasm.o" "freertos\startup\startup_mspm0g350x_ticlang.o" "posix\PTLS.o" "posix\aeabi_portable.o" "posix\clock.o" "posix\memory.o" "posix\mqueue.o" "posix\pthread.o" "posix\pthread_barrier.o" "posix\pthread_cond.o" "posix\pthread_mutex.o" "posix\pthread_rwlock.o" "posix\sched.o" "posix\semaphore.o" "posix\sleep.o" "posix\timer.o" 
	-$(RM) "dpl\AppHooks_freertos.d" "dpl\ClockP_freertos.d" "dpl\DebugP_freertos.d" "dpl\HwiPMSPM0_freertos.d" "dpl\MutexP_freertos.d" "dpl\SemaphoreP_freertos.d" "dpl\StaticAllocs_freertos.d" "dpl\SystemP_freertos.d" "dpl\TaskP_freertos.d" "freertos\croutine.d" "freertos\event_groups.d" "freertos\heap_4.d" "freertos\list.d" "freertos\queue.d" "freertos\stream_buffer.d" "freertos\tasks.d" "freertos\timers.d" "freertos\portable\TI_ARM_CLANG\ARM_CM0\port.d" "freertos\portable\TI_ARM_CLANG\ARM_CM0\portasm.d" "freertos\startup\startup_mspm0g350x_ticlang.d" "posix\PTLS.d" "posix\aeabi_portable.d" "posix\clock.d" "posix\memory.d" "posix\mqueue.d" "posix\pthread.d" "posix\pthread_barrier.d" "posix\pthread_cond.d" "posix\pthread_mutex.d" "posix\pthread_rwlock.d" "posix\sched.d" "posix\semaphore.d" "posix\sleep.d" "posix\timer.d" 
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

