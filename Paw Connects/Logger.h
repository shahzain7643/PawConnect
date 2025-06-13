#ifndef LOGGER_H
#define LOGGER_H
#include <fstream>
#include <string>
using namespace std;

class Logger {
private:
    ofstream logfile;

public:
    Logger();                            
    ~Logger();                          
    void logEvent(string eventMessage);   
};

#endif

