#ifndef __BULLET__
#define __BULLET__

#include "common.h"

class Bullet{
    std::vector <vec3> vertices;
    std::vector <std::vector<vec3>> bullet;
    vec3 direction;
    std::vector <vec3> colors;
    int max_bullet = 3;
    float radius = 0.015;

    struct{
        vec3 velocity;
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
        Bullet(vec3 position, vec3 direction);
        void gl_init();
        void draw(mat4 proj);
        void update_state(Map map, std::vector <vec3> duck_vert, std::vector<std::vector<vec3>> hunters_hitboxes);
        //std::vector<vec3> gen_bullet(vec3 position, vec3 direction);
        bool ground_check(std::vector<std::vector <vec3>> platforms);
        bool wall_check(std::vector<std::vector <vec3>> platforms);
        bool duck_check(std::vector<vec3> duck_vert);
        bool hunters_check(std::vector<std::vector<vec3>> hunters_hitboxes);
};


#endif