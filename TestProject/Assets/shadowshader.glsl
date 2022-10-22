#type vertex
#version 330 core

    layout(location = 0) in vec3 aPosition;
    layout(location = 1) in vec3 aNormal;
    layout(location = 2) in vec2 aTexCoord;

    uniform mat4 uLightViewProjectionMatrix;
    uniform mat4 uModelMatrix;

    void main()
    {
        gl_Position = uLightViewProjectionMatrix * uModelMatrix * vec4(aPosition.x, aPosition.y, aPosition.z, 1);
    }

#type fragment
#version 330 core

    void main()
    {
    }