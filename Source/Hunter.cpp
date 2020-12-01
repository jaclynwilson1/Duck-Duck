//Duck! Duck!
#include "common.h"


Hunter::Hunter(){
    //draw the hunter here
    vertices.push_back(vec3(-0.025,0,0));
    vertices.push_back(vec3(-0.025,0.075,0));
    vertices.push_back(vec3(0.025,0.075,0));
    vertices.push_back(vec3(0.025,0,0));

    for(int i = 0; i < vertices.size();i++){
        colors.push_back(vec3(1,0,0));
    }


};

bool Hunter::ground_check(std::vector<std::vector <vec3>> platforms){
    //Returns true if hunter is standing on a platform
    std::vector <vec3> ground_lines;

    for (int i = 0; i < platforms.size(); i++){
        //These points should be the top of each platforms
        ground_lines.push_back(platforms[i][4]);//[i][0] with the 3D functions
        ground_lines.push_back(platforms[i][3]);//[i][1] with the 3D functions
    }
    for(int i = 0; i < ground_lines.size(); i+=2){
        if(state.position.x >= ground_lines[i].x && state.position.x <= ground_lines[i+1].x){
            if(state.position.y >= ground_lines[i].y-(state.gravity*2) && state.position.y<=ground_lines[i].y){ //Might need to change this to a small range above and below if there are bugs
                state.feet.y = ground_lines[i].y;
                return true;
            }
        }
    }

    return false;

}

bool Hunter::wall_check(std::vector<std::vector <vec3>> platforms){
    std::vector <vec3> wall_lines;
    for (int i = 0; i < platforms.size(); i++){
        //These points should be the top of each platforms
        wall_lines.push_back(platforms[i][4]); //[i][0] with the 3D functions
        wall_lines.push_back(platforms[i][0]); //[i][6]
        wall_lines.push_back(platforms[i][3]); //[i][1]
        wall_lines.push_back(platforms[i][2]); //[i][7]
    }
    for(int i = 0; i < wall_lines.size(); i+=4){
        if(state.position.y < wall_lines[i].y && state.position.y >= wall_lines[i+1].y){
            if(state.position.x >= wall_lines[i].x && state.position.x<=wall_lines[i+2].x){ //Might need to change this to a small range above and below if there are bugs
                if(state.position.x <= (wall_lines[i].x+wall_lines[i+2].x)/2){
                    state.feet.x = wall_lines[i].x;
                }else {
                    state.feet.x = wall_lines[i+2].x;
                }
                
                return true;
            }
        }
    }
    

    return false;
}

void Hunter::update_state(Map map){
    //Set GL state to use vertex array object
    glBindVertexArray(GLvars.vao);
    //Set GL state to use this buffer
    glBindBuffer(GL_ARRAY_BUFFER, GLvars.buffer);

    int num_vertices = sizeof(vertices)/sizeof(vertices[0]);
    std::vector <vec3> temp_vertices;

    for (int i = 0; i<vertices.size(); i++){
        temp_vertices.push_back(vec3(vertices[i].x + state.position.x,vertices[i].y + state.position.y,0));
        
        if(state.running){
            if(wall_check(map.get_platforms())){//If touching wall, no movement
                state.position.x = state.feet.x;
            }
            state.position.x += state.direction * state.run_speed;
        }

        //Grounded is used to detect if hunter is on the ground
        //If not grounded, hunter can't jump
        //Need Map to interact with hunter and grounded
        
        if (state.jump){
            state.position.y += 0.01;
            if(state.position.y >= state.feet.y + state.max_jump_height){state.jump = false;}
        }else {
            state.position.y -= state.gravity;
            /*if (state.position.y <=0) {state.position.y = 0;state.grounded=true;}*/
            if (ground_check(map.get_platforms())){
                state.position.y = state.feet.y;
                state.grounded=true;
            }    
        }
    }
    current_vertices.resize(temp_vertices.size());
    current_vertices = temp_vertices;
    //Send new vertices to buffer
    glBufferSubData(GL_ARRAY_BUFFER, 0, temp_vertices.size()*sizeof(temp_vertices[0]), &temp_vertices[0]);
    glBindVertexArray(0);

}

void Hunter::jump(){if (state.grounded){state.jump = true;state.grounded = false;}}
void Hunter::land(){state.jump = false;}

void Hunter::run(int direction){
    //Move hunter horizontally
    //- for left; + for right
    state.running = true;
    state.direction = direction;
}

void Hunter::stop(){state.running = false;}
int Hunter::get_direction(){return state.direction;}



void Hunter::gl_init(){
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

void Hunter::draw(mat4 proj){
    glUseProgram(GLvars.program);
    glBindVertexArray(GLvars.vao);

    //If you have a modelview matrix, pass it with proj
    glUniformMatrix4fv(GLvars.M_location, 1, GL_TRUE, proj);

    //Draw something
    glDrawArrays(GL_LINE_LOOP, 0, vertices.size());

    glBindVertexArray(0);
    glUseProgram(0);
}