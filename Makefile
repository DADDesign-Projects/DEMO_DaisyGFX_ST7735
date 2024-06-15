# Project Name
TARGET = DEMO_DaisyGFX_ST7735

# Sources
CPP_SOURCES = DEMO_DaisyGFX_ST7735.cpp DaisySeedGFX/Frame.cpp DaisySeedGFX/GFX.cpp DaisySeedGFX/TFT_SPI.cpp

# Library Locations
LIBDAISY_DIR = ../../../Desktop/DaisyExamples/libDaisy/
DAISYSP_DIR = ../../../Desktop/DaisyExamples/DaisySP/

# Core location, and generic Makefile.
SYSTEM_FILES_DIR = $(LIBDAISY_DIR)/core
include $(SYSTEM_FILES_DIR)/Makefile
