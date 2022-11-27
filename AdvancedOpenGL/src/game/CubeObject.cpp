#include "../engine/Shader.h"
#include "CubeObject.h"
#include "CubeMesh.h"
#include "../engine/Timer.h"

CubeObject::CubeObject(float xP, float yP, CubeMesh* cubeMeshP) : cubeMesh { cubeMeshP }
{
    setPosition(xP, yP);
}

void CubeObject::update(){

   std::cout <<Timer::getTimeSinceStart()<<std::endl;
        const float t = Maths::sin(Timer::getTimeSinceStart() * 0.5f) - 0.8f;
    
    // transform = transform
    //              * Matrix4::createRotationY(1 * Maths::toRadians(1.0f));
    float y = Maths::sin(Timer::getTimeSinceStart() * 0.5f);
    float x = Maths::cos(Timer::getTimeSinceStart() * 0.5f);
    transform = Matrix4::createTranslation(Vector3(x,y,-12.0f)) *   Matrix4::createRotationY(t * Maths::toRadians(180.0f)) * Matrix4::createRotationX(t * Maths::toRadians(45.0f)); ;//setPosition(x, y);
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
    return Matrix4::createTranslation(Vector3(x, y, -12.0f));
}