#include <M5Unified.h>
#include "headers/menu.h"

void menu() {
    M5.Display.fillScreen(TFT_BLACK);
    M5.Display.setTextColor(TFT_WHITE);
    M5.Display.setTextSize(1);
    M5.Display.setCursor(10, 10);
    M5.Display.println("Menu Principal\n");

    const char *menuItems[] = {"1. mic/Audio", "2. Cubo 3D BG", "3. Cubo 3D", "4. Servo Motor", "5. Debug"};

    for (int i = 0; i < 5; i++) {
        int posY = 30 + (i * 10); // Ajusta a posição vertical de cada opção
        M5.Display.setCursor(20, posY);

        if ((i + 1) == opcaoSelecionada) {
            M5.Display.setTextColor(TFT_BLACK, TFT_WHITE);
            M5.Display.fillRect(15, posY, 100, 10, TFT_WHITE); // Cria um fundo branco
        } else {
            M5.Display.setTextColor(TFT_WHITE);
        }

        M5.Display.println(menuItems[i]);
    }
    M5.Display.setTextColor(TFT_WHITE);
}