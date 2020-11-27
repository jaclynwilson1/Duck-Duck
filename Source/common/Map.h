#ifndef __MAP__
#define __MAP__

#include "common.h"

class map{
    std::vector <vec4> map_vert[];
    std::vector<vector <vec4>> platforms;
    std::vector <vec4> map_color[];
    std::vector <vec3> map_normals[];
    int num_map_vert = map_vert.size();

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

    std::vector <vec4> gen_platform(vec4 location, float width,float height, float depth);
    std::vector<vector <vec4>> get_platforms;
}


#endif