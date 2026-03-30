#ifndef SECURITY_STATE_H
#define SECURITY_STATE_H

#include <stdint.h>

typedef enum {
    STATE_NORMAL,
    STATE_WARNING,
    STATE_ALERT_TAMPER   // Triggers on sudden motion, panic, OR wire cut
} SystemState_t;

typedef struct {
    float magnitude;
    uint8_t button_pressed;
} SensorData_t;

// State machine evaluator
SystemState_t SecurityLogic_Evaluate(SensorData_t *data);

#endif // SECURITY_STATE_H