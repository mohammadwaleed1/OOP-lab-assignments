#include <iostream>
#include <string>

using namespace std;

class Logger {
private:
    static const int MAX_LOGS = 1000;
    string logs[MAX_LOGS];
    int logCount = 0;
    int start = 0;

    void storeLog(const string& severity, const string& module, const string& message) {
        string formatted = "[" + severity + "] from [" + module + "]: " + message;

        int index = (start + logCount) % MAX_LOGS;
        logs[index] = formatted;

        if (logCount < MAX_LOGS) {
            logCount++;
        } else {
            start = (start + 1) % MAX_LOGS; 
        }
    }

public:
    void logInfo(const string& module, const string& message) {
        storeLog("INFO", module, message);
    }

    void logWarning(const string& module, const string& message) {
        storeLog("WARN", module, message);
    }

    void logError(const string& module, const string& message) {
        storeLog("ERROR", module, message);
    }

    friend class Auditor;
};

class Auditor {
private:
    string password;

public:
    Auditor(const string& pwd) : password(pwd) {}

    bool isAuthenticated() const {
        return password == "admin123";
    }

    void retrieveLogs(const Logger& logger) const {
        if (!isAuthenticated()) {
            cout << "\nAccess denied: Unauthorized auditor.\n";
            return;
        }

        cout << "\n Retrieving logs for audit:\n";
        for (int i = 0; i < logger.logCount; ++i) {
            int index = (logger.start + i) % Logger::MAX_LOGS;
            cout << logger.logs[index] << "\n";
        }
    }
};

int main() {
    Logger logger;

    logger.logInfo("Network", "Connected to server.");
    logger.logWarning("Database", "Slow response detected.");
    logger.logError("Auth", "Failed login attempt.");
    logger.logInfo("System", "Health check passed.");

    Auditor badAuditor("1234");
    badAuditor.retrieveLogs(logger);

    Auditor goodAuditor("admin123");
    goodAuditor.retrieveLogs(logger);

    return 0;
}
