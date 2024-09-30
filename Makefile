CXX      := -c++
CXXFLAGS := -pedantic-errors -Wall -Wextra -Werror
LDFLAGS  := -L/usr/lib -lstdc++ -lm
BUILD    := ./build
OBJ_DIR  := $(BUILD)/objects
APP_DIR  := $(BUILD)/apps
TARGET   := slinky
INCLUDE  := -Iinclude/
SRC      := $(shell find src -name '*.cpp')

OBJECTS  := $(SRC:%.cpp=$(OBJ_DIR)/%.o)
DEPENDENCIES \
         := $(OBJECTS:.o=.d)

space := $(empty) $(empty)

all: build $(APP_DIR)/$(TARGET)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -MMD -o $@

$(APP_DIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -o $(APP_DIR)/$(TARGET) $^ $(LDFLAGS)

-include $(DEPENDENCIES)

.PHONY: all build clean debug release info

build:
	@mkdir -p $(APP_DIR)
	@mkdir -p $(OBJ_DIR)

debug: CXXFLAGS += -DDEBUG -g
debug: all

release: CXXFLAGS += -O2
release: all

clean:
	-@rm -rvf $(OBJ_DIR)/*
	-@rm -rvf $(APP_DIR)/*

info:
	@echo "     _ _      _        "
	@echo "  __| (_)_ _ | |___  _ "
	@echo " (_-< | | ' \| / / || |"
	@echo " /__/_|_|_||_|_\_\\_, |"
	@echo "                  |__/  "
	@echo ""
	@echo "[*] Application dir: ${APP_DIR}     "
	@echo "[*] Object dir:      ${OBJ_DIR}     "
	@echo "[*] Sources:          "
	@echo "      - $(subst $(space),\n      - ,$(SRC))"
	@echo "[*] Objects:          "
	@echo "      - $(subst $(space),\n      - ,$(OBJECTS))"
	@echo "[*] Dependencies:     "
	@echo "      - $(subst $(space),\n      - ,$(DEPENDENCIES))"