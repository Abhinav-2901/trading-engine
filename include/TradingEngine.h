#ifndef TRADINGENGINE_H
#define TRADINGENGINE_H

#include "json.hpp"
#include "LogManager.h"  // Include LogManager for logging
#include <string>
#include <vector>
#include <iostream>

using json = nlohmann::json;

struct Order {
    std::string symbol;
    std::string type;  // BL = Buy Limit
    double order_price;
    int quantity;
};

struct Tick {
    std::string symbol;
    double price;
    std::string timestamp;
};

class TradingEngine {
private:
    std::vector<Order> orders;

public:
    // Constructor
    TradingEngine() = default;

    // Load orders and ticks from a JSON file
    void loadData(const std::string& filename);

    // Add a new order
    void addOrder(const Order& order);

    // Process a new tick
    void newTick(const Tick& tick);

    // Display the current orders (for debugging)
    void displayOrders() const;
};

#endif