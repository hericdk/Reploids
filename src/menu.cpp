#include <M5Unified.h>
#include "telas.h"

void menu()
{
    int selectedScreen = 0; // Índice da tela selecionada

    while (true)
    {
        M5.update();

        // Se o botão for pressionado, muda a seleção
        if (M5.BtnA.wasPressed())
        {
            selectedScreen = (selectedScreen + 1) % 5; // Alterna entre 5 telas
        }

        // Se o botão for segurado, confirma a escolha
        if (M5.BtnA.pressedFor(500))
        {
            M5.Display.fillScreen(TFT_BLACK);
            switch (selectedScreen)
            {
            case 0:
                tela1();
                break;
            case 1:
                tela2();
                break;
            case 2:
                tela3();
                break;
            case 3:
                tela4();
                break;
            case 4:
                tela_debug();
                break;
            }
            return;
        }

        // Exibe o menu na tela
        M5.Display.fillScreen(TFT_BLACK);
        M5.Display.setCursor(10, 10);
        M5.Display.setTextSize(2);
        M5.Display.setTextColor(TFT_WHITE);

        M5.Display.printf("Selecione a Tela:\n\n");

        const char *telas[] = {"1. Visao 3D", "2. Perspectiva", "3. Servos", "4. Audio", "5. Debug"};

        for (int i = 0; i < 5; i++)
        {
            if (i == selectedScreen)
            {
                M5.Display.setTextColor(TFT_GREEN);
            }
            else
            {
                M5.Display.setTextColor(TFT_WHITE);
            }

            M5.Display.setCursor(10, 40 + (i * 20));
            M5.Display.printf("%s", telas[i]);
        }

        delay(100);
    }
}