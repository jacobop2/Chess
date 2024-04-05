# Directory where Python source files are located
SRC_DIR := src

# Python interpreter
PYTHON := python

# Find all Python files in the source directory
PYTHON_FILES := $(wildcard $(SRC_DIR)/*.py)

# Target to run the game
r:
	$(PYTHON) $(SRC_DIR)/main.py

# Target to clean compiled files
c:
	@echo "Cleaning up..."
	@find . -type f -name '*.pyc' -exec rm -f {} + 2>/dev/null || :
	@find . -type d -name '__pycache__' -exec rm -rf {} + 2>/dev/null || :
	@echo "Done."

# Default target
.DEFAULT_GOAL := run
