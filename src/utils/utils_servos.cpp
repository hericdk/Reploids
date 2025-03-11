#include "../headers/utils_servos.h"
#include <Wire.h>

// ✅ Define `pca9685` apenas uma vez aqui
Adafruit_PWMServoDriver pca9685 = Adafruit_PWMServoDriver(0x40);

void setupPCA9685()
{
    Wire.begin(39, 38); // SDA=39, SCL=38 (pinos do AtomS3R)
    pca9685.begin();
    pca9685.setPWMFreq(50); // Define a frequência para servos (50Hz)
}

void moveServoSmoothly(int servoIndex, int targetAngle, int stepDelay)
{
    if (servoIndex < 0 || servoIndex > 15) return;

    int targetPulse = map(targetAngle, 0, 180, 150, 600);
    pca9685.setPWM(servoIndex, 0, targetPulse);
    delay(stepDelay);
}