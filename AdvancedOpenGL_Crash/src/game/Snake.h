#include "CubeObject.h"
#include <vector>

const float CUBE_OFFSET = 0.6; 

class Snake {
    public:
    void load(CubeMesh* myCube);

    // Snake interactions:
    void handleTurn();
    void eat();
    void collision();

    // Getters :
    int getSize() {return size;}
    CubeObject* getHead(){return head;}
    std::vector<CubeObject> getBody(){return body;}

    private:
    CubeObject* head { &body[0] };
    std::vector<CubeObject> body;
    int size { 3 };
};