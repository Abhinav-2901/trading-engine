#ifndef LOGMANAGER_H
#define LOGMANAGER_H

#include <fstream>
#include <iostream>
#include <string>
#include <chrono>
#include <ctime>

class LogManager {
public:
    // Log file name (declaration only)
    static const std::string logFileName;

    // Log a message to the file with timestamp
    static void logToFile(const std::string& message);
};

#endif