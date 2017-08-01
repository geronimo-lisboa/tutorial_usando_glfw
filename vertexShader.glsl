#version 400
layout(location = 0) in vec3 vp;
layout(location = 2) in vec3 uv;

out vec3 textureCoords;

void main() {
  gl_Position = vec4(vp, 1.0);
  textureCoords = uv;
}