#ifndef UTILS_SERVOS_H
#define UTILS_SERVOS_H

#include <Adafruit_PWMServoDriver.h>

extern Adafruit_PWMServoDriver pca9685; // Declaração externa

void setupServos();
void moveServoTo(int servoIndex, int targetAngle);
void moveAllServosTo(int angle0, int angle1, int angle2);
void moveAllServosToRandom();
void moveServoSmoothly(int servoIndex, int targetAngle);

#endif // UTILS_SERVOS_H