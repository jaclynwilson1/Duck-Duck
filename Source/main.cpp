//Duck! Duck!
//main.cpp

#include "common.h"

using namespace Angel;

Duck duck;
Map map{1};

std::vector<std::vector<vec3>> hunters_hitboxes;
Hunter hunter1;
Hunter hunter2;


std::vector<Bullet> bullets;
double hunter_bullet_timer;



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
    if(action == GLFW_PRESS){duck.run(-1);}
    if(action == GLFW_RELEASE){
      if(duck.get_direction() == -1){duck.stop();}
    }
  }
  if (key == GLFW_KEY_RIGHT || key == GLFW_KEY_D){
    if(action == GLFW_PRESS){duck.run(1);}
    if(action == GLFW_RELEASE){
      if(duck.get_direction() == 1){duck.stop();}
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

      velocity.x = -1.0 + 2.0 * xpos / width; 
      velocity.y = 1.0 - 2.0 * ypos / height;  

      velocity.y *= -1;
      velocity /= 100;
      new_bullet(duck.get_position(), velocity);
    }
}

void init(){
  glClearColor(0.52,0.8,0.98,0); //background color
  glHint (GL_LINE_SMOOTH_HINT, GL_NICEST);
  glHint (GL_POINT_SMOOTH_HINT, GL_NICEST);
  duck.gl_init(); //FIXME causes crashes
  map.gl_init();
  hunter1.gl_init();
}

//Refreshes ~60 times a second
void animate(){
  if(glfwGetTime() > 0.016){
    hunter_bullet_timer+=glfwGetTime();
    glfwSetTime(0.0);
    
    duck.update_state(map);
    hunter1.update_state(map);
    hunter2.update_state(map);
    hunters_hitboxes.clear();
    hunters_hitboxes.push_back(hunter1.get_current_vertices());
    hunters_hitboxes.push_back(hunter2.get_current_vertices());
    //bullet.gl_init();
    //bullet.update_state(map, duck.get_current_vertices(), hunters_hitboxes);
    for(int i=0;i<bullets.size();i++){
      if(!bullets[i].dead_check()){
        bullets[i].gl_init();
        bullets[i].update_state(map, duck.get_current_vertices(), hunters_hitboxes);
      }
    }
  }

  if (hunter_bullet_timer >= 5){
    int width, height;

    vec2 velocity = duck.get_position();
    velocity/=100;

    new_bullet(hunter1.get_position(),velocity);
    hunter_bullet_timer = 0;
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
    map.draw(proj);
    hunter1.draw(proj);
    hunter2.draw(proj);
    for(int i=0; i<bullets.size();i++){
      //bullets[i].gl_init();
      bullets[i].draw(proj);
    }

    glfwSwapBuffers(window);
    glfwPollEvents();
    
  }
  
  glfwDestroyWindow(window);
  
  glfwTerminate();
  exit(EXIT_SUCCESS);
}