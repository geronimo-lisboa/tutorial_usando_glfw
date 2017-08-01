#version 400
in vec3 textureCoords;
 
out vec4 frag_color;

uniform sampler3D myTextureSampler;

void main() {
  frag_color = texture( myTextureSampler, textureCoords ); 
}