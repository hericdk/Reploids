#ifndef UTILS_SERVOS_H
#define UTILS_SERVOS_H

#include <ESP32Servo.h>

extern Servo myServoD; // Declara a variável global externamente

void moveServoSmoothly(Servo &servo, int targetAngle, int stepDelay = 0);

#endif