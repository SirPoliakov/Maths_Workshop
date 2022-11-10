#ifndef SCENE_027_PLANETE_H
#define SCENE_027_PLANETE_H
#include "../engine/Scene.h"
#include "../engine/Assets.h"
#include "CubeObject.h"

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
    GLuint vao;
    GLuint buffer;
    Shader shader;


};


#endif //SCENE_027_PLANETE