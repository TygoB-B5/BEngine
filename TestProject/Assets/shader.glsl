#type vertex
#version 330 core

    layout(location = 0) in vec3 aPosition;
    layout(location = 1) in vec3 aNormal;
    layout(location = 2) in vec2 aTexCoord;

    uniform mat4 uViewProjection;



    out float intensity;
    out vec2 oTexCoord;


    void main()
    {
        oTexCoord = aTexCoord;

        vec3 dirLight = clamp(normalize(-vec3(-0.5f, -1.0f, -0.2f)) + 0.25f, 0, 1);

        intensity = dot(dirLight, aNormal);
        gl_Position = uViewProjection * vec4(aPosition.x, aPosition.y, aPosition.z, 1);
    }

#type fragment
#version 330 core

    out vec4 FragColor;

    in float intensity;
    in vec2 oTexCoord;

    uniform sampler2D uTexture;

    void main()
    {
        FragColor = texture(uTexture, oTexCoord);
    }