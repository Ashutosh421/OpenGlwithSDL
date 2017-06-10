#version 410 core

in vec4 FragColor;
in vec2 textUV;

out vec4 color;

uniform sampler2D mainTexture;

void main(){
    color = texture(mainTexture , textUV);
   // color = FragColor;
}
