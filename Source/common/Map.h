#ifndef __MAP__
#define __MAP__

#include "common.h"

class Map{
    std::vector <vec3> vertices;
    std::vector<std::vector <vec3>> platforms;
    int platform_count=0;
    std::vector <vec3> colors;
    std::vector <vec3> map_normals;
    int num_vertices = vertices.size();

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

    std::vector <vec3> gen_platform(vec3 location, float width,float height, float depth);
    std::vector<std::vector <vec3>> get_platforms();
};


#endif