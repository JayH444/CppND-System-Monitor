#include <string>

#include "format.h"

using std::string;

// DONE: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long seconds) {
    int hour = seconds / 3600;
    int minute = (seconds % 3600) / 60;
    int second = (seconds % 3600) % 60;
    int vals[6] = {0,0,0,0,0,0};
    int curr;
    string res;
    for (int i = 5; i > -1; i--) {
        if (i == 5) {
            curr = second;
        }
        else if (i == 3) {
            curr = minute;
        }
        else if (i == 1) {
            curr = hour;
        }
        vals[i] = curr % 10;
        curr /= 10;
    }
    for (int i = 0; i < 6; i++) {
        if (i % 2 == 0 && i > 0) {
            res += ':';
        }
        res += std::to_string(vals[i]);
    }
    return res;
}