#include "processor.h"
#include <vector>
#include <string>

using std::vector;
using std::string;

// DONE: Return the aggregate CPU utilization
float Processor::Utilization() {
    double active = LinuxParser::ActiveJiffies();
    double total = LinuxParser::Jiffies();

    float utilization = (float)(active / total);
    return utilization;
}