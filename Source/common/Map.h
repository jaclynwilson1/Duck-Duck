#ifndef __MAP__
#define __MAP__

#include "common.h"

class map{
    vec4 map_vert[];
    vec3 map_normals[];
    int num_map_vert = sizeof(map_vert)/sizeof(vec4(0,0,0,0));

    struct {
    GLuint vao;           //Vertex array object
    GLuint program;       //shader program
    GLuint buffer;        //Vertex buffer objects
    GLuint vertex_shader, fragment_shader;  //Shaders
    GLint vpos_location, vcolor_location;   //reference to pos and color in shaders
    GLint M_location;     //Reference to matrix in shader
    } GLvars;

    public:
    Map();
    void gl_init();
    void draw(mat4 proj);

}


#endif