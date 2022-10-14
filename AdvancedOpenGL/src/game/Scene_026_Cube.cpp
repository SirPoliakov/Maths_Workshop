#include "Scene_026_Cube.h"
#include "../engine/Timer.h"
#include "../engine/MacroUtils.h"

#include <cstdlib>
#include <ctime>
#include <GL/glew.h>

#include "CubeMesh.h"


Scene_026_Cube::Scene_026_Cube()
{
}

Scene_026_Cube::~Scene_026_Cube() {
    clean();
}

void Scene_026_Cube::setGame(Game *_game) {
    game = _game;
}

void Scene_026_Cube::load() {
    std::srand((int) std::time(nullptr));
    Assets::loadShader(SHADER_VERT(SHADER_NAME), SHADER_FRAG(SHADER_NAME), "", "", "", SHADER_ID(SHADER_NAME));

    projection = Matrix4::createPerspectiveFOV(70.0f, game->windowWidth, game->windowHeight, 0.1f, 1000.0f);

    cubeMesh = new CubeMesh();
    cubeMesh->load();

    glEnable(GL_CULL_FACE);
    glFrontFace(GL_CW);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    shader = Assets::getShader(SHADER_ID(SHADER_NAME));

    cubes.emplace_back(0.0f, 0.0f, cubeMesh);
}

void Scene_026_Cube::clean() {
    cubeMesh->clean();
    delete cubeMesh;
}

void Scene_026_Cube::pause() {
}

void Scene_026_Cube::resume() {
}

void Scene_026_Cube::handleEvent(const InputState &inputState) {
}

void Scene_026_Cube::update(float dt) {
    for (auto& cube : cubes){
        cube.update();
    }
    // float formerXPosition = cubes[0].getX();
    // newXPosition = formerXPosition + 0.02f;
    // cubes[0].setPosition(newXPosition, cubes[0].getY());
}

void Scene_026_Cube::draw() {

    static const GLfloat bgColor[] = {0.0f, 0.0f, 0.0f, 1.0f};
    glClearBufferfv(GL_COLOR, 0, bgColor);
    
    shader.use();
    shader.setMatrix4("proj_matrix", projection);

    for (auto& cube : cubes){
        cube.draw(shader);
    }
}
