#pragma once

#include <fstream>

#include "ILogger.h"

using namespace std;

class LogToFile : public ILogger {
private:
    string fileName;
    void log(string type, string message) {
        ofstream logFile;
        logFile.open(fileName, ofstream::app);

        if (logFile.is_open()) {
            logFile << type << " " << message << endl;
        } else {
            throw "File could not be opened";
        }

        logFile.close();
    }

public:
    void logInfo(string message) override {
        log("INFO", message);
    }

    void logError(string message) override {
        log("ERROR", message);
    }
};
