#ifndef CUBEOBJECT_H
#define CUBEOBJECT_H

#include "../engine/maths/Matrix4.h"

class CubeMesh;
class Shader;

enum Axe{
    DROITE,
    GAUCHE,
    HAUT,
    BAS
};

class CubeObject{
    public:
    CubeObject(float xP, float yP, CubeMesh* cubeMeshP);

    void update();
    void draw(Shader& shader);

    float getX() const {return x;}
    float getY(){return y;}
    void setDir(Axe axe){direction = axe;}

    void setPosition(float xP, float yP);
    Matrix4 computeTransform();

    private:
    float x { 0 };
    float y { 0 };
    Matrix4 transform {};
    float newXPosition { 0 };
    float newYPosition { 0 };
    Axe direction { DROITE };

    CubeMesh* cubeMesh{nullptr};
};

#endif