#type vertex
#version 330 core

    layout(location=0)in vec3 aPos;
    layout(location=1)in vec3 aTestPos;

    uniform float _FunnyFloat;
    out float oFunnyFloat;

    void main()
    {
        oFunnyFloat = _FunnyFloat;
        gl_Position=vec4(aPos.x, aPos.y, aPos.z, 1);
    }

#type fragment
#version 330 core

    out vec4 FragColor;

    in float oFunnyFloat;

    void main()
    {
        vec4 col = vec4(-1.0f, 1.0f, 1.0f, 1.0f) * oFunnyFloat;
        FragColor = col;
    }