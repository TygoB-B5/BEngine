#type vertex
#version 330 core

    layout(location=0)in vec3 aPos;
    layout(location=1)in vec3 aTestPos;

    uniform float lol;
    out vec3 oTestPos;

    void main()
    {
        oTestPos = aTestPos;
        gl_Position=vec4(aPos.x,aPos.y,aPos.z, 1);
    }

#type fragment
#version 330 core

    out vec4 FragColor;
    in vec3 oTestPos;

    void main()
    {
        FragColor=vec4(1.0f * oTestPos.x, 0.5f  * oTestPos.y,.2f  * oTestPos.z,1.f);
    }