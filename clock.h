// Header file contents
#ifndef CLOCK_H
#define CLOCK_H

#include <string>
using namespace std;

// Create a string with 'n' copies of '*'
string nCharString(int n, char c);

// Structure to hold time information
struct Time {
    int hours;     // 0-23 for 24-hour format
    int minutes;   // 0-59
    int seconds;   // 0-59
};

// Function for clock operation
void addHour(Time &t);      // Adds one hour, wrap around at 24
void addMinute(Time &t);    // Adds one minute, wrap around at 60
void addSecond(Time &t);   // Adds one second, wrap around at 60

// Shows both 12-hour and 24-hour clocks
void displayClocks(const Time &t);

#endif