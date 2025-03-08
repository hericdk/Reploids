#include <M5Unified.h>
#include "headers/utils_3d.h"

void grid3D()
{
  float x, y, z;
  M5.Imu.getAccel(&x, &y, &z);

  RotationMatrix rotationMatrix = getRotationMatrix(x, y, z);

  M5.Display.fillScreen(M5.Display.color565(10, 10, 10)); // Fundo cinza escuro

  M5.Display.setCursor(5, 5);
  M5.Display.printf("X: %d", (int)(x * 100));

  M5.Display.setCursor(5, 17);
  M5.Display.printf("Y: %d", (int)(y * 100));

  M5.Display.setCursor(5, 29);
  M5.Display.printf("Z: %d", (int)(z * 100));

  draw3DGrid(rotationMatrix, 10); // Renderiza a malha inferior
  draw3DCube(rotationMatrix);     // Renderiza o cubo
}
