#include <iostream>
#include "clock.h" // Include function definitions and Time struct
using namespace std;

int main() {
    // Starting with the example time (3:22:00 PM = 15:22:00 in 24-hour format)
    Time t = {15, 22, 0};  // initial time (3:22:00 PM)

    int choice = 0; // User menu choice
    while (choice != 4) {   // Loop until user chooses to exit
        displayClocks(t);   // Show current time in both formats

        // Display menu
        cout << endl;
        cout << "***************************" << endl;
        cout << "* 1 - Add One Hour        *" << endl;
        cout << "* 2 - Add One Minute      *" << endl;
        cout << "* 3 - Add One Second      *" << endl;
        cout << "* 4 - Exit Program        *" << endl;
        cout << "***************************" << endl;
        cout << "Enter your choice: ";

        // Get user input
        if (!(cin >> choice)) {     // If input fails (non-integer), break
            cout << "Invalid input. Exiting." << endl;
            break;
        }

        // Process user choice
        if (choice == 1) {
            addHour(t);
        } else if (choice == 2) {
            addMinute(t);
        } else if (choice == 3) {
            addSecond(t);
        } else if (choice != 4) {  // Ignore exit choice
            cout << "Invalid choice! Try again." << endl;
        }

        cout << endl;   // Spacing before next display
    }

    cout << "Exiting program." << endl;
    return 0;
}
