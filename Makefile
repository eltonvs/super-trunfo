CXX = g++
DEL = /bin/rm

CFLAGS = -Wall -std=c++11
DFLAGS = -g -O0

BIN_DIR = bin
TARGET = supertrunfo
SRC1 = supertrunfo
SRC2 = st_card
SRC3 = st_game
SRC4 = st_player
DEBUG = debug
SRC_DIR = src
INCLUDE_DIR = include

all: $(BIN_DIR)/$(TARGET)

debug: $(BIN_DIR)/$(DEBUG)

$(BIN_DIR)/$(TARGET): $(BIN_DIR)/$(SRC1).o $(BIN_DIR)/$(SRC2).o $(BIN_DIR)/$(SRC3).o $(BIN_DIR)/$(SRC4).o
	@echo "Creating compiled file"
	$(CXX) $(CFLAGS) $(BIN_DIR)/$(SRC1).o $(BIN_DIR)/$(SRC2).o $(BIN_DIR)/$(SRC3).o $(BIN_DIR)/$(SRC4).o -o $(BIN_DIR)/$(TARGET)

$(BIN_DIR)/$(DEBUG): $(BIN_DIR)/$(SRC1).o $(BIN_DIR)/$(SRC2).o $(BIN_DIR)/$(SRC3).o $(BIN_DIR)/$(SRC4).o
	@echo "Creating compiled [ready to debug] file"
	$(CXX) $(CFLAGS) $(DFLAGS) $(BIN_DIR)/$(SRC1).o $(BIN_DIR)/$(SRC2).o $(BIN_DIR)/$(SRC3).o $(BIN_DIR)/$(SRC4).o -o $(BIN_DIR)/$(DEBUG)

$(BIN_DIR)/$(SRC1).o: $(SRC_DIR)/$(SRC1).cpp
	@echo "Creating object file 1"
	$(CXX) $(CFLAGS) -c $(SRC_DIR)/$(SRC1).cpp -I $(INCLUDE_DIR) -o $(BIN_DIR)/$(SRC1).o

$(BIN_DIR)/$(SRC2).o: $(SRC_DIR)/$(SRC2).cpp
	@echo "Creating object file 2"
	$(CXX) $(CFLAGS) -c $(SRC_DIR)/$(SRC2).cpp -I $(INCLUDE_DIR) -o $(BIN_DIR)/$(SRC2).o

$(BIN_DIR)/$(SRC3).o: $(SRC_DIR)/$(SRC3).cpp
	@echo "Creating object file 3"
	$(CXX) $(CFLAGS) -c $(SRC_DIR)/$(SRC3).cpp -I $(INCLUDE_DIR) -o $(BIN_DIR)/$(SRC3).o

$(BIN_DIR)/$(SRC4).o: $(SRC_DIR)/$(SRC4).cpp
	@echo "Creating object file 4"
	$(CXX) $(CFLAGS) -c $(SRC_DIR)/$(SRC4).cpp -I $(INCLUDE_DIR) -o $(BIN_DIR)/$(SRC4).o

clean:
	$(DEL) $(BIN_DIR)/$(TARGET) $(BIN_DIR)/$(SRC1).o $(BIN_DIR)/$(SRC2).o $(BIN_DIR)/$(SRC3).o $(BIN_DIR)/$(SRC4).o
	$(DEL) $(BIN_DIR)/$(DEBUG)