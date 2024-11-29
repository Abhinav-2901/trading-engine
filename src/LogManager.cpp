#include "LogManager.h"
#include <iomanip>
#include <sstream>

// Define logFileName
const std::string LogManager::logFileName = "logs/trading_engine.log";

void LogManager::logToFile(const std::string& message) {
    std::ofstream logFile(logFileName, std::ios_base::app); // Open file in append mode
    if (logFile.is_open()) {
        // Get current time
        auto currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

        // Convert time_t to tm struct
        std::tm* tm = std::localtime(&currentTime);
        
        // Format the time into a string
        std::ostringstream oss;
        oss << std::put_time(tm, "%Y-%m-%d %H:%M:%S");

        // Write to log file
        logFile << "[INFO] " << oss.str() << " " << message << std::endl;
        logFile.close();
    } else {
        std::cerr << "Failed to open log file.\n";
    }
}