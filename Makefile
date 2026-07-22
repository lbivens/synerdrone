# The name of your sketch (folder name and .ino file name)
SKETCH_NAME = synerdrone
# The Fully Qualified Board Name (FQBN) - find this via 'arduino-cli board list'
BOARD = arduino:esp32:esp32:esp32s3
# The serial port your board is connected to
PORT = /dev/ttyACM0

# --- Tool Definitions ---
ARDUINO_CLI = arduino-cli

# --- Build Targets ---

# Default target: compile the sketch
all: compile

# Compile the sketch
compile:
	$(ARDUINO_CLI) compile --fqbn $(BOARD) $(SKETCH_NAME)

# Upload the compiled binary to the board
upload: compile
	$(ARDUINO_CLI) upload -p $(PORT) --fqbn $(BOARD) $(SKETCH_NAME)

# Clean build artifacts
clean:
	# Arduino-CLI manages its own build folder; 
	# this typically clears the local temporary build cache
	$(ARDUINO_CLI) compile --fqbn $(BOARD) $(SKETCH_NAME) --build-path ./build
	rm -rf ./build

# Help menu
help:
	@echo "Available targets:"
	@echo "  make        - Compile the project"
	@echo "  make upload  - Compile and upload to board"
	@echo "  make clean   - Remove build artifacts"
	@echo "  make help    - Show this help message"

.PHONY: all compile upload clean help
