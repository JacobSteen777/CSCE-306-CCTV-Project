#pragma once
#include <string>

void clearLog();
void readLog(std::string); // Reads a file (Example String: "log.txt")
void addToLog(std::string, std::string); // Logs a basic, non-user specific action to file (Example: "Started Program", "log.txt")
void addToLog(std::string, std::string, std::string); // Logs a user specified action to a file (Example: "Bob", "Checked Personal Info", "log.txt")
void addToLog(std::string, std::string, std::string, std::string); //logs a user specified action as well as a value (Example: "Bob", "Changed Phone Number", "393-3933-3999", "log.txt")