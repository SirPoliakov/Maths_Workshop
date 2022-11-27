#include "CubeMesh.h"


 void CubeMesh::load(){

    
    static const GLfloat vertexPositions[] =
    {
      -1, -1,  1,
       1, -1,  1,
      -1,  1,  1,
       1,  1,  1,
      -1, -1, -1,
       1, -1, -1,
      -1,  1, -1,
       1,  1, -1,
    };

      static const GLint indices[] =
    {
      //Top
      2, 7, 6,
      2, 3, 7,

      //Bottom
      0, 4, 5,
      5, 1, 0,

      //Left
      0, 2, 6,
      6, 4, 0,

      //Right
      1, 7, 3,
      5, 7, 1,

      //Front
      0, 1, 3,
      0, 3, 2,

      //Back
      4, 6, 7,
      7, 5, 4
    };

    glGenVertexArrays(1, &vao);
   

    // Generate data and put it in buffer object
    glGenBuffers(1, &buffer);
    glGenBuffers(1, &EBO);
   
    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexPositions), vertexPositions, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices),indices, GL_STATIC_DRAW);

    // Setup vertex attribute 
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);  // How OpenGL "reads" the datas we just stored upper in the buffer ("Where do we start, 3 by 3, they are floats, normalizable or fixed-points, offset between vertices to ignore any other datas and the first offset if needed ")
    glEnableVertexAttribArray(0);  // If not, the current value of the attribute is used for all vertices.
 }

 void CubeMesh::draw(){

    glDrawElements(GL_PATCHES, 36, GL_UNSIGNED_INT, nullptr);

 }

 void CubeMesh::clean(){
    glDeleteVertexArrays(1, &vao);
 }