#include "./monitor.h"
#include "./monitorValues.h"
#include <assert.h>
#include <thread>
#include <chrono>
#include <iostream>
using std::cout, std::flush, std::this_thread::sleep_for, std::chrono::seconds;

void alertBlink_print() {
    for (int i = 0; i < 6; i++) {
        cout << "\r* " << flush;
        sleep_for(seconds(1));
        cout << "\r *" << flush;
        sleep_for(seconds(1));
    }
}

// Función que chequea si un valor está fuera del rango [min, max]
bool isOutOfRange(float value, float min, float max) {
    return (value < min || value > max);
}
int vitalsOk(float temperature, float pulseRate, float spo2) {
  if (isOutOfRange ( temperature ,TEMP_MIN ,TEMP_MAX )) {
    cout << "Temperature is critical!\n";
    alertBlink_print()
    return 0;
  } else if (isOutOfRange ( pulseRate, PULSE_MIN , PULSE_MAX )) {
    cout << "Pulse Rate is out of range!\n";
    alertBlink_print()
    return 0;
  } else if (spo2 < SPO2_MIN ) {
    cout << "Oxygen Saturation out of range!\n";
    alertBlink_print()
    return 0;
  }
  return 1;
}
