#include "../headers/utils_servos.h"

Servo myServoD; // Define a variável global

void moveServoSmoothly(Servo &servo, int targetAngle, int stepDelay)
{
    int currentAngle = servo.read();
    if (currentAngle != targetAngle)
    {
        int step = (currentAngle < targetAngle) ? 1 : -1;
        for (int angle = currentAngle; angle != targetAngle; angle += step)
        {
            servo.write(angle);
            delay(stepDelay);
        }
    }
}