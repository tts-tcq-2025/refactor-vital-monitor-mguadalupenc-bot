#include <iostream>
#include <thread>
#include <chrono>
#include "alert_blink.h"

using namespace std;
using namespace std::this_thread;   // sleep_for
using namespace std::chrono;        // seconds

void alertBlink_print() {
    for (int i = 0; i < 6; i++) {
        cout << "\r* " << flush;
        sleep_for(seconds(1));
        cout << "\r *" << flush;
        sleep_for(seconds(1));
    }
}
