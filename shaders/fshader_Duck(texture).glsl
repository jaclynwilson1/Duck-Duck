#version 150

in  vec4 color;
in vec4 pos;
in vec4 N;
in vec2 texCoord;

uniform sampler2D textureDuck;

out vec4 fragColor;


void main()
{

  vec4 diffuse_color = texture(textureDuck, texCoord);

  //fragColor = color;
  fragColor = diffuse_color;
  fragColor = clamp(fragColor, 0.0, 1.0);
  fragColor.a  = 1.0;
}