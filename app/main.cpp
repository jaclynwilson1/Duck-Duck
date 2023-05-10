//Duck! Duck!
//main.cpp

#include "common.h"

using namespace Angel;

/**
 * Initializes the duck and multiple maps
*/
Duck duck;
std::vector <Map> maps;
Map map0(0);
Map map1(1);
Map map2(2);
int current_map;

/**
 * Initializes the hunters on each map
*/
std::vector<std::vector<vec3>> hunters_hitboxes;
Hunter hunter0;
Hunter hunter1;
Hunter hunter2;
Hunter hunter3;
bool unplaced23=true;
/*Alive hunters bool true when alive*/
std::vector<bool*> hunters_alive_pointers;



std::vector<Bullet> bullets;
double hunter0_bullet_timer;
double hunter1_bullet_timer;
double hunter2_bullet_timer;
double hunter3_bullet_timer;

/**
 * New bullet design
*/
void new_bullet(vec2 start_position, vec2 velocity){
  
  
  Bullet new_bullet(vec3(start_position,0), velocity);
  bullets.push_back(new_bullet);
  
  //bullets.push_back(bullet);


}

static void error_callback(int error, const char* description)
{
  fprintf(stderr, "Error: %s\n", description);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    glfwSetWindowShouldClose(window, GLFW_TRUE);

  //Release only stop the running if you're running in the same direction
  //Allows for changing directions more smoothly
  if (key == GLFW_KEY_LEFT || key == GLFW_KEY_A){
    if(action == GLFW_PRESS){duck.run(-1);/*hunter0.run(-1);*/}
    if(action == GLFW_RELEASE){
      if(duck.get_direction() == -1){duck.stop();}
      //if(hunter0.get_direction() == -1){hunter0.stop();}

    }
  }
  if (key == GLFW_KEY_RIGHT || key == GLFW_KEY_D){
    if(action == GLFW_PRESS){duck.run(1);/*hunter0.run(1);*/}
    if(action == GLFW_RELEASE){
      if(duck.get_direction() == 1){duck.stop();}
      //if(hunter0.get_direction() == 1){hunter0.stop();}

    }
  }

  if (key == GLFW_KEY_SPACE || key == GLFW_KEY_W  || key == GLFW_KEY_UP){
    if(action == GLFW_PRESS){duck.jump();}
    if(action == GLFW_RELEASE){duck.land();}
  }
  if (key == GLFW_KEY_Z && action == GLFW_PRESS){
    
  }
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
    if(button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) 
    {
      double xpos, ypos; //FIXME need to translate to coordinate plane
      int width, height;
      vec2 velocity;

      glfwGetCursorPos(window, &xpos, &ypos);
      glfwGetFramebufferSize(window, &width, &height);
      /*
      velocity.x = -1.0 + 2.0 * xpos / width; 
      velocity.y = 1.0 - 2.0 * ypos / height;
      */
      ypos+=20;
      if(xpos<=(width/2)){
        velocity.x = -1*(1 - (xpos/(width/2)));
      }else if(xpos>(width/2)){
        velocity.x = (xpos-(width/2))/(width/2);
      }
      if(ypos<=(height/2)){
        velocity.y = (1 - (ypos/(height/2)));
      }else if(ypos>(height/2)){
        velocity.y = -1*((ypos-(height/2))/(height/2));
      }
      velocity-=duck.get_position();
      velocity /= 75;
      new_bullet(vec2(duck.get_current_vertices()[0].x+velocity.x*10,duck.get_current_vertices()[0].y+velocity.y*10 - 0.06), velocity);
    }
}

void init(){
  glClearColor(0.52,0.8,0.98,0); //background color
  glHint (GL_LINE_SMOOTH_HINT, GL_NICEST);
  glHint (GL_POINT_SMOOTH_HINT, GL_NICEST);
  maps.push_back(map0);
  maps.push_back(map1);
  maps.push_back(map2);
  for (int i=0; i<3; i++){
    maps[i].gl_init();
  }
  duck.gl_init(); //FIXME causes crashes
  hunter0.gl_init();
  hunter1.gl_init();
  hunter2.gl_init();
  hunter3.gl_init();
  hunters_alive_pointers.push_back(hunter0.get_alive_pointer());
  hunters_alive_pointers.push_back(hunter1.get_alive_pointer());
  hunters_alive_pointers.push_back(hunter2.get_alive_pointer());
  hunters_alive_pointers.push_back(hunter3.get_alive_pointer());


  
  }

//Refreshes ~60 times a second
void animate(){
  if(glfwGetTime() > 0.016){
    hunter0_bullet_timer+=glfwGetTime();
    hunter1_bullet_timer+=glfwGetTime();
    hunter2_bullet_timer+=glfwGetTime();
    hunter3_bullet_timer+=glfwGetTime();


    glfwSetTime(0.0);
    current_map = duck.get_current_map();
    //Place hunters based on current map
    if(current_map == 0){
      if(!hunter0.placed_check(0)){
        hunter0.set_position(vec2(0.5,-0.75),0);
      }
      if(!hunter1.placed_check(0)){
        hunter1.set_position(vec2(0.3,0),0);
      }
      if(!hunter2.placed_check(0)){
        hunter2.set_position(vec2(-1.3,-0.74),0);
      }
      if(!hunter3.placed_check(0)){
        hunter3.set_position(vec2(-1.3,-0.39),0);
      }
    }else if(current_map == 1){
      if(unplaced23){
        hunter2.set_position(vec2(0.6,0.5),0);
        hunter3.set_position(vec2(0.8,-0.39),0);
        unplaced23 = false;
      }

    }


    duck.update_state(maps[current_map]);
    hunter0.update_state(maps[current_map]);
    hunter1.update_state(maps[current_map]);
    hunter2.update_state(maps[current_map]);
    hunter3.update_state(maps[current_map]);
    hunters_hitboxes.clear();
    hunters_hitboxes.push_back(hunter0.get_current_vertices());
    hunters_hitboxes.push_back(hunter1.get_current_vertices());
    hunters_hitboxes.push_back(hunter2.get_current_vertices());
    hunters_hitboxes.push_back(hunter3.get_current_vertices());

    for(int i=0;i<bullets.size();i++){
      if(!bullets[i].init_check()){
        bullets[i].gl_init();
      }
      if(!bullets[i].dead_check()){
        bullets[i].update_state(maps[current_map], duck.get_hitbox(), duck.get_alive_pointer(), hunters_hitboxes, hunters_alive_pointers);
      }else{
        bullets.erase(bullets.begin()+i);

      }
    }
  }
  
  if (hunter0_bullet_timer >= 3 && *hunter0.get_alive_pointer()){ //Hunter 0

    vec2 velocity = duck.get_position() - hunter0.get_position();
    velocity.y += 0.03;
    normalize(velocity);
    velocity/=100;

    new_bullet(hunter0.get_position()+velocity*10,velocity);
    hunter0_bullet_timer = 0;
  }
  if (hunter1_bullet_timer >= 2 && *hunter1.get_alive_pointer()){ //Hunter 1

    vec2 velocity = duck.get_position() - hunter1.get_position();
    velocity.y += 0.03;
    normalize(velocity);
    velocity/=100;

    new_bullet(hunter1.get_position()+velocity*11,velocity);
    hunter1_bullet_timer = 0;
  }
  if (hunter2_bullet_timer >= 1 && *hunter2.get_alive_pointer()){ //Hunter 2

    vec2 velocity = duck.get_position() - hunter2.get_position();
    velocity.y += 0.03;
    normalize(velocity);
    velocity/=100;
    if(!unplaced23){
      new_bullet(hunter2.get_position()+velocity*11,velocity);
    }
    hunter2_bullet_timer = 0;
  }
  if (hunter3_bullet_timer >= 0.75 && *hunter3.get_alive_pointer()){ //Hunter 3

    vec2 velocity = duck.get_position() - hunter3.get_position();
    velocity.y += 0.03;
    normalize(velocity);
    velocity/=100;
    if(!unplaced23){
      new_bullet(hunter3.get_position()+velocity*11,velocity);
    }
    hunter3_bullet_timer = 0;
  }
  
}

int main(void)
{
  GLFWwindow* window;
  
  glfwSetErrorCallback(error_callback);
  
  if (!glfwInit())
    exit(EXIT_FAILURE);
  
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  
  glfwWindowHint(GLFW_SAMPLES, 4);
  
  
  window = glfwCreateWindow(720, 720, "Duck! Duck!", NULL, NULL);
  if (!window){
    glfwTerminate();
    exit(EXIT_FAILURE);
  }
  
  glfwSetKeyCallback(window, key_callback);
  glfwSetMouseButtonCallback(window,mouse_button_callback);
  
  glfwMakeContextCurrent(window);
  gladLoadGL(glfwGetProcAddress); //CHECKME
  glfwSwapInterval(1);
  
  init();
  
  while (!glfwWindowShouldClose(window)){
    glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);
    
//    //Pick a coordinate system that makes the most sense to you
//    //(left, right, top, bottom)
    mat4 proj = Ortho2D(-1.0, 1.0, -1.0, 1.0);
    
    animate();
    
    
    glClear(GL_COLOR_BUFFER_BIT);
    
    duck.draw(proj);
    maps[current_map].draw(proj);
    hunter0.draw(proj);
    hunter1.draw(proj);
    hunter2.draw(proj);
    hunter3.draw(proj);

    for(int i=0; i<bullets.size();i++){
      bullets[i].gl_init();
      bullets[i].draw(proj);
    }

    glfwSwapBuffers(window);
    glfwPollEvents();
    
  }
  
  glfwDestroyWindow(window);
  
  glfwTerminate();
  exit(EXIT_SUCCESS);
}