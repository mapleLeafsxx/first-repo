################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
src/motor/%.o: ../src/motor/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs2010/ccs/tools/compiler/ti-cgt-armllvm_4.0.2.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"C:/Users/33049/workspace_ccstheia/empty_PRO_LP_MSPM0G3507_nortos_ticlang/inc" -I"C:/Users/33049/workspace_ccstheia/empty_PRO_LP_MSPM0G3507_nortos_ticlang/src" -I"C:/Users/33049/workspace_ccstheia/empty_PRO_LP_MSPM0G3507_nortos_ticlang" -I"C:/Users/33049/workspace_ccstheia/empty_PRO_LP_MSPM0G3507_nortos_ticlang/Debug" -I"C:/ti/mspm0_sdk_2_04_00_06/source/third_party/CMSIS/Core/Include" -I"C:/ti/mspm0_sdk_2_04_00_06/source" -I"C:/Users/33049/workspace_ccstheia/empty_PRO_LP_MSPM0G3507_nortos_ticlang/inc/mpu6050" -gdwarf-3 -MMD -MP -MF"src/motor/$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


