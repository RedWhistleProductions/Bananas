# Compiler
CC := g++

# Directories
SRC_DIR := ./Source
DEBUG_DIR := ./Debug
RELEASE_DIR := ./Release

# Source files
SRCS := $(wildcard $(SRC_DIR)/*.cpp) 

# Object files
DEBUG_OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(DEBUG_DIR)/obj/%.o,$(SRCS))
RELEASE_OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(RELEASE_DIR)/obj/%.o,$(SRCS))

# Compiler flags
CFLAGS := -g 

# Linker flags
LDFLAGS := 

# Targets
.PHONY: all debug release clean

all: debug

debug: $(DEBUG_DIR)/Bananas

release: $(RELEASE_DIR)/Bananas

$(DEBUG_DIR)/Bananas: $(DEBUG_OBJS)
	$(CC) $(LDFLAGS) $^ -o $@

$(DEBUG_DIR)/obj/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(RELEASE_DIR)/Bananas: $(RELEASE_OBJS)
	$(CC) $(LDFLAGS) $^ -o $@

$(RELEASE_DIR)/obj/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(DEBUG_DIR) $(RELEASE_DIR)
	