#include "TradingEngine.h"
#include <fstream>

void TradingEngine::loadData(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: Cannot open file " << filename << "\n";
        LogManager::logToFile("Error: Cannot open file " + filename); // Log error
        return;
    }

    json inputData;
    file >> inputData;

    // Load orders
    for (const auto& o : inputData["orders"]) {
        orders.push_back({o["symbol"], o["type"], o["order_price"], o["quantity"]});
    }

    // Process ticks
    for (const auto& t : inputData["ticks"]) {
        newTick({t["symbol"], t["price"], t["timestamp"]});
    }
}

void TradingEngine::addOrder(const Order& order) {
    orders.push_back(order);
    LogManager::logToFile("New Order Added: Symbol: " + order.symbol + ", Type: " + order.type +
                          ", Price: " + std::to_string(order.order_price) +
                          ", Quantity: " + std::to_string(order.quantity));
}

void TradingEngine::newTick(const Tick& tick) {
    auto it = orders.begin();
    while (it != orders.end()) {
        if (it->symbol == tick.symbol) {
            if ((it->type == "BL" && tick.price <= it->order_price)) {
                std::cout << "Order executed at " << tick.timestamp
                          << ", Price: " << tick.price
                          << ", Quantity: " << it->quantity << "\n";
                
                // Log the order execution
                LogManager::logToFile("Order executed at " + tick.timestamp +
                                      ", Price: " + std::to_string(tick.price) +
                                      ", Quantity: " + std::to_string(it->quantity) +
                                      ", Symbol: " + it->symbol);
                it = orders.erase(it); // Remove filled order
            } else {
                ++it;
            }
        } else {
            ++it;
        }
    }
}

void TradingEngine::displayOrders() const {
    std::cout << "Pending Orders:\n";
    for (const auto& order : orders) {
        std::cout << "Symbol: " << order.symbol
                  << ", Type: " << order.type
                  << ", Price: " << order.order_price
                  << ", Quantity: " << order.quantity << "\n";
    }
}