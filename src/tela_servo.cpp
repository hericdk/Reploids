#include <M5Unified.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <headers/utils_servos.h>
#include <cmath>

#define SDA_PIN 38
#define SCL_PIN 39
#define SERVO_MIN 150  // Pulso mínimo (~0 graus)
#define SERVO_MAX 600  // Pulso máximo (~180 graus)
 

void scanI2C()
{
    M5.Display.fillScreen(TFT_BLACK); // Limpa a tela antes de exibir o resultado
    M5.Display.setTextSize(2);
    M5.Display.setTextColor(TFT_WHITE);
    M5.Display.setCursor(10, 10);
    M5.Display.println("🔍 Escaneando I2C...");

    byte error, address;
    int nDevices = 0;
    int yPos = 30; // Posição inicial do texto

    for (address = 1; address < 127; address++)
    {
        Wire.beginTransmission(address);
        error = Wire.endTransmission();

        if (error == 0)
        {
            // Exibe cada dispositivo encontrado na tela
            M5.Display.setCursor(10, yPos);
            M5.Display.printf("✅ Encontrado: 0x%X", address);
            yPos += 20; // Move o cursor para a próxima linha
            nDevices++;
        }
    }

    M5.Display.setCursor(10, yPos + 10);
    if (nDevices == 0)
    {
        M5.Display.setTextColor(TFT_YELLOW);
        M5.Display.println("⚠️ Nenhum dispositivo I2C!");
    }
    else
    {
        M5.Display.setTextColor(TFT_GREEN);
        M5.Display.println("✅ Scan concluído!");
    }

    delay(3000);
}


void servos()
{
    float x, y, z;
    M5.Imu.getAccel(&x, &y, &z);

    int targetAngle = map((int)(y * 100), -100, 100, 0, 180);
    int pulseWidth = map(targetAngle, 0, 180, SERVO_MIN, SERVO_MAX);

    pca9685.setPWM(0, 0, pulseWidth); // Move o servo no canal 0

    // **Exibe na tela**
    M5.Display.fillScreen(TFT_BLACK);
    M5.Display.setCursor(5, 5);
    M5.Display.printf("X: %d", (int)(x * 100));

    M5.Display.setCursor(5, 17);
    M5.Display.printf("Y: %d", (int)(y * 100));

    M5.Display.setCursor(5, 29);
    M5.Display.printf("Z: %d", (int)(z * 100));

    M5.Display.setCursor(5, 50);
    M5.Display.printf("Servo: %d°", targetAngle);

    scanI2C();

}