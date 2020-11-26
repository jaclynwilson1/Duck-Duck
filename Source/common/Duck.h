#ifndef __DUCK__
#define __DUCK__

#include "common.h"

class Duck{
    vec2 duck_vert[4];
    vec3 duck_color[4];
    int num_duck_vert = sizeof(duck_vert)/sizeof(duck_vert[0]);

    
    struct{
        int health;
        vec2 position;
        float gravity = 0.0040;
        bool jump = false;
        float max_jump_height = 0.5;
        bool grounded = true;
        bool running = false;
        int direction;
        float run_speed = 0.003;
        
        
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
        void land();
        void run(int direction);
        void stop();
        int get_direction();
        void gl_init();
        void draw(mat4 proj);
};

#endif