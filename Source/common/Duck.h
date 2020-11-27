#ifndef __DUCK__
#define __DUCK__

#include "common.h"

class Duck{
    vec2 duck_vert[4];
    vec3 duck_color[4];
    int num_duck_vert = sizeof(duck_vert)/sizeof(duck_vert[0]);
    

    
    struct{
        int health;
        vec2 position = vec2(0,0);
        float gravity = 0.0040;
        bool jump = false;
        float max_jump_height = 0.5;
        bool grounded = true;
        bool running = false;
        int direction;
        float run_speed = 0.003;
        float ground_y = 0;
        float ground_x = 0;

        
        
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
        void update_state(Map map);
        void jump();
        void land();
        void run(int direction);
        void stop();
        int get_direction();
        void gl_init();
        void draw(mat4 proj);
        bool ground_check(std::vector<std::vector <vec4>> platforms); //vec4 h1, vec4 h2, vec4 v1, vec4 v2, vec4 v11, vec4 v22
        bool wall_check(std::vector<std::vector <vec4>> platforms);
};

#endif