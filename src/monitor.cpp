#include ".api/monitor.h"
#include ".api/vitals_constants.h"
#include ".api/alertPrint.h"
#include <assert.h>
#include <thread>
#include <chrono>
#include <iostream>

// Función que chequea si un valor está fuera del rango [min, max]
bool isOutOfRange(float value, float min, float max) {
    return (value < min || value > max);
}

bool isBelowMin(float value, float min) {
    return (value < min);
}


int vitalsOk(float temperature, float pulseRate, float spo2) {
struct Check {
        float value;
        float min;
        float max;
        const char* message;
    };

    Check checks[] = {
        {temperature, TEMP_MIN, TEMP_MAX, "Temperature is critical!\n"},
        {pulseRate, PULSE_MIN, PULSE_MAX, "Pulse Rate is out of range!\n"}
    };

    for (const auto& check : checks) {
        if (check.value < check.min || check.value > check.max) {
            cout << check.message;
            alertBlink_print();
            return 0;
        }
    }
    
if ( isBelowMin (spo2 ,SPO2_MIN) ) {
    cout << "Oxygen Saturation out of range!\n";
    alertBlink_print()
    return 0;
  }
  return 1;
}
