#include "utils_3d.h"

// **Função para criar a matriz de rotação**
RotationMatrix getRotationMatrix(float angleX, float angleY, float angleZ)
{
    RotationMatrix rotationMatrix;

    float cx = cos(angleX), sx = sin(angleX);
    float cy = cos(angleY), sy = sin(angleY);
    float cz = cos(angleZ), sz = sin(angleZ);

    rotationMatrix.matrix[0] = cy * cz;
    rotationMatrix.matrix[1] = cy * sz;
    rotationMatrix.matrix[2] = -sy;

    rotationMatrix.matrix[3] = sx * sy * cz - cx * sz;
    rotationMatrix.matrix[4] = sx * sy * sz + cx * cz;
    rotationMatrix.matrix[5] = sx * cy;

    rotationMatrix.matrix[6] = cx * sy * cz + sx * sz;
    rotationMatrix.matrix[7] = cx * sy * sz - sx * cz;
    rotationMatrix.matrix[8] = cx * cy;

    return rotationMatrix;
}

// **Função para rotacionar um ponto usando a matriz de rotação**
Point3D rotatePoint(Point3D p, RotationMatrix rotationMatrix)
{
    Point3D rotated;
    rotated.x = p.x * rotationMatrix.matrix[0] + p.y * rotationMatrix.matrix[3] + p.z * rotationMatrix.matrix[6];
    rotated.y = p.x * rotationMatrix.matrix[1] + p.y * rotationMatrix.matrix[4] + p.z * rotationMatrix.matrix[7];
    rotated.z = p.x * rotationMatrix.matrix[2] + p.y * rotationMatrix.matrix[5] + p.z * rotationMatrix.matrix[8];
    return rotated;
}