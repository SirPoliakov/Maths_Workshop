#include "../engine/Shader.h"
#include "CubeObject.h"
#include "CubeMesh.h"

CubeObject::CubeObject(float xP, float yP, CubeMesh* cubeMeshP) : cubeMesh { cubeMeshP }
{
    setPosition(xP, yP);
}

void CubeObject::update(){
    float formerXPosition = getX();
    newXPosition = formerXPosition + 0.02f;
    setPosition(newXPosition, getY());
}

void CubeObject::draw(Shader& shader){
    shader.setMatrix4("mv_matrix", transform);
    cubeMesh->draw();
};

void CubeObject::setPosition(float xP, float yP) {
    x = xP;
    y = yP;
    transform = computeTransform();
}

Matrix4 CubeObject::computeTransform() {
    return Matrix4::createTranslation(Vector3(x, y, -4.0f));
}