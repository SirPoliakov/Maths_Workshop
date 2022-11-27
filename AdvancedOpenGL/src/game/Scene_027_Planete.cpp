#include "Scene_027_Planete.h"
#include "CubeObject.h"
#include "../engine/Timer.h"
#include "../engine/MacroUtils.h"
#include "../engine/Log.h"

#include <cstdlib>
#include <ctime>
#include <GL/glew.h>


Scene_027_Planete::Scene_027_Planete() {

}

Scene_027_Planete::~Scene_027_Planete() {
    clean();
}

void Scene_027_Planete::setGame(Game *_game) {
    game = _game;
}

void Scene_027_Planete::clean() {

}

void Scene_027_Planete::pause() {
}

void Scene_027_Planete::resume() {
}

void Scene_027_Planete::handleEvent(const InputState &inputState) {

}

void Scene_027_Planete::load() 
{
    std::srand((int) std::time(nullptr));
    Assets::loadShader(SHADER_VERT(SHADER_NAME), SHADER_FRAG(SHADER_NAME), SHADER_TECS(SHADER_NAME), SHADER_TESE(SHADER_NAME), SHADER_GEOM(SHADER_NAME), SHADER_ID(SHADER_NAME));
    projection = Matrix4::createPerspectiveFOV(70.0f, game->windowWidth, game->windowHeight, 0.1f, 1000.0f);

    shader = Assets::getShader(SHADER_ID(SHADER_NAME));
    myCubeMesh.load();
    myObject = new CubeObject(0,0, &myCubeMesh);

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glEnable(GL_DEPTH_TEST);
}

void Scene_027_Planete::update(float dt) 
{
    
    interp_frac = Maths::abs(Maths::sin(Timer::getTimeSinceStart()));
    // float y = Maths::sin(Timer::getTimeSinceStart() * 0.5f);
    // float x = Maths::cos(Timer::getTimeSinceStart() * 0.5f);
    // myObject->setPosition(x, y);$
    unsigned int t = SDL_GetTicks();
    innerTesVal = 5 + 5 * Maths::sin(t/250);
    outerTesVal = Maths::abs(innerTesVal - 2);
    myObject->update();
    
}

void Scene_027_Planete::draw()
{
    static const GLfloat bgColor[] = {0.0f, 0.0f, 0.2f, 1.0f};
    glClearBufferfv(GL_COLOR, 0, bgColor);
    shader.use();
    float r = Maths::abs(Maths::sin(Timer::getTimeSinceStart()));
    float g = Maths::abs(Maths::cos(Timer::getTimeSinceStart()));
    float b = Maths::abs(Maths::tan(Timer::getTimeSinceStart()));
    Vector4 myColor{r,g,b,1} ;
    shader.setVector4f("colorChange", myColor);
    shader.setFloat("interp_frac", interp_frac);
    shader.setMatrix4("proj_matrix", projection);
    shader.setFloat("innerVal", innerTesVal);
    shader.setFloat("outerVal", outerTesVal);
    myObject->draw(shader);
}