#include <M5Unified.h>
#include "headers/utils.h"
#include "headers/menu.h" // Agora o menu é incluído corretamente
#include "telas.h"        // Inclui as telas

int telaAtual = 1;      // Começa na tela 1
bool menuAtivo = false; // Controla se o menu está aberto

void setup()
{
    auto cfg = M5.config();
    cfg.internal_imu = true;
    M5.begin(cfg);

    M5.Display.fillScreen(TFT_BLACK);
    M5.Display.setTextColor(TFT_WHITE);
    M5.Display.setTextSize(1);
}

void loop()
{
    M5.update();

    // **Se segurar o botão por mais de 200ms, ativa o menu**
    if (!menuAtivo && M5.BtnA.pressedFor(200))
    {
        menuAtivo = true;
        opcaoSelecionada = 0; // Reinicia a seleção do menu
        menu();
        while (M5.BtnA.isPressed())
            M5.update(); // Aguarda soltar o botão para evitar travamento
    }

    if (menuAtivo)
    {
        if (M5.BtnA.pressedFor(200))
        {
            // Sai do menu e entra na tela selecionada
            menuAtivo = false;
            telaAtual = opcaoSelecionada;

            // Aguarda o botão ser solto para evitar ativação dupla
            while (M5.BtnA.isPressed())
                M5.update();
        }
        else if (M5.BtnA.wasReleased()) // Agora espera soltar o botão antes de mudar de opção
        {
            opcaoSelecionada++;
            if (opcaoSelecionada > 5)
                opcaoSelecionada = 1; // Volta para a primeira opção se passar da última
            menu();                   // Atualiza a tela do menu
        }
    }
    else
    {
        // **Chama a tela correta continuamente para manter a animação**
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

    delay(100); // **Mantém o loop rodando corretamente sem travamento**
}