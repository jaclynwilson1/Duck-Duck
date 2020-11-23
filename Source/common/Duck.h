#ifndef __DUCK__
#define __DUCK__

#include "common.h"

class Duck{
    vec2 duck_vert[3];
    vec3 duck_color[3];
    struct{
        int health;
        vec2 velocity;
        
        
    } state;
    
    struct {
    GLuint vao;           //Vertex array object
    GLuint program;       //shader program
    GLuint buffer;        //Vertex buffer objects
    GLuint vertex_shader, fragment_shader;  //Shaders
    GLint vpos_location, vcolor_location;   //reference to pos and color in shaders
    GLint M_location;     //Reference to matrix in shader
  } GLvars;

    public:
        Duck();
        void update_state();
        void jump();
        void run(int direction);
        void gl_init();
        void draw(mat4 proj);
};

#endif