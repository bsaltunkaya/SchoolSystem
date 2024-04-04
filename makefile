# Compiler
CC = g++

# Compiler flags
CFLAGS = -Wall -std=c++11

# Source files
SRC = main.cpp Student.cpp Course.cpp SchoolManagerSystem.cpp

# Output executable
OUT = SchoolManagerSystem

all: $(SRC)
	$(CC) $(CFLAGS) -o $(OUT) $(SRC)

clean:
	rm -f $(OUT)