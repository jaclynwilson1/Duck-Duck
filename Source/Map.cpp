//Duck! Duck!
#include "common.h"

Map::Map(){
    //Generate the map by using gen_platforms to place platforms
    //Need to decide where to handle collision of duck and platform
    map_vert.resize(num_map_vert);
    platforms.push_back(gen_platform(vec4(-1,0,-1,1),1.25,0.5,1));
    platforms.push_back(gen_platform(vec4(0.25,0.5,1,1),0.5,0.5,1));


    std::vector<vec4> temp_platform;
    for(int i = 0; i < platform_count; i++){
        temp_platform =platforms[i];
        platforms.push_back(temp_platform);
    }
    for (int i = 0; i < platform_count; i++){
        for(int j=0;j < platforms[i].size();j++){
            map_vert.push_back(platforms[i][j]);
        }
    }
    for(int i = 0; i < num_map_vert;i++){
        map_color.push_back(vec4(0,1,0,1));
        map_normals.push_back(vec3(0,0,1));
    }



};

void Map::gl_init(){
    ////ADD SHADERS
    std::string vshader = shader_path + "vshader_Map.glsl";
    std::string fshader = shader_path + "fshader_Map.glsl";

    GLchar* vertex_shader_source = readShaderSource(vshader.c_str());
    GLchar* fragment_shader_source = readShaderSource(fshader.c_str());

    GLvars.vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(GLvars.vertex_shader, 1, (const GLchar**)&vertex_shader_source, NULL);
    glCompileShader(GLvars.vertex_shader);
    check_shader_compilation(vshader, GLvars.vertex_shader);

    GLvars.fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(GLvars.fragment_shader, 1, (const GLchar**)&fragment_shader_source, NULL);
    glCompileShader(GLvars.fragment_shader);
    check_shader_compilation(fshader, GLvars.fragment_shader);

    GLvars.program = glCreateProgram();
    glAttachShader(GLvars.program, GLvars.vertex_shader);
    glAttachShader(GLvars.program, GLvars.fragment_shader);

    glLinkProgram(GLvars.program);
    check_program_link(GLvars.program);

    glBindFragDataLocation(GLvars.program, 0, "fragColor");

    GLvars.vpos_location = glGetAttribLocation(GLvars.program, "vPos");
    GLvars.vcolor_location = glGetAttribLocation(GLvars.program, "vColor");
    GLvars.M_location = glGetUniformLocation(GLvars.program, "M");



    // Create a vertex array object
    glGenVertexArrays(1, &GLvars.vao);
    //Set GL state to use vertex array object
    glBindVertexArray(GLvars.vao);
    //Generate buffer to hold our vertex data
    glGenBuffers(1, &GLvars.buffer);
    //Set GL state to use this buffer
    glBindBuffer(GL_ARRAY_BUFFER, GLvars.buffer);
    //Create GPU buffer to hold vertices and color
    glBufferData(GL_ARRAY_BUFFER, sizeof(map_vert) + sizeof(map_color), NULL, GL_STATIC_DRAW);
    //First part of array holds vertices
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(map_vert), &map_vert[0]);
    //Second part of array hold colors (offset by sizeof(triangle))
    glBufferSubData(GL_ARRAY_BUFFER, sizeof(map_vert), sizeof(map_color), &map_color[0]);

    glEnableVertexAttribArray(GLvars.vpos_location);
    glEnableVertexAttribArray(GLvars.vcolor_location);

    glVertexAttribPointer(GLvars.vpos_location, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
    glVertexAttribPointer(GLvars.vcolor_location, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(sizeof(map_vert)));

    glBindVertexArray(0);
}

void Map::draw(mat4 proj){
    glUseProgram(GLvars.program);
    glBindVertexArray(GLvars.vao);

    //If you have a modelview matrix, pass it with proj
    glUniformMatrix4fv(GLvars.M_location, 1, GL_TRUE, proj);

    //Draw something
    glDrawArrays(GL_TRIANGLES, 0, num_map_vert);

    glBindVertexArray(0);
    glUseProgram(0);
}

std::vector <vec4> Map::gen_platform(vec4 location, float width,float height, float depth){
    //vec4 location is the upper left corner of the polygon, closest to the screen
    std::vector <vec4> vertices;
    float x = location.x;
    float y = location.y;
    float z = location.z;
    //Top face
    vertices.push_back(location);
    vertices.push_back(vec4(x+width,y,z));
    vertices.push_back(vec4(x+width,y,z-depth));

    vertices.push_back(vec4(x+width,y,z-depth));
    vertices.push_back(vec4(x,y,z-depth));
    vertices.push_back(location);

    //Bottom face
    vertices.push_back(vec4(x,y-height,z));
    vertices.push_back(vec4(x+width,y-height,z));
    vertices.push_back(vec4(x+width,y-height,z-depth));

    vertices.push_back(vec4(x+width,y-height,z-depth));
    vertices.push_back(vec4(x,y-height,z-depth));
    vertices.push_back(vec4(x,y-height,z));
    //Front face
    vertices.push_back(vec4(x,y-height,z));
    vertices.push_back(vec4(x+width,y-height,z));
    vertices.push_back(vec4(x+width,y,z));

    vertices.push_back(vec4(x+width,y,z));
    vertices.push_back(location);
    vertices.push_back(vec4(x,y-height,z));
    //Back face
    vertices.push_back(vec4(x,y-height,z-depth));
    vertices.push_back(vec4(x+width,y-height,z-depth));
    vertices.push_back(vec4(x+width,y,z-depth));

    vertices.push_back(vec4(x+width,y,z-depth));
    vertices.push_back(vec4(z,y,z-depth));
    vertices.push_back(vec4(x,y-height,z-depth));
    //Left face
    vertices.push_back(vec4(x,y-height,z-depth));
    vertices.push_back(vec4(x,y-height,z));
    vertices.push_back(location);

    vertices.push_back(location);
    vertices.push_back(vec4(x,y,z-depth));
    vertices.push_back(vec4(x,y-height,z-depth));
    //Right face
    vertices.push_back(vec4(x+width,y-height,z-depth));
    vertices.push_back(vec4(x+width,y-height,z));
    vertices.push_back(vec4(x+width,y,z));

    vertices.push_back(vec4(x+width,y,z));
    vertices.push_back(vec4(x+width,y,z-depth));
    vertices.push_back(vec4(x+width,y-height,z-depth));

    return vertices;
}

std::vector<std::vector <vec4>> Map::get_platforms(){
    return platforms;
}