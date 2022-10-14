

#ifndef SCENE_026_CUBE_H
#define SCENE_026_CUBE_H

#include "../engine/Scene.h"
#include "../engine/Assets.h"
#include "CubeObject.h"

class Scene_026_Cube : public Scene {
public:
    Scene_026_Cube();
    ~Scene_026_Cube();
    void load();
    void clean();
    void pause();
    void resume();
    void handleEvent(const InputState &);
    void update(float dt);
    void draw();
    void setGame(Game *);

private:
    Game *game;

    CubeMesh* cubeMesh;
    Matrix4 projection;
    Shader shader;

    vector<CubeObject> cubes;
    //float newXPosition { 0 };
};


#endif //SCENE_026_CUBE