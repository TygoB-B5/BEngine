#type vertex
#version 330 core

    layout(location = 0) in vec3 aPosition;

    uniform mat4 uViewProjection;

    out float amogus;
    void main()
    {
    amogus = uViewProjection[0][0];
        gl_Position = vec4(aPosition.x + amogus, aPosition.y, aPosition.z, 1);
    }

#type fragment
#version 330 core

    out vec4 FragColor;
    in float amogus;
    void main()
    {
        FragColor = vec4(1.0f * amogus, cos(amogus) * 0.5f, 1.0f * -amogus, 0.5f);
    }