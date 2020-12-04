#ifndef __HUNTER__
#define __HUNTER__

#include "common.h"

class Hunter{
    std::vector <vec3> vertices;
    std::vector <vec3> colors;
    std::vector <vec3> current_vertices;
    

    
    struct{
        int health;
        vec2 position = vec2(0.5,0.5);
        float gravity = 0.06;
        bool jump = false;
        float max_jump_height = 0.5;
        bool grounded = true;
        bool running = false;
        int direction;
        float run_speed = 0.003;
        vec2 feet;

        
        
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
        Hunter();
        void update_state(Map map);
        void jump();
        void land();
        void run(int direction);
        void stop();
        int get_direction();
        void gl_init();
        void draw(mat4 proj);
        bool ground_check(std::vector<std::vector <vec3>> platforms); //vec4 h1, vec4 h2, vec4 v1, vec4 v2, vec4 v11, vec4 v22
        bool wall_check(std::vector<std::vector <vec3>> platforms);
        std::vector<vec3> get_current_vertices(){return current_vertices;}
        vec2 get_position(){return state.position;}
};

#endif