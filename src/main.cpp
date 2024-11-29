#include "TradingEngine.h"

int main() {
    LogManager::logToFile("Trading engine started.");

    TradingEngine engine;

    // Load data from input.json
    engine.loadData("data/input.json");

    LogManager::logToFile("Trading engine completed.");

    return 0;
}