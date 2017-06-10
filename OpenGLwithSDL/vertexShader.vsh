#version 410 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec4 color;
layout(location = 2) in vec2 uv;

out vec4 FragColor;
out vec2 textUV;

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

void main(){
    
    gl_Position = projectionMatrix * viewMatrix  * modelMatrix * vec4(position , 1.0f);
    FragColor = color;
    textUV = uv;
}
