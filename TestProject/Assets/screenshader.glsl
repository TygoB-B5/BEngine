#type vertex
#version 330 core

    layout(location = 0) in vec3 aPosition;
    layout(location = 1) in vec2 aTexCoord;

    out vec2 oTexCoord;

    void main()
    {
        oTexCoord = aTexCoord;
        gl_Position = vec4(aPosition.x, aPosition.y, aPosition.z, 1);
    }

#type fragment
#version 330 core

    out vec4 FragColor;
    in vec2 oTexCoord;

    uniform sampler2D uTexture;

    void main()
    {
        FragColor = texture(uTexture, oTexCoord);
    }