#include <M5Unified.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <headers/utils_servos.h>  // Inclui o arquivo de cabeçalho correto
#include <cmath>

#define SDA_PIN 38
#define SCL_PIN 39
#define SERVO_MIN 150
#define SERVO_MAX 600

bool pca9685Connected = false;
bool servo0Connected = false;
bool servo1Connected = false;
bool servo2Connected = false;


void checkServoConnection(int servoIndex, bool &servoConnected) {
    int testAngle = 90;
    int pulseWidth = map(testAngle, 0, 180, SERVO_MIN, SERVO_MAX);
    pca9685.setPWM(servoIndex, 0, pulseWidth);
    
    delay(10);
    int currentPulseWidth = pca9685.getPWM(servoIndex);
    
    servoConnected = currentPulseWidth > 0;
}

bool checkPCA9685Connection() {
    Wire.beginTransmission(0x40);
    return Wire.endTransmission() == 0;
}

void scanI2C() {
    M5.Display.fillScreen(TFT_BLACK);
    M5.Display.setTextSize(1);
    M5.Display.setTextColor(TFT_WHITE);
    M5.Display.setCursor(10, 10);
    M5.Display.println("Escaneando I2C...");

    byte error, address;
    int nDevices = 0;
    int yPos = 30;

    for (address = 1; address < 127; address++) {
        Wire.beginTransmission(address);
        error = Wire.endTransmission();

        if (error == 0) {
            M5.Display.setCursor(10, yPos);
            M5.Display.printf("[OK] Encontrado: 0x%X", address);
            yPos += 10;
            nDevices++;
        }
    }

    M5.Display.setCursor(10, yPos + 10);
    if (nDevices == 0) {
        M5.Display.setTextColor(TFT_YELLOW);
        M5.Display.println("[!!] Nenhum dispositivo I2C!");
    } else {
        M5.Display.setTextColor(TFT_GREEN);
        M5.Display.println("[OK] Scan concluído!");
    }

    delay(3000);
}

void servos() {
    scanI2C();

    // Verifica a conexão com a PCA9685
    pca9685Connected = checkPCA9685Connection();

    // Verifica a conexão dos servos se a PCA9685 estiver conectada
    if (pca9685Connected) {
        checkServoConnection(0, servo0Connected);
        checkServoConnection(1, servo1Connected);
        checkServoConnection(2, servo2Connected);
    }

    // Display Status
    M5.Display.fillScreen(TFT_BLACK);
    M5.Display.setTextSize(1);

    M5.Display.setCursor(5, 5); 
    M5.Display.setTextColor(pca9685Connected ? TFT_GREEN : TFT_RED);
    M5.Display.printf("PCA9685: %s\n", pca9685Connected ? "[OK]" : "[!!]");
    M5.Display.setTextColor(TFT_WHITE);

    M5.Display.setCursor(5, 15);
    M5.Display.setTextColor(servo0Connected ? TFT_GREEN : TFT_RED);
    M5.Display.printf("Servo 0: %s\n", servo0Connected ? "[OK]" : "[!!]");
    
    M5.Display.setCursor(5, 25);
    M5.Display.setTextColor(servo1Connected ? TFT_GREEN : TFT_RED);
    M5.Display.printf("Servo 1: %s\n", servo1Connected ? "[OK]" : "[!!]");
   
    M5.Display.setCursor(5, 35);
    M5.Display.setTextColor(servo2Connected ? TFT_GREEN : TFT_RED);
    M5.Display.printf("Servo 2: %s\n", servo2Connected ? "[OK]" : "[!!]");

   
}