#include "clock.h"
#include <iostream>
#include <iomanip>
using namespace std;

string nCharString(int n, char c) {
    return string(n, c); 
}

// Add one hour, wrap around at 24 (23 -> 0)
void addHour(Time &t) {
    t.hours++;
    if (t.hours >= 24) t.hours = 0; // Reset to 0 after 23
}

// Add one minute, wrap around at 60 (59 -> 0, increments hour)
void addMinute(Time &t) {
    t.minutes++;
    if (t.minutes >= 60) {
        t.minutes = 0;  // Reset minutes to 0 after 59
        addHour(t);     // Increment hour
    }
}

// Add one second, wrap around at 60 (59 -> 0, increments minute)
void addSecond(Time &t) {
    t.seconds++;
    if (t.seconds >= 60) {
        t.seconds = 0;  // Reset seconds to 0 after 59
        addMinute(t);   // Increment minute
    }
}

// Display time in both 12-hour and 24-hour formats side by side
void displayClocks(const Time &t) {
    int hour12 = t.hours % 12;
    if (hour12 == 0) hour12 = 12;
    bool isPM = t.hours >= 12;

    // Top border
    cout << nCharString(27, '*')
         << "    "
         << nCharString(27, '*') << endl;

    // Titles
    cout << "*     12-Hour Clock       *"
         << "    "
         << "*     24-Hour Clock       *" << endl;

    // Times
    cout << "*     " << setw(2) << setfill('0') << hour12 << ":"
         << setw(2) << setfill('0') << t.minutes << ":"
         << setw(2) << setfill('0') << t.seconds
         << (isPM ? " PM" : " AM") << "        *";

    cout << "    ";

    cout << "*       " << setw(2) << setfill('0') << t.hours << ":"
         << setw(2) << setfill('0') << t.minutes << ":"
         << setw(2) << setfill('0') << t.seconds << "         *" << endl;

    // Bottom border
    cout << nCharString(27, '*')
         << "    "
         << nCharString(27, '*') << endl;
}
