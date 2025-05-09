#include <M5Unified.h>
#include "headers/utils_3d.h"

void cube3D()
{
    float x, y, z;
    M5.Imu.getAccel(&x, &y, &z);

    RotationMatrix rotationMatrix = getRotationMatrix(x, y, z);

    M5.Display.fillScreen(M5.Display.color565(10, 10, 10));

    // Exibir valores X, Y, Z no canto superior esquerdo
    M5.Display.setCursor(5, 5);
    M5.Display.printf("X: %d", (int)(x * 100));

    M5.Display.setCursor(5, 17);
    M5.Display.printf("Y: %d", (int)(y * 100));

    M5.Display.setCursor(5, 29);
    M5.Display.printf("Z: %d", (int)(z * 100));

    draw3DCube(rotationMatrix);
}
