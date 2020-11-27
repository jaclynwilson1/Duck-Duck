//Duck! Duck!
#include "common.h"


Duck::Duck(){
    //draw the duck here
    duck_vert[0] = vec2(0,0);
    duck_vert[1] = vec2(0,0.1);
    duck_vert[2] = vec2(0.1,0.1);
    duck_vert[3] = vec2(0.1,0);

    duck_color[0] = vec3(1,1,0);
    duck_color[1] = vec3(1,1,0);
    duck_color[2] = vec3(1,1,0);
    duck_color[3] = vec3(1,1,0);


};

bool Duck::ground_check(std::vector<std::vector <vec4>> platforms){
    //Returns true if duck is standing on a platform
    std::vector <vec4> ground_lines;

    for (int i = 0; i < platforms.size(); i++){
        //These points should be the top of each platforms
        ground_lines.push_back(platforms[i][0]);
        ground_lines.push_back(platforms[i][1]);
    }
    for(int i = 0; i < ground_lines.size(); i+=2){
        if(state.position.x >= ground_lines[i].x && state.position.x <= ground_lines[i+1].x){
            if(state.position.y >= ground_lines[i].y-(state.gravity*2) && state.position.y<=ground_lines[i].y){ //Might need to change this to a small range above and below if there are bugs
                state.ground_y = ground_lines[i].y;
                return true;
            }
        }
    }

    return false;

}

bool Duck::wall_check(std::vector<std::vector <vec4>> platforms){
    std::vector <vec4> wall_lines;
    for (int i = 0; i < platforms.size(); i++){
        //These points should be the top of each platforms
        wall_lines.push_back(platforms[i][0]);
        wall_lines.push_back(platforms[i][6]);
        wall_lines.push_back(platforms[i][1]);
        wall_lines.push_back(platforms[i][7]);
    }
    for(int i = 0; i < wall_lines.size(); i+=2){
        if(state.position.y < wall_lines[i].y && state.position.x >= wall_lines[i+1].y){
            if(state.position.x >= wall_lines[i].x && state.position.x<=wall_lines[i+2].x){ //Might need to change this to a small range above and below if there are bugs
                if(state.position.x <= (wall_lines[i].x+wall_lines[i+2].x)/2){
                    state.ground_x = wall_lines[i].x;
                }else {
                    state.ground_x = wall_lines[i+2].x;
                }
                
                return true;
            }
        }
    }
    

    return false;
}

void Duck::update_state(Map map){
    //Set GL state to use vertex array object
    glBindVertexArray(GLvars.vao);
    //Set GL state to use this buffer
    glBindBuffer(GL_ARRAY_BUFFER, GLvars.buffer);

    int num_duck_vert = sizeof(duck_vert)/sizeof(duck_vert[0]);
    vec2 temp_duck_vert[4];

    for (int i = 0; i<num_duck_vert; i++){
        temp_duck_vert[i] = vec2(duck_vert[i].x + state.position.x,duck_vert[i].y + state.position.y);
        
        if(state.running){
            if(wall_check(map.get_platforms())){//If touching wall, no movement
                state.position.x = state.ground_x;
            }
            state.position.x += state.direction * state.run_speed;
        }

        //Grounded is used to detect if duck is on the ground
        //If not grounded, duck can't jump
        //Need Map to interact with duck and grounded
        
        if (state.jump){
            state.position.y += 0.01;
            if(state.position.y >= state.ground_y + state.max_jump_height){state.jump = false;}
        }else {
            state.position.y -= state.gravity;
            /*if (state.position.y <=0) {state.position.y = 0;state.grounded=true;}*/
            if (ground_check(map.get_platforms())){
                state.position.y = state.ground_y;
                state.grounded=true;
            }    
        }
    }
    //Send new vertices to buffer
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(temp_duck_vert), temp_duck_vert);
    glBindVertexArray(0);

}

void Duck::jump(){if (state.grounded){state.jump = true;state.grounded = false;}}
void Duck::land(){state.jump = false;}

void Duck::run(int direction){
    //Move duck horizontally
    //- for left; + for right
    state.running = true;
    state.direction = direction;
}

void Duck::stop(){state.running = false;}
int Duck::get_direction(){return state.direction;}



void Duck::gl_init(){
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
    glBufferData(GL_ARRAY_BUFFER, sizeof(duck_vert) + sizeof(duck_color), NULL, GL_STATIC_DRAW);
    //First part of array holds vertices
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(duck_vert), duck_vert);
    //Second part of array hold colors (offset by sizeof(triangle))
    glBufferSubData(GL_ARRAY_BUFFER, sizeof(duck_vert), sizeof(duck_color), duck_color);

    glEnableVertexAttribArray(GLvars.vpos_location);
    glEnableVertexAttribArray(GLvars.vcolor_location);

    glVertexAttribPointer(GLvars.vpos_location, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
    glVertexAttribPointer(GLvars.vcolor_location, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(sizeof(duck_vert)));

    glBindVertexArray(0);
}

void Duck::draw(mat4 proj){
    glUseProgram(GLvars.program);
    glBindVertexArray(GLvars.vao);

    //If you have a modelview matrix, pass it with proj
    glUniformMatrix4fv(GLvars.M_location, 1, GL_TRUE, proj);

    //Draw something
    glDrawArrays(GL_LINE_LOOP, 0, num_duck_vert);

    glBindVertexArray(0);
    glUseProgram(0);
}