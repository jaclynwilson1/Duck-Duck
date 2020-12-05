//Duck! Duck!
#include "common.h"
#include "lodepng.h"

//GLuint duck_texture;

// Initialize shader lighting parameters
vec4 light(   0.0, 0.5, 10.0, 1.0 );
vec4 light_ambient(  0.1, 0.1, 0.1, 1.0 );
vec4 light_diffuse(  1.0, 1.0, 1.0, 1.0 );
vec4 light_specular( 1.0, 1.0, 1.0, 1.0 );

// Initialize DEFAULT shader material parameters
vec4 material_ambient( 0.1, 0.1, 0.1, 1.0 );
vec4 material_diffuse( 1.0, 0.8, 0.0, 1.0 );
vec4 material_specular( 0.8, 0.8, 0.8, 1.0 );
float  material_shininess = 10;

Duck::Duck(){
    //draw the duck here
    /*
    vertices.push_back(vec3(-0.025,0,0));
    vertices.push_back(vec3(-0.025,0.075,0));
    vertices.push_back(vec3(0.025,0.075,0));

    vertices.push_back(vec3(0.025,0.075,0));
    vertices.push_back(vec3(0.025,0,0));
    vertices.push_back(vec3(-0.025,0,0));

    for(int i = 0; i < vertices.size();i++){
        normals.push_back(vec3(0,0,1));
    }
    
    uvs.push_back(vec2(0,0));
    uvs.push_back(vec2(0,1));
    uvs.push_back(vec2(1,1));
    uvs.push_back(vec2(1,1));
    uvs.push_back(vec2(1,0));
    uvs.push_back(vec2(0,0));


    for(int i = 0; i < vertices.size();i++){
        colors.push_back(vec3(1,0,0));
    }
    */
   state.alive = (bool*) malloc(sizeof(bool));
    *state.alive = true;
   
   //**VERTICES**
    //Beak
    vertices.push_back(vec3(0.06, 0.1, 0));
    vertices.push_back(vec3(0.06, 0.07, 0));
    vertices.push_back(vec3(0.1, 0.085, 0));
    num_beak_vert = 3;

    //Leg
    vertices.push_back(vec3(-0.005, 0.05, 0));
    vertices.push_back(vec3(0.005, 0.05, 0));
    vertices.push_back(vec3(-0.005, 0, 0));
    vertices.push_back(vec3(0.005, 0.03, 0));
    vertices.push_back(vec3(0.03, 0, 0));
    num_leg_vert = 5;

    //Head
    for (int i = 0; i < 362; i+=10) {
        double parameterization = i * (M_PI / 180);
        vertices.push_back(vec3(0.025 * cos(parameterization)+0.05, 0.03 * sin(parameterization) + 0.09,0));
    }
    num_head_vert = vertices.size() - num_beak_vert - num_leg_vert;

    //Body
    for (int i = 191; i < 372; i+=10) {
        double parameterization = i * (M_PI / 180);
        vertices.push_back(vec3(0.05 * cos(parameterization), 0.05 * sin(parameterization)+0.07,0));
    }
    num_body_vert = vertices.size()- num_head_vert - num_beak_vert - num_leg_vert;

    //Wing
    vertices.push_back(vec3(-0.03,0.05, 0));
    vertices.push_back(vec3(0.025,0.06,0));
    vertices.push_back(vec3(0.01,0.03,0));
    num_wing_vert = 3;

    //Eye
    for (int i = 0; i < 362; i += 10) {
        double parameterization = i * (M_PI / 180);
        vertices.push_back(vec3(0.005 * cos(parameterization) + 0.06, 0.005 * sin(parameterization) + 0.09, 0));
    }
    num_eye_vert = vertices.size() - num_wing_vert - num_body_vert - num_head_vert - num_beak_vert - num_leg_vert;

    //**COLORS**
    //Beak
    colors.push_back(vec3(1, 0.6, 0));
    colors.push_back(vec3(1, 0.6, 0));
    colors.push_back(vec3(1, 0.6, 0));

    //Leg
    colors.push_back(vec3(1, 0.6, 0));
    colors.push_back(vec3(1, 0.6, 0));
    colors.push_back(vec3(1, 0.6, 0));
    colors.push_back(vec3(1, 0.6, 0));
    colors.push_back(vec3(1, 0.6, 0));

    //Head and Body
    for(int i = 0; i < vertices.size() - num_beak_vert - num_wing_vert - num_eye_vert - num_leg_vert; i++){
        colors.push_back(vec3(1,1,0));
    }

    //Wing
    colors.push_back(vec3(1,0.7,0.18));
    colors.push_back(vec3(1,0.7,0.18));
    colors.push_back(vec3(1,0.7,0.18));
    
    //Eye
    for (int i = 0; i < vertices.size() - num_wing_vert - num_body_vert - num_head_vert - num_beak_vert - num_leg_vert; i++) {
        colors.push_back(vec3(0, 0, 0));
    }

    
    initial_hitbox.push_back(vec3(-0.03,0,0));
    initial_hitbox.push_back(vec3(0.03,0.1,0));


};

bool Duck::ground_check(std::vector<std::vector <vec3>> platforms){
    //Returns true if duck is standing on a platform
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

bool Duck::wall_check(std::vector<std::vector <vec3>> platforms){
    std::vector <vec3> wall_lines;
    for (int i = 0; i < platforms.size(); i++){
        //These points should be the top of each platforms
        wall_lines.push_back(platforms[i][4]); //[i][0] with the 3D functions
        wall_lines.push_back(platforms[i][0]); //[i][6]
        wall_lines.push_back(platforms[i][3]); //[i][1]
        wall_lines.push_back(platforms[i][2]); //[i][7]
    }
    for(int i = 0; i < wall_lines.size(); i+=4){
        if(state.position.y < wall_lines[i].y - state.gravity && state.position.y >= wall_lines[i+1].y){
            if(state.position.x > wall_lines[i].x-state.run_speed*5.5 && state.position.x<wall_lines[i+2].x+state.run_speed*5.5){ //Might need to change this to a small range above and below if there are bugs
                if(state.position.x <= (wall_lines[i].x+wall_lines[i+2].x)/2){
                    state.feet.x = wall_lines[i].x-state.run_speed*5.5;
                }else {
                    state.feet.x = wall_lines[i+2].x+state.run_speed*5.5;
                }
                
                return true;
            }
        }
    }
    

    return false;
}

bool Duck::ceiling_check(std::vector<std::vector <vec3>> platforms){
    std::vector <vec3> ceiling_lines;

    for (int i = 0; i < platforms.size(); i++){
        //These points should be the top of each platforms
        ceiling_lines.push_back(platforms[i][0]);//[i][0] with the 3D functions
        ceiling_lines.push_back(platforms[i][1]);//[i][1] with the 3D functions
    }
    for(int i = 0; i < ceiling_lines.size(); i+=2){
        if(state.position.x >= ceiling_lines[i].x && state.position.x <= ceiling_lines[i+1].x){
            if(state.position.y <= ceiling_lines[i].y && state.position.y>=ceiling_lines[i].y-state.jump_speed*4){ //Might need to change this to a small range above and below if there are bugs
                state.feet.y = ceiling_lines[i].y;
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

    std::vector <vec3> temp_vertices;
    hitbox.clear();
    for(int i=0;i<initial_hitbox.size();i++){
        hitbox.push_back(vec3(initial_hitbox[i].x+state.position.x,initial_hitbox[i].y+state.position.y,0));
    }

    if(state.running){
            if(wall_check(map.get_platforms())){//If touching wall, no movement
                state.position.x = state.feet.x;
            }
            state.position.x += state.direction * state.run_speed;
        }

        //Grounded is used to detect if duck is on the ground
        //If not grounded, duck can't jump
        //Need Map to interact with duck and grounded
        
        if (state.jump){
            if(!ceiling_check(map.get_platforms())){
                state.position.y += state.jump_speed;
            }
            if(state.position.y >= state.feet.y + state.max_jump_height){state.jump = false;}
        }else {
            /*if (state.position.y <=0) {state.position.y = 0;state.grounded=true;}*/
            if (ground_check(map.get_platforms())){
                state.position.y = state.feet.y;
                state.grounded=true;
            }else {
                state.position.y -= state.gravity;
            }
        }

    for (int i = 0; i<vertices.size(); i++){
        temp_vertices.push_back(vec3((vertices[i].x + state.position.x),vertices[i].y + state.position.y,0));
    }

    /*
    //Reflect duck across its middle if duck moving left
    if(state.direction == -1){
        for (int i = 0; i< temp_vertices.size();i++){
            if(temp_vertices[i].x<state.feet.x){
                temp_vertices[i].x += sqrt((pow(temp_vertices[i].x-state.feet.x,2)));
            }else if(temp_vertices[i].x>state.feet.x){
                temp_vertices[i].x = temp_vertices[i].x - sqrt((pow(temp_vertices[i].x-state.feet.x,2)));
            }
        }
    }
    */
    

    //Track which map duck is on
    if(state.position.x > 1 && state.current_map < 3){
        state.current_map += 1;
        state.position.x = -0.95;
    }
    if(state.position.x < -1 && state.current_map > 0){
        state.current_map -= 1;
        state.position.x = 0.95;

    }

    //Store temp_vertices for tracking collision with bullet
    if(temp_vertices.size()>0){
        current_vertices.resize(temp_vertices.size());
        current_vertices = temp_vertices;
    }

    //Check if alive
    if(!*state.alive){
        num_beak_vert = 0;
        num_head_vert = 0;
        num_body_vert = 0;
        num_leg_vert = 0;
        num_wing_vert = 0;
        num_eye_vert = 0;
        vertices.clear();
        temp_vertices.clear();
    }

    //Send new vertices to buffer
    glBufferSubData(GL_ARRAY_BUFFER, 0, temp_vertices.size()*sizeof(temp_vertices[0]), &temp_vertices[0]);
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

void loadFreeImageTexture(const char* lpszPathName, GLuint textureID, GLuint GLtex){
  //This is from the mapping assignment
  
  std::vector<unsigned char> image;
  unsigned int width;
  unsigned int height;
  //decode
  unsigned error = lodepng::decode(image, width, height, lpszPathName, LCT_RGBA, 8);

  //if there's an error, display it
  if(error){
    std::cout << "decoder error " << error;
    std::cout << ": " << lodepng_error_text(error) << std::endl;
    return;
  }

  /* the image "shall" be in RGBA_U8 format */

  std::cout << "Image loaded: " << width << " x " << height << std::endl;
  std::cout << image.size() << " pixels.\n";
  std::cout << "Image has " << image.size()/(width*height) << "color values per pixel.\n";

  GLint GL_format = GL_RGBA;

  glActiveTexture( GLtex );
  glBindTexture( GL_TEXTURE_2D, textureID );
  glTexImage2D( GL_TEXTURE_2D, 0, GL_format, width, height, 0, GL_format, GL_UNSIGNED_BYTE, &image[0] );
  glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
  glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
  glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
  glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
  glGenerateMipmap(GL_TEXTURE_2D);
  
  //Put things away and free memory
  image.clear();
}

void Duck::gl_init(){
    /* texture mapping attempt
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

    GLvars.vPosition = glGetAttribLocation(GLvars.program, "vPos");
    GLvars.vNormal = glGetAttribLocation(GLvars.program, "vNormal");
    GLvars.vColor = glGetAttribLocation(GLvars.program, "vColor");
    GLvars.M_location = glGetUniformLocation(GLvars.program, "M");
    GLvars.vTexCoord = glGetUniformLocation(GLvars.program, "vTexCoord");


    glGenTextures(1, &GLvars.texture);

    std::string duck_image = shader_path + "duck_right.png";
    loadFreeImageTexture(duck_image.c_str(), GLvars.texture, GL_TEXTURE0);
    glUniform1i( glGetUniformLocation(GLvars.program, "textureDuck"), 0 );


    // Create a vertex array object
    glGenVertexArrays(1, &GLvars.vao);
    //Set GL state to use vertex array object
    glBindVertexArray(GLvars.vao);

    //Generate buffer to hold our vertex data
    glGenBuffers(1, &GLvars.buffer);
    //Set GL state to use this buffer
    glBindBuffer(GL_ARRAY_BUFFER, GLvars.buffer);

    unsigned int vertices_bytes = vertices.size()*sizeof(vec3);
    unsigned int normals_bytes = normals.size()*sizeof(vec3);
    unsigned int uvs_bytes = uvs.size()*sizeof(vec2);
    unsigned int colors_bytes = colors.size()*sizeof(vec3);


    //Create GPU buffer to hold vertices and color
    glBufferData(GL_ARRAY_BUFFER, vertices_bytes + normals_bytes + uvs_bytes + colors_bytes , NULL, GL_STATIC_DRAW);
    unsigned int offset = 0;
    glBufferSubData(GL_ARRAY_BUFFER, offset, vertices_bytes, &vertices[0]);
    offset += vertices_bytes;
    glBufferSubData(GL_ARRAY_BUFFER, offset, normals_bytes, &normals[0]);
    offset += normals_bytes;
    glBufferSubData(GL_ARRAY_BUFFER, offset, uvs_bytes, &uvs[0]);
    offset += uvs_bytes;
    glBufferSubData(GL_ARRAY_BUFFER, offset, uvs_bytes, &uvs[0]);
    offset += colors_bytes;
    glBufferSubData(GL_ARRAY_BUFFER, offset, colors_bytes, &colors[0]);





    glEnableVertexAttribArray(GLvars.vPosition);
    glEnableVertexAttribArray(GLvars.vNormal);
    glEnableVertexAttribArray(GLvars.vTexCoord);
    glEnableVertexAttribArray(GLvars.vColor);



    glVertexAttribPointer(GLvars.vPosition, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
    glVertexAttribPointer(GLvars.vNormal, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(vertices_bytes));
    glVertexAttribPointer(GLvars.vTexCoord, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(vertices_bytes+normals_bytes));
    glVertexAttribPointer(GLvars.vColor, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(vertices_bytes+normals_bytes+uvs_bytes));


    glBindVertexArray(0);
    */
    /*
    std::string vshader = shader_path + "vshader.glsl";
    std::string fshader = shader_path + "fshader.glsl";

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

    GLvars.vPosition = glGetAttribLocation(GLvars.program, "vPos");
    GLvars.vColor = glGetAttribLocation(GLvars.program, "vColor");
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

    glEnableVertexAttribArray(GLvars.vPosition);
    glEnableVertexAttribArray(GLvars.vColor);

    glVertexAttribPointer(GLvars.vPosition, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
    glVertexAttribPointer(GLvars.vColor, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(vertices.size()*sizeof(vertices[0])));

    glBindVertexArray(0);
    */
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

    GLvars.vPosition = glGetAttribLocation(GLvars.program, "vPos");
    GLvars.vNormal = glGetAttribLocation(GLvars.program, "vNormal");
    GLvars.vColor = glGetAttribLocation(GLvars.program, "vColor");
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

    glEnableVertexAttribArray(GLvars.vPosition);
    glEnableVertexAttribArray(GLvars.vColor);

    glVertexAttribPointer(GLvars.vPosition, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
    glVertexAttribPointer(GLvars.vColor, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(vertices.size()*sizeof(vertices[0])));

    glBindVertexArray(0);
}

void Duck::draw(mat4 proj){
    glUseProgram(GLvars.program);
    //glBindTexture(GL_TEXTURE_2D, GLvars.texture);
    glBindVertexArray(GLvars.vao);

    //If you have a modelview matrix, pass it with proj
    glUniformMatrix4fv(GLvars.M_location, 1, GL_TRUE, proj);

    //Compute ambient, diffuse, and specular terms
    vec4 ambient_product  = light_ambient * material_ambient;
    vec4 diffuse_product  = light_diffuse * material_diffuse;
    vec4 specular_product = light_specular * material_specular;

    //Retrieve and set uniform variables
    glUniform4fv( glGetUniformLocation(GLvars.program, "Light"), 1, light);
    glUniform4fv( glGetUniformLocation(GLvars.program, "AmbientProduct"), 1, ambient_product );
    glUniform4fv( glGetUniformLocation(GLvars.program, "DiffuseProduct"), 1, diffuse_product );
    glUniform4fv( glGetUniformLocation(GLvars.program, "SpecularProduct"), 1, specular_product );
    glUniform1f(  glGetUniformLocation(GLvars.program, "Shininess"), material_shininess );
    //Draw something
    //glDrawArrays(GL_TRIANGLES, 0, vertices.size());
    glDrawArrays(GL_TRIANGLES, 0, num_beak_vert);
    glDrawArrays(GL_TRIANGLE_STRIP, num_beak_vert, num_leg_vert);
    glDrawArrays(GL_TRIANGLE_FAN, num_beak_vert + num_leg_vert, num_head_vert);
    glDrawArrays(GL_TRIANGLE_FAN, num_head_vert + num_beak_vert + num_leg_vert, num_body_vert);
    glDrawArrays(GL_TRIANGLES, num_head_vert + num_body_vert + num_beak_vert + num_leg_vert, num_wing_vert);
    glDrawArrays(GL_TRIANGLE_FAN, num_head_vert + num_body_vert + num_wing_vert + num_beak_vert + num_leg_vert, num_eye_vert);


    //glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    glBindVertexArray(0);
    glUseProgram(0);
}

