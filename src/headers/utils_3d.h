#ifndef UTILS_3D_H
#define UTILS_3D_H

#include <M5Unified.h>

// Estruturas para rotação 3D
struct Point3D
{
    float x, y, z;
};

struct RotationMatrix
{
    float matrix[9];
};

// Declarações das funções
RotationMatrix getRotationMatrix(float angleX, float angleY, float angleZ);
Point3D rotatePoint(Point3D p, RotationMatrix rotationMatrix);
void draw3DCube(RotationMatrix rotationMatrix);
void draw3DGrid(RotationMatrix rotationMatrix, float scale);

#endif