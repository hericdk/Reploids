#include "../headers/utils_3d.h"

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

Point3D rotatePoint(Point3D p, RotationMatrix rotationMatrix)
{
    Point3D rotated;
    rotated.x = p.x * rotationMatrix.matrix[0] + p.y * rotationMatrix.matrix[3] + p.z * rotationMatrix.matrix[6];
    rotated.y = p.x * rotationMatrix.matrix[1] + p.y * rotationMatrix.matrix[4] + p.z * rotationMatrix.matrix[7];
    rotated.z = p.x * rotationMatrix.matrix[2] + p.y * rotationMatrix.matrix[5] + p.z * rotationMatrix.matrix[8];
    return rotated;
}

void draw3DCube(RotationMatrix rotationMatrix)
{
    int screenWidth = M5.Display.width();
    int screenHeight = M5.Display.height();
    int centerX = screenWidth / 2;
    int centerY = screenHeight / 2;
    int scale = 20;

    Point3D cubeVertices[8] = {
        {-1, -1, -1}, {1, -1, -1}, {1, 1, -1}, {-1, 1, -1}, 
        {-1, -1, 1}, {1, -1, 1}, {1, 1, 1}, {-1, 1, 1}};

    int cubeEdges[12][2] = {
        {0, 1}, {1, 2}, {2, 3}, {3, 0}, {4, 5}, {5, 6}, {6, 7}, {7, 4}, {0, 4}, {1, 5}, {2, 6}, {3, 7}};

    Point3D projected[8];
    for (int i = 0; i < 8; i++)
    {
        projected[i] = rotatePoint(cubeVertices[i], rotationMatrix);
        projected[i].x = projected[i].x * scale + centerX;
        projected[i].y = projected[i].y * scale + centerY;
    }

    for (int i = 0; i < 12; i++)
    {
        int x1 = projected[cubeEdges[i][0]].x;
        int y1 = projected[cubeEdges[i][0]].y;
        int x2 = projected[cubeEdges[i][1]].x;
        int y2 = projected[cubeEdges[i][1]].y;

        M5.Display.drawLine(x1, y1, x2, y2, TFT_WHITE);
    }
}

void draw3DGrid(RotationMatrix rotationMatrix, float scale)
{
    int screenWidth = M5.Display.width();
    int screenHeight = M5.Display.height();
    int centerX = screenWidth / 2;
    int centerY = screenHeight / 2 + 40;

    for (int i = -10; i <= 10; i++)
    {
        for (int j = -10; j <= 10; j++)
        {
            Point3D p1 = {static_cast<float>(i), -1.0f, static_cast<float>(j)};
            Point3D p2 = {static_cast<float>(i + 1), -1.0f, static_cast<float>(j)};
            Point3D p3 = {static_cast<float>(i), -1.0f, static_cast<float>(j + 1)};

            p1 = rotatePoint(p1, rotationMatrix);
            p2 = rotatePoint(p2, rotationMatrix);
            p3 = rotatePoint(p3, rotationMatrix);

            p1.x = p1.x * scale + centerX;
            p1.y = p1.y * scale + centerY;
            p2.x = p2.x * scale + centerX;
            p2.y = p2.y * scale + centerY;
            p3.x = p3.x * scale + centerX;
            p3.y = p3.y * scale + centerY;

            int depthFactor = map(j, -10, 10, 120, 30);
            uint16_t gridColor = M5.Display.color565(depthFactor, depthFactor, depthFactor);

            M5.Display.drawLine(p1.x, p1.y, p2.x, p2.y, gridColor);
            M5.Display.drawLine(p1.x, p1.y, p3.x, p3.y, gridColor);
        }
    }
}