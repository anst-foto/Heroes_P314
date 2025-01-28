#pragma once

#include <string>

using namespace std;

class ILogger {
protected:
    ILogger() = default;
public:
    virtual void logInfo(string message) = 0;
    virtual void logError(string message) = 0;
};
