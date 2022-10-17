#type vertex
#version 330 core
layout(location=0)in vec3 aPos;
uniform float lol;
void main()
{
    gl_Position=vec4(aPos.x+sin(lol),aPos.y+cos(lol),aPos.z,1.);
}

#type fragment
#version 330 core
out vec4 FragColor;
void main()
{
    FragColor=vec4(1.f,.5f,.2f,1.f);
}