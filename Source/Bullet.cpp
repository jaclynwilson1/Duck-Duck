
#include "common.h"

Bullet::Bullet(vec3 position, vec2 velocity){
    position.y += 0.03;
    vertices.push_back(position);
    
    state.velocity = velocity;
    for (int i = 0; i < 362; i++) {
        double parameterization = i * (M_PI / 180);
        vertices.push_back(vec3(radius * cos(parameterization) + position.x, radius * sin(parameterization) + position.y,0));
    }
    for(int i = 0; i<vertices.size();i++){
        colors.push_back(vec3(1,0.75,0));
    }

    
};
/*
std::vector<vec3> Bullet::gen_bullet(vec3 position, vec3 direction){
    std::vector <vec3> bullet;
    directions.push_back(direction);
    bullet.push_back(position);
    for (int i = 0; i < 362; i++) {
        float radius = 0.02;
        double parameterization = i * (M_PI / 180);
        bullet.push_back(vec3(radius * cos(parameterization) + position.x, radius * sin(parameterization) + position.y,0));
    }

    return bullet;
}
*/

void Bullet::gl_init(){
    std::string vshader = shader_path + "vshader_Duck.glsl";
    std::string fshader = shader_path + "fshader_Duck.glsl";

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
    glBufferData(GL_ARRAY_BUFFER, vertices.size()*sizeof(vertices[0]) + colors.size()*sizeof(colors[0]), NULL, GL_STATIC_DRAW);
    //First part of array holds vertices
    glBufferSubData(GL_ARRAY_BUFFER, 0, vertices.size()*sizeof(vertices[0]), &vertices[0]);
    //Second part of array hold colors (offset by sizeof(triangle))
    glBufferSubData(GL_ARRAY_BUFFER, vertices.size()*sizeof(vertices[0]), colors.size()*sizeof(colors[0]), &colors[0]);

    glEnableVertexAttribArray(GLvars.vpos_location);
    glEnableVertexAttribArray(GLvars.vcolor_location);

    glVertexAttribPointer(GLvars.vpos_location, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
    glVertexAttribPointer(GLvars.vcolor_location, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(vertices.size()*sizeof(vertices[0])));

    glBindVertexArray(0);
}

void Bullet::draw(mat4 proj){
    glUseProgram(GLvars.program);
    glBindVertexArray(GLvars.vao);

    //If you have a modelview matrix, pass it with proj
    glUniformMatrix4fv(GLvars.M_location, 1, GL_TRUE, proj);

    //Draw something
    glDrawArrays(GL_TRIANGLE_FAN, 0, vertices.size());

    glBindVertexArray(0);
    glUseProgram(0);
}

void Bullet::update_state(Map map, std::vector<vec3> duck_vert, std::vector<std::vector<vec3>> hunters_hitboxes){
    //Set GL state to use vertex array object
    glBindVertexArray(GLvars.vao);
    //Set GL state to use this buffer
    glBindBuffer(GL_ARRAY_BUFFER, GLvars.buffer);


    for(int i=0; i< vertices.size();i++){
        vertices[i].x += state.velocity.x;
        vertices[i].y += state.velocity.y;
    }
    if(ground_check(map.get_platforms())){
        state.dead = true;
        vertices.clear();
    }
    if(wall_check(map.get_platforms())){
        state.dead = true;
        vertices.clear();

    }
    /*  Commented out for testing bullets. Need to check if start in duck.
    if(duck_check(duck_vert)){
        state.dead = true;
    }
    */
   /*
    if(hunters_check(hunters_hitboxes)){
        state.dead = true;
        vertices.clear();

    }
    */
    //Send new vertices to buffer
    glBufferSubData(GL_ARRAY_BUFFER, 0, vertices.size()*sizeof(vertices[0]), &vertices[0]);
    glBindVertexArray(0);
    
}

bool Bullet::ground_check(std::vector<std::vector <vec3>> platforms){
    //Returns true if duck is standing on a platform
    std::vector <vec3> ground_lines;

    for (int i = 0; i < platforms.size(); i++){
        //These points should be the top of each platforms
        ground_lines.push_back(platforms[i][4]);//[i][0] with the 3D functions
        ground_lines.push_back(platforms[i][3]);//[i][1] with the 3D functions
    }

    if (vertices[0].x > 1 || vertices[0].x < -1){
        return true;
    }
    for(int i = 0; i < ground_lines.size(); i+=2){
        if(vertices[0].x+radius >= ground_lines[i].x && vertices[0].x-radius <= ground_lines[i+1].x){
            if(vertices[0].y >= ground_lines[i].y-(2*radius) && vertices[0].y<=ground_lines[i].y){ //Might need to change this to a small range above and below if there are bugs
                return true;
            }
        }
    }

    return false;

}

bool Bullet::wall_check(std::vector<std::vector <vec3>> platforms){
    std::vector <vec3> wall_lines;
    for (int i = 0; i < platforms.size(); i++){
        //These points should be the top of each platforms
        wall_lines.push_back(platforms[i][4]); //[i][0] with the 3D functions
        wall_lines.push_back(platforms[i][0]); //[i][6]
        wall_lines.push_back(platforms[i][3]); //[i][1]
        wall_lines.push_back(platforms[i][2]); //[i][7]
    }

    if (vertices[0].y > 1 || vertices[0].y < -1){
        return true;
    }
    for(int i = 0; i < wall_lines.size(); i+=4){
        if(vertices[0].y < wall_lines[i].y && vertices[0].y >= wall_lines[i+1].y){
            if(vertices[0].x >= wall_lines[i].x && vertices[0].x<=wall_lines[i+2].x){ //Might need to change this to a small range above and below if there are bugs
                return true;
            }
        }
    }
    

    return false;
}

bool Bullet::duck_check(std::vector<vec3> duck_vert){
    if(vertices[0].x >= duck_vert[0].x && vertices[0].x <= duck_vert[2].x){
        if(vertices[0].y >= duck_vert[0].y && vertices[0].y <= duck_vert[2].y){
            return true;
        }
    }
    return false;

}
bool Bullet::hunters_check(std::vector<std::vector<vec3>> hunters_hitboxes){
    for(int i=0; i<hunters_hitboxes.size();i++){
        std::vector <vec3> hitbox = hunters_hitboxes[i];
        if(vertices[0].x >= hitbox[0].x && vertices[0].x <= hitbox[2].x){
            if(vertices[0].y >= hitbox[0].y && vertices[0].y <= hitbox[2].y){
                return true;
            }
        } 
    }
    
    return false;

}


