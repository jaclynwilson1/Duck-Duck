//Duck! Duck!
#include "common.h"

Map::Map(){
    //Top face
    map_vert.push_back(vec4(-0.5,0,0.5,1));
    map_vert.push_back(vec4(-0.5,0,-0.5,1));
    map_vert.push_back(vec4(0.5,0,0.5,1));

    map_vert.push_back(vec4(-0.5,0,-0.5,1));
    map_vert.push_back(vec4(0.5,0,-0.5,1));
    map_vert.push_back(vec4(0.5,0,0.5,1));
    //Bottom face
    




};

void Map::gl_init(){
    
}