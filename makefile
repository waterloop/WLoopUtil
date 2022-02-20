BUILD_DIR = bin

all:
	@echo 'Error: no rule to build "all", must specify board (ex. make master_bms)'
	@echo ""

master_bms:
	make -f main.mk \
		BUILD_DIR=$(BUILD_DIR) \
		BOARD_VARS="master_bms.mk"

motor_controller:
	make -f main.mk \
		BUILD_DIR=$(BUILD_DIR) \
		BOARD_VARS="motor_controller.mk"

clean:
	rm -rf $(BUILD_DIR)
