#ifndef UTILS_SERVOS_H
#define UTILS_SERVOS_H

#include <Adafruit_PWMServoDriver.h>

extern Adafruit_PWMServoDriver pca9685; // Declaração externa

void setupPCA9685();
void moveServoSmoothly(int servoIndex, int targetAngle, int stepDelay);

#endif // UTILS_SERVOS_H