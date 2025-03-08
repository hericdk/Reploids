#include <M5Unified.h>
#include "telas.h"
#include "utils.h"  // Agora inclui tudo modularizado

int telaAtual = 0;

void setup() {
    M5.begin();
    tela1();
}

void loop() {
    M5.update();
    if (M5.BtnA.wasPressed()) {
        telaAtual = (telaAtual + 1) % 5;
        M5.Display.fillScreen(TFT_BLACK);
    }
    switch (telaAtual) {
        case 0: tela1(); break;
        case 1: tela2(); break;
        case 2: tela3(); break;
        case 3: tela4(); break;
        case 4: tela_debug(); break;
    }
    delay(100);
}