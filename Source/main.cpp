//Duck! Duck!
//main.cpp

#include "common.h"

using namespace Angel;

Duck duck;
Map map;

std::vector<std::vector<vec3>> hunters_hitboxes;
Hunter hunter1;
Hunter hunter2;



Bullet bullet(vec3(0,0.2,0), vec3(0.001,0,0));


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

void init(){
  glClearColor(0.52,0.8,0.98,0); //background color
  glHint (GL_LINE_SMOOTH_HINT, GL_NICEST);
  glHint (GL_POINT_SMOOTH_HINT, GL_NICEST);
  duck.gl_init(); //FIXME causes crashes
  map.gl_init();
  hunter1.gl_init();
  bullet.gl_init();
}

//Refreshes ~60 times a second
void animate(){
  if(glfwGetTime() > 0.016){
    glfwSetTime(0.0);
    duck.update_state(map);
    hunter1.update_state(map);
    hunters_hitboxes.clear();
    hunters_hitboxes.push_back(hunter1.get_hitbox());
    hunters_hitboxes.push_back(hunter2.get_hitbox());
    bullet.update_state(map, duck.get_current_vertices(), hunters_hitboxes);
    

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
    bullet.draw(proj);
    
    glfwSwapBuffers(window);
    glfwPollEvents();
    
  }
  
  glfwDestroyWindow(window);
  
  glfwTerminate();
  exit(EXIT_SUCCESS);
}