# Library makefile

# Module Name
Module_Name := Audio

# Lib Name
Lib_Name := SDL3_Audio

# Compiler
CC := g++

# Compiler flags
CFLAGS := -fPIC -Wall -Wextra -pedantic -std=c++17 -I/usr/local/include

# Source files
Src_Files := $(wildcard *.cpp)

# Output Directory
Output_Dir := ../../../../Plugins/$(Module_Name)/$(Lib_Name)/
Headers := $(wildcard *.h)


# Object Directory
Obj_Dir := $(Output_Dir)Obj/

# Object files
Obj_Files := $(Src_Files:%.cpp=$(Obj_Dir)%.o)



#OS Specific
ifeq ($(OS),Windows_NT)
	# Windows
	# Library file
	Lib_File := $(Output_Dir)$(Lib_Name).dll
	# Library flags
	LFLAGS := -shared -Wl,--out-implib,$(Output_Dir)$(Lib_Name).a
else
	# Linux
	# Library file
	Lib_File := $(Output_Dir)$(Lib_Name).so
	# Library flags
	
	LFLAGS := -shared -L/usr/local/lib -lSDL3 -lSDL3_mixer -Wl,-Bstatic -Wl,-Bdynamic

endif

# Makefile targets
# Default target
all: $(Lib_File) 

# Build the library
$(Lib_File): $(Obj_Files)
	$(CC) $(CFLAGS) $(LFLAGS) -o $(Lib_File) $(Obj_Files)

# Build the object files in the object directory
$(Obj_Files): $(Src_Files)
	mkdir -p $(Obj_Dir)
	$(CC) $(CFLAGS) -c $< -o $@



# Clean
clean:
	rm -f $(Obj_Files) $(Lib_File)