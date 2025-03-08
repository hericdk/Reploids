#ifndef UTILS_SERVOS_H
#define UTILS_SERVOS_H

#include <ESP32Servo.h>

extern Servo myServoD; // Declaração do servo para ser usada em outros arquivos

void moveServoSmoothly(Servo &servo, int targetAngle, int stepDelay = 0);

#endif