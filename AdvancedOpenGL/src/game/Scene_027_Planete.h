#ifndef SCENE_027_PLANETE_H
#define SCENE_027_PLANETE_H
#include "../engine/Scene.h"
#include "../engine/Assets.h"
#include "CubeMesh.h"

class CubeObject;

class Scene_027_Planete : public Scene {
public:
    Scene_027_Planete();
    ~Scene_027_Planete();
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
    GLuint VAO;
    Shader shader;
    CubeMesh myCubeMesh;
    CubeObject* myObject;
    Matrix4 projection;
    float interp_frac;
    float innerTesVal;
    float outerTesVal;


};


#endif //SCENE_027_PLANETE