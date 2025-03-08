#include <M5Unified.h>
#include "headers/menu.h"

int opcaoSelecionada = 1; // Definição única da variável

void menu()
{
    M5.Display.fillScreen(TFT_BLACK);
    M5.Display.setCursor(10, 10);
    M5.Display.setTextSize(1);
    M5.Display.printf("Menu Principal\n\n");

    for (int i = 1; i <= 5; i++)
    {
        int posY = 10 + (i * 15); // Ajusta a posição vertical de cada opção
        M5.Display.setCursor(20, posY);

        if (i == opcaoSelecionada)
        {
            M5.Display.setTextColor(TFT_BLACK, TFT_WHITE);
            M5.Display.fillRect(15, posY - 2, 100, 12, TFT_WHITE); // Cria um fundo branco
        }
        else
        {
            M5.Display.setTextColor(TFT_WHITE);
        }

        switch (i)
        {
        case 1:
            M5.Display.printf("1. mic/Audio");
            break;
        case 2:
            M5.Display.printf("2. Cubo 3D BG");
            break;
        case 3:
            M5.Display.printf("3. Cubo 3D");
            break;
        case 4:
            M5.Display.printf("4. Servo Motor");
            break;
        case 5:
            M5.Display.printf("5. Debug");
            break;
        }
    }
    M5.Display.setTextColor(TFT_WHITE);
}