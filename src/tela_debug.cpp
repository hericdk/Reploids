#include <M5Unified.h>
#include "utils_audio.h"

void tela_debug()
{
    setupI2S(); // Agora a configuração está no utils_audio.cpp

    while (true)
    {
        M5.update();
        if (M5.BtnA.wasPressed())
        {
            i2s_driver_uninstall(I2S_PORT);
            return;
        }

        float accX, accY, accZ;
        float gyroX, gyroY, gyroZ;
        M5.Imu.getAccel(&accX, &accY, &accZ);
        M5.Imu.getGyro(&gyroX, &gyroY, &gyroZ);

        int audioLevel = getAudioLevel();
        float batteryVoltage = M5.Power.getBatteryVoltage();

        M5.Display.fillScreen(TFT_BLACK);
        M5.Display.setCursor(10, 10);
        M5.Display.setTextSize(1);

        M5.Display.printf("DEBUG MODE\n");
        M5.Display.printf("-----------\n");

        // **IMU**
        M5.Display.printf("IMU:\nX: %d  Y: %d  Z: %d\n", (int)(accX * 100), (int)(accY * 100), (int)(accZ * 100));
        M5.Display.printf("GX: %d  GY: %d  GZ: %d\n", (int)(gyroX * 100), (int)(gyroY * 100), (int)(gyroZ * 100));

        // **Áudio**
        M5.Display.printf("\nMIC: %d\n", audioLevel);

        // **Bateria**
        M5.Display.printf("BAT: %.2fV\n", batteryVoltage / 1000.0);

        // **Botões**
        M5.Display.printf("BTN A: %s\n", M5.BtnA.isPressed() ? "ON" : "OFF");

        delay(100);
    }
}