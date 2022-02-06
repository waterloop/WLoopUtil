# build with debug symbols
DEBUG = 1

# all features enabled by default, change to 0 to exclude from build
RTOS = 1

# board details
BOARD = MASTER_BMS

DEVICE = STM32F405RGTx
DEVICE_VARIANT = STM32F405xx
DEVICE_FAMILY = STM32F4xx

CPU = -mcpu=cortex-m4
FPU = -mfpu=fpv4-sp-d16
FLOAT-ABI = -mfloat-abi=hard
