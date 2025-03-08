#include <M5Unified.h>
#include "utils/utils_audio.h"

void tela4()
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

        int audioLevel = getAudioLevel();

        M5.Display.fillScreen(TFT_BLACK);
        M5.Display.setCursor(10, 10);
        M5.Display.setTextSize(2);
        M5.Display.printf("Audio Level: %d", audioLevel);

        int barWidth = map(audioLevel, 0, 5000, 0, M5.Display.width() - 20);
        M5.Display.fillRect(10, 40, barWidth, 20, TFT_GREEN);

        delay(100);
    }
}