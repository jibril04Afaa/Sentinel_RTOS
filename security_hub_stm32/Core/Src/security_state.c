#include <stdio.h>
#include "security_state.h"

// Thresholds for motion classification
#define THRESHOLD_WARNING 1.5f
#define THRESHOLD_ALERT   2.5f

SystemState_t SecurityLogic_Evaluate(SensorData_t *data) {
    if (data == NULL) {
        return STATE_ALERT_TAMPER; // Safety net
    }

    if (data->button_pressed) {
        return STATE_ALERT_TAMPER; // User triggered panic
    }

    if (data->magnitude >= THRESHOLD_ALERT) {
        return STATE_ALERT_TAMPER; // Sudden violent movement (snatch)
    }

    if (data->magnitude >= THRESHOLD_WARNING) {
        return STATE_WARNING;      // Suspicious jostling
    }

    return STATE_NORMAL;           // At rest (~1.0g due to gravity)
}