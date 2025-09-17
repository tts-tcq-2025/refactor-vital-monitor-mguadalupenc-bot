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
