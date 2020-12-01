#version 460

in  vec3 vPosition;
in  vec3 vNormal;
in  vec3 vColor;

uniform mat4 ModelView;
uniform mat4 Projection;
uniform mat4 NormalMatrix;

out vec4 pos;
out vec4 N;
out vec4 color;


void main()
{
  // Send through the vertex color
  color = vec4(vColor,1);
  
  // Transform vertex normal into eye coordinates
  N = NormalMatrix*vec4(vNormal, 0.0); N.w = 0.0;
  N = normalize(N);
  
  // Transform vertex position into eye coordinates
  pos = ModelView * vec4(vPosition,1);
  gl_Position = Projection * pos;
  
}