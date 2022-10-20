#type vertex
#version 330 core

    layout(location = 0) in vec3 aPosition;
    layout(location = 1) in vec3 aNormal;

    uniform mat4 uViewProjection;
    out float intensity;

    void main()
    {
        vec3 dirLight = clamp(normalize(-vec3(-0.5f, -1.0f, -0.2f)) + 0.25f, 0, 1);
        intensity = dot(dirLight, aNormal);
        gl_Position = uViewProjection * vec4(aPosition.x, aPosition.y, aPosition.z, 1);
    }

#type fragment
#version 330 core

    out vec4 FragColor;
    in float intensity;

    void main()
    {
        FragColor = vec4(0.5f  * intensity, 1.0f  * intensity, 0.75f  * intensity, 1.0f);
    }