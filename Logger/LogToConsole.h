#pragma once

#include <iostream>

#include "ILogger.h"

using namespace std;

class LogToConsole : public ILogger {
private:
    static void log(string type, string message) {
        cout << type << " " << message << endl;
    }

public:
    void logInfo(string message) override {
        log("INFO", message);
    }

    void logError(string message) override {
        log("ERROR", message);
    }
};
