# Trading Engine Assignment
 
## Problem
 
In this assignment, we are tasked with simulating a trading engine that processes buy and sell orders in real-time. The goal is to:
 
1. **Read Orders** from an input file in JSON format.
2. **Process Orders**: Execute the orders in the correct sequence based on their timestamps.
3. **Log Execution** details such as timestamp, price, quantity, and symbol of the orders.
 
This system will mimic a basic trading engine that receives orders, processes them, and logs the results.
 
## Solution
 
### Overview
 
The solution involves building a **Trading Engine** that performs the following operations:
 
1. **Input Parsing**: The system reads orders from a JSON file (`orders.json`). Each order contains information like timestamp, price, quantity, and symbol.
2. **Order Sorting**: The orders are sorted by their timestamp to ensure they are executed in the correct sequence.
 
3. **Order Execution**: After sorting, the orders are executed in the given sequence. The execution will log the details of each order, including its price, quantity, and symbol.
 
4. **Logging**: The execution details of the trading engine, including each order's execution, are logged to a log file (`trading_engine.log`).
 
### Approach
 
- **Reading Orders**: The orders are stored in a JSON file, which is parsed using the `nlohmann/json` C++ library.
- **Sorting**: After reading the data, the orders are sorted by their timestamp to ensure chronological execution.
- **Executing Orders**: The engine executes the orders one by one, logging the execution details to the log file.
 
- **Logging**: The `LogManager` class handles the logging of execution details to `trading_engine.log`.
 
---
 
## Assignment Structure
 
```plaintext
trading_engine/
├── include/
│   ├── TradingEngine.h           # Header file for TradingEngine class
│   └── LogManager.h              # Header file for LogManager class
├── src/
│   ├── TradingEngine.cpp         # Implementation of TradingEngine logic
│   ├── LogManager.cpp            # Implementation of LogManager class
│   └── main.cpp                  # Main file to execute the trading engine
├── data/
│   └── orders.json               # Sample input file containing orders
├── logs/
│   └── trading_engine.log        # Log file generated during execution
├── Makefile                      # Build configuration file
├── README.md                     # Project documentation
```
 
---
 
## How to Build the Assignment
 
### Prerequisites
 
- C++17 or later support in your compiler.
- g++ or any modern C++ compiler.
 
### Steps to Build
 
1. **Clone the Repository**:
   ```bash
   git clone https://github.com/Abhinav-2901/trading-engine.git
   ```
 
2. **Navigate to the Project Directory**:
   ```bash
   cd trading-engine
   ```
 
3. **Build the Project**:
   ```bash
   make
   ```
 
4. **Run the Trading Engine**:
   ```bash
   ./trading_engine
   ```