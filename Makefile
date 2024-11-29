CXX = g++
CXXFLAGS = -std=c++17 -Wall
SRC = src/main.cpp src/TradingEngine.cpp src/LogManager.cpp
INC = include/
OUT = trading_engine

all: $(OUT)

$(OUT): $(SRC)
	$(CXX) $(CXXFLAGS) -I$(INC) -o $(OUT) $(SRC)

clean:
	rm -f $(OUT)