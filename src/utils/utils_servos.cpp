#include "../headers/utils_servos.h"
#include <Wire.h>
#include <random>

// ✅ Define `pca9685` apenas uma vez aqui
Adafruit_PWMServoDriver pca9685 = Adafruit_PWMServoDriver(0x40);

#define SERVO_MIN 150  // Pulso mínimo (~0 graus)
#define SERVO_MAX 600  // Pulso máximo (~180 graus)
#define NUM_SERVOS 3 // Number of servos in use

void setupServos() {
    Wire.begin(38, 39); // SDA=38, SCL=39 (pinos do AtomS3R)
    pca9685.begin();
    pca9685.setPWMFreq(50); // Define a frequência para servos (50Hz)
}

void moveServoTo(int servoIndex, int targetAngle) {
    if (servoIndex < 0 || servoIndex >= NUM_SERVOS) return; // Validate servoIndex
    
    int targetPulse = map(targetAngle, 0, 180, SERVO_MIN, SERVO_MAX);
    pca9685.setPWM(servoIndex, 0, targetPulse);
}

void moveAllServosTo(int angle0, int angle1, int angle2) {
    moveServoTo(0, angle0);
    moveServoTo(1, angle1);
    moveServoTo(2, angle2);
}

void moveAllServosToRandom() {
    // Seed the random number generator
    randomSeed(analogRead(0)); // Use a random value from an analog pin as the seed

    int randomAngle0 = random(0, 181); // Generate a random angle between 0 and 180
    int randomAngle1 = random(0, 181); // Generate a random angle between 0 and 180
    int randomAngle2 = random(0, 181); // Generate a random angle between 0 and 180

    moveAllServosTo(randomAngle0, randomAngle1, randomAngle2);
}

void moveServoSmoothly(int servoIndex, int targetAngle) {
   moveServoTo(servoIndex, targetAngle);
}