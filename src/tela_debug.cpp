#include <M5Unified.h>
#include "headers/utils.h"

void tela_debug(){

    float accX, accY, accZ;
    float gyroX, gyroY, gyroZ;
    M5.Imu.getAccel(&accX, &accY, &accZ);
    M5.Imu.getGyro(&gyroX, &gyroY, &gyroZ);

    float batteryVoltage = M5.Power.getBatteryVoltage();

    M5.Display.fillScreen(TFT_BLACK);
    M5.Display.setCursor(10, 10);
    M5.Display.setTextSize(1);

    M5.Display.printf("DEBUG MODE\n");
    M5.Display.printf("-------------\n");

        // **IMU**
    M5.Display.printf("X: %d  Y: %d  Z: %d\n\n", (int)(accX * 100), (int)(accY * 100), (int)(accZ * 100));
    M5.Display.printf("GX: %d \nGY: %d \nGZ: %d\n\n", (int)(gyroX * 100), (int)(gyroY * 100), (int)(gyroZ * 100));

        // **Bateria**
    M5.Display.printf("BAT: %.2fV\n", batteryVoltage / 1000.0);

        // **Botões**
    // M5.Display.printf("BTN A: %s\n", M5.BtnA.isPressed() ? "ON" : "OFF");
    // delay(100); // Atualiza a cada 100ms
}