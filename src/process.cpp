#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "process.h"

using std::string;
using std::to_string;
using std::vector;

// DONE: Return this process's ID
int Process::Pid() const { return pid_; }

// DONE: Return this process's CPU utilization
float Process::CpuUtilization() {
    double totalTime = (double)(LinuxParser::ActiveJiffies(Pid()));
    double seconds = (double)(LinuxParser::UpTime(Pid()));
    double cr = (double)sysconf(_SC_CLK_TCK);
    return (float)((totalTime / cr) / seconds);
    //return seconds

    /*long newActiveJiffies = LinuxParser::ActiveJiffies(Pid());
    long newUpTime = LinuxParser::UpTime(Pid());

    double totalTime = (double)(newActiveJiffies);
    double seconds = (double)(newUpTime);

    double cr = (double)sysconf(_SC_CLK_TCK);
    return (float)((totalTime / cr) / seconds);*/
}

// DONE: Return the command that generated this process
string Process::Command() { return LinuxParser::Command(Pid()); }

// DONE: Return this process's memory utilization
string Process::Ram() const { return LinuxParser::Ram(Pid()); }

// DONE: Return the user (name) that generated this process
string Process::User() {
    int pid = Pid();
    int uid = stoi(LinuxParser::Uid(pid));
    return LinuxParser::User(uid);
}

// DONE: Return the age of this process (in seconds)
long int Process::UpTime() { 
    return LinuxParser::UpTime(Pid());
}

// DONE: Overload the "less than" comparison operator for Process objects
// REMOVE: [[maybe_unused]] once you define the function
bool Process::operator<(Process const& a) const {
    return stoi(this->Ram()) < stoi(a.Ram());
}