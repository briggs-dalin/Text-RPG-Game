# Compiler
CXX = g++
CXXFLAGS = -std=c++17 -Wall

# Source files
SRC = src/main.cpp src/Combat.cpp src/Utils.cpp src/PlayerCreation.cpp src/Room.cpp src/Dungeon.cpp

# Output executable name
OUT = dungeon_rpg

# Default rule
all: $(OUT)

# Build rule
$(OUT): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT)

# Run the program
run: $(OUT)
	./$(OUT)

# Delete executable
clean:
	del $(OUT).exe 2>nul || true
