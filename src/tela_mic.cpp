#include <M5Unified.h>

bool gravando = false;
bool reproduzindo = false;
unsigned long tempoInicio = 0;
unsigned long duracaoGravacao = 0;

void mic()
{
    M5.update();

    // **Se apertar o botão, alterna entre os estados**
    if (M5.BtnA.isPressed())
    {
        if (!gravando && !reproduzindo) // Se está parado, começa a gravar
        {
            gravando = true;
            tempoInicio = millis();
        }
        else if (gravando) // Se está gravando, para e inicia a reprodução
        {
            gravando = false;
            reproduzindo = true;
            duracaoGravacao = (millis() - tempoInicio) / 1000; // Salva o tempo total gravado
            tempoInicio = millis();
        }
        else if (reproduzindo) // Se está reproduzindo, volta ao estado normal
        {
            reproduzindo = false;
        }
    }

    // **Se estiver reproduzindo, para após o tempo gravado**
    unsigned long tempoDecorrido = (millis() - tempoInicio) / 1000;
    if (reproduzindo && tempoDecorrido >= duracaoGravacao)
    {
        reproduzindo = false; // Retorna ao estado normal após tocar o tempo gravado
    }

    // **Define a cor do MIC conforme o estado**
    uint16_t micColor = TFT_BLACK; // Cor padrão
    if (gravando)
        micColor = TFT_RED;
    if (reproduzindo)
        micColor = TFT_GREEN;

    // **Redesenha a tela**
    M5.Display.fillScreen(TFT_WHITE);
    M5.Display.setTextColor(micColor);
    M5.Display.setCursor(10, 10);
    M5.Display.setTextSize(2);
    M5.Display.printf("MIC");

    // **Exibe o status e o tempo corretamente**
    M5.Display.setTextColor(TFT_BLACK);
    M5.Display.setTextSize(1);
    M5.Display.setCursor(10, 60);
    if (gravando)
    {
        M5.Display.printf("Status: Gravando");
    }
    else if (reproduzindo)
    {
        M5.Display.printf("Status: Tocando");
    }
    else
    {
        M5.Display.printf("Status: Parado");
    }

    M5.Display.setCursor(10, 70);
    if (gravando)
    {
        M5.Display.printf("Tempo: %lu s", tempoDecorrido);
    }
    else if (reproduzindo)
    {
        M5.Display.printf("Tempo: %lu/%lu s", tempoDecorrido, duracaoGravacao);
    }
    else
    {
        M5.Display.printf("Tempo: -/- s");
    }

    M5.Display.display();
}