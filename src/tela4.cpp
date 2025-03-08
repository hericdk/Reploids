#include <M5Unified.h>
#include <ESP32Servo.h>
#include "headers/utils_servos.h"
#include <cmath>

void drawServo2D(int angle)
{
    int offsetX = 20;
    int centerX = M5.Display.width() / 2 + offsetX;
    int centerY = M5.Display.height() / 2;
    int armLength = 40;

    float rad = angle * M_PI / 180.0;
    int endX = centerX + cos(rad) * armLength;
    int endY = centerY + sin(rad) * armLength;

    M5.Display.drawCircle(centerX - armLength, centerY, 12, TFT_WHITE);
    M5.Display.drawCircle(endX, endY, 8, TFT_WHITE);
    M5.Display.drawLine(centerX - armLength, centerY, endX, endY, TFT_WHITE);
}

void tela4()
{
    float x, y, z;
    M5.Imu.getAccel(&x, &y, &z);

    int targetAngle = map((int)(y * 100), -100, 100, 0, 180);
    moveServoSmoothly(myServoD, targetAngle);

    M5.Display.fillScreen(TFT_BLACK);

    M5.Display.setCursor(5, 5);
    M5.Display.printf("X: %d", (int)(x * 100));

    M5.Display.setCursor(5, 17);
    M5.Display.printf("Y: %d", (int)(y * 100));

    M5.Display.setCursor(5, 29);
    M5.Display.printf("Z: %d", (int)(z * 100));

    drawServo2D(targetAngle);
}