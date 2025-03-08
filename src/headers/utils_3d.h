#ifndef UTILS_3D_H
#define UTILS_3D_H

#include <cmath>

// **Estruturas para armazenar dados 3D**
struct Point3D
{
    float x, y, z;
};

struct RotationMatrix
{
    float matrix[9]; // Matriz 3x3
};

// **Declaração das funções**
RotationMatrix getRotationMatrix(float angleX, float angleY, float angleZ);
Point3D rotatePoint(Point3D p, RotationMatrix rotationMatrix);

#endif // UTILS_3D_H