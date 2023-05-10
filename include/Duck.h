#ifndef __DUCK__
#define __DUCK__

#include "common.h"

class Duck{
    std::vector <vec3> vertices;
    std::vector <vec3> initial_hitbox;

    std::vector <vec3> hitbox;
    int num_beak_vert;
    int num_head_vert;
    int num_body_vert;
    int num_leg_vert;
    int num_wing_vert;
    int num_eye_vert;

    std::vector <vec3> normals;
    std::vector <vec2> uvs;
    std::vector <vec3> colors;

    std::vector <vec3> current_vertices;//used when animating

    vec2 tex_coord[4];

    

    
    struct{
        bool* alive;
        vec2 position = vec2(-0.8,-0.75);
        float gravity = 0.010;
        float jump_speed = 0.03;
        bool jump = false;
        float max_jump_height = 0.5;
        bool grounded = true;
        bool running = false;
        int direction = 1;
        float run_speed = 0.01;
        vec2 feet;
        int current_map = 0;
    } state;

    struct {
    GLuint vao;           //Vertex array object
    GLuint program;       //shader program
    GLuint buffer;        //Vertex buffer objects
    GLuint vertex_shader, fragment_shader;  //Shaders
    GLint vPosition,vNormal,vColor, vTexCoord;   //reference to pos and color in shaders
    GLint M_location;     //Reference to matrix in shader
    GLint tex_coord_location;
    unsigned int texture;
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
        bool ground_check(std::vector<std::vector <vec3>> platforms); //vec4 h1, vec4 h2, vec4 v1, vec4 v2, vec4 v11, vec4 v22
        bool wall_check(std::vector<std::vector <vec3>> platforms);
        bool ceiling_check(std::vector<std::vector <vec3>> platforms);
        std::vector<vec3> get_current_vertices(){return current_vertices;}
        std::vector<vec3> get_hitbox(){return hitbox;}

        vec2 get_position(){return state.position;}
        int get_current_map(){return state.current_map;}
        bool* get_alive_pointer(){return state.alive;}
};

#endif