#include "Logger.h"
#include <ctime>
#include <iomanip>
#include <sstream>     

using namespace std;

Logger::Logger() {
    logfile.open("log.txt", ios::app); 
}

Logger::~Logger() {
    if (logfile.is_open()) {
        logfile.close(); 
    }
}

void Logger::logEvent(string eventMessage) {
    if (logfile.is_open()) {
        time_t now = time(nullptr);
        struct tm localTime;
        localtime_s(&localTime, &now);  

        logfile << put_time(&localTime, "%Y-%m-%d %H:%M:%S") << " - " << eventMessage << endl;
    }
}

