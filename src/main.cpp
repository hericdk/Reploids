#include <M5Unified.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include "headers/utils.h"
#include "headers/menu.h"
#include "telas.h"

int telaAtual = 1;
bool menuAtivo = false;
int opcaoSelecionada = 1;
unsigned long lastMenuChange = 0;
const unsigned long menuDebounceDelay = 200;


void setup()
{
    auto cfg = M5.config();
    cfg.internal_imu = true;
    M5.begin(cfg);

    Wire.begin(38, 39); 

    setupServos();

    M5.Display.fillScreen(TFT_BLACK);
    M5.Display.setTextColor(TFT_WHITE);
    M5.Display.setTextSize(1);
}

void loop()
{
    M5.update();

     //Entrada no Menu
    if (!menuAtivo && M5.BtnA.pressedFor(menuDebounceDelay))
    {
        menuAtivo = true;
        opcaoSelecionada = 1; 
        menu();
    }

    if (menuAtivo)
    {
        if (M5.BtnA.pressedFor(menuDebounceDelay))
        {
            menuAtivo = false;
            telaAtual = opcaoSelecionada;
        } else if (M5.BtnA.wasReleased() && (millis() - lastMenuChange > menuDebounceDelay))
        {
            opcaoSelecionada++;
            if (opcaoSelecionada > 5)
                opcaoSelecionada = 1; 
            menu(); 
            lastMenuChange = millis();
        }

    } else
    {
        switch (telaAtual)
        {
        case 1:
            mic();
            break;
        case 2:
            grid3D();
            break;
        case 3:
            cube3D();
            break;
        case 4:
            servos();
            break;
        case 5:
            tela_debug();
            break;
        }
    }
}
