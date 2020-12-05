#version 150

uniform vec4 AmbientProduct;
uniform vec4 DiffuseProduct;
uniform vec4 SpecularProduct;
uniform vec4 Light;
uniform float Shininess;

in vec4 pos;
in vec4 N;
in  vec4 color;

out vec4 fragColor;

void
main()
{
  //L
  vec4 L = normalize(Light-pos);

  //V
  vec4 V = normalize(vec4(0.0,0.0,0.0,1.0)-pos);

  //R
  vec4 R = normalize(reflect(-L,N));

  // Ambient
  vec4 ambient = AmbientProduct;
  
  // Diffuse
  float D  = max(dot(L, N), 0.0);
  vec4  diffuse = D * DiffuseProduct;
  
  //Specular
  float S = pow(max(dot(V, R), 0.0), Shininess);

  vec4 specular = S * SpecularProduct;
  
  //fragColor = color * (ambient + diffuse + specular);
  fragColor = color;

}