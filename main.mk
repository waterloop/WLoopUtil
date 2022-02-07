include $(BOARD_VARS)

TARGET = wloop_util.a

CC = arm-none-eabi-gcc
CP = arm-none-eabi-gcc-objcopy
SZ = arm-none-eabi-size
AR = arm-none-eabi-ar
CPP_CC = arm-none-eabi-g++ -std=c++11

OPT = -Og

ifeq ($(RTOS), 1)
	C_SOURCES = $(wildcard ./rtos/src/*.c)
	CPP_SOURCES = $(wildcard ./rtos/src/*.cpp)
endif

C_INCLUDES = \
-I ./rtos/inc \
-I ../$(DEVICE)/Core/Inc \
-I ../$(DEVICE)/Middlewares/Third_Party/FreeRTOS/Source/include \
-I ../$(DEVICE)/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 \
-I ../$(DEVICE)/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F \

C_DEFS = \
-D $(DEVICE_VARIANT) \
-D $(BOARD)

ifeq ($(DEBUG), 1)
	-D += DEBUG
endif

MCU = $(CPU) -mthumb $(FPU) $(FLOAT-ABI)

C_FLAGS = $(C_INCLUDES) $(C_DEFS) $(MCU) $(OPT) -ffunction-sections -fdata-sections -Wall -MMD -MP -MF"$(@:%.o=%.d)"

ifeq ($(DEBUG), 1)
	C_FLAGS += -ggdb
endif

# c objects
OBJECTS = $(addprefix $(BUILD_DIR)/,$(notdir $(C_SOURCES:.c=.o)))

# cpp objects
OBJECTS += $(addprefix $(BUILD_DIR)/,$(notdir $(CPP_SOURCES:.cpp=.o)))

.PHONY: all run clean

all: $(BUILD_DIR)/$(TARGET)

$(BUILD_DIR)/$(TARGET): $(OBJECTS) | $(BUILD_DIR)
	$(AR) rvs $(BUILD_DIR)/$(TARGET) $(OBJECTS)
	@echo ""
	$(SZ) $@
	@echo ""

$(BUILD_DIR)/%.o: ./*/src/%.c | $(BUILD_DIR)
	$(CC) -c $(C_FLAGS) -Wa,-a,-ad,-alms=$(BUILD_DIR)/$(notdir $(<:.c=.lst)) $< -o $@
	@echo ""

$(BUILD_DIR)/%.o: ./*/src/%.cpp | $(BUILD_DIR)
	$(CPP_CC) -c $(C_FLAGS) -Wa,-a,-ad,-alms=$(BUILD_DIR)/$(notdir $(<:.cpp=.lst)) $< -o $@
	@echo ""

$(BUILD_DIR):
	mkdir $@
	@echo ""

clean:
	rm -rf $(BUILD_DIR)

