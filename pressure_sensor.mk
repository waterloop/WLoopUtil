# build with debug symbols
DEBUG = 1

# all features enabled by default, change to 0 to exclude from build
RTOS = 1

# board details
BOARD = PRESSURE_SENSOR

DEVICE = STM32F303K6Tx
DEVICE_VARIANT = STM32F303x8
DEVICE_FAMILY = STM32F3xx

CPU = -mcpu=cortex-m4
FPU = -mfpu=fpv4-sp-d16
FLOAT-ABI = -mfloat-abi=hard
