#include "../engine/Scene.h"
#include "../engine/Assets.h"

#include "CubeObject.h"

class CubeMesh;

class Scene_007_SpinningCube : public Scene {
public:
    Scene_007_SpinningCube();
    ~Scene_007_SpinningCube();

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
    float newXPosition { 0 };
};
