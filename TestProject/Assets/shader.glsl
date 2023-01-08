#type vertex
#version 330 core

    layout(location = 0) in vec3 aPosition;
    layout(location = 1) in vec3 aNormal;
    layout(location = 2) in vec2 aTexCoord;

    uniform mat4 uViewProjection;
    uniform mat4 uModelMatrix;
    uniform mat4 uLightViewProjectionMatrix;
    uniform vec3 uLightPosition;
    uniform vec3 uCameraPosition;

    out float oDiffuseIntensity;
    out vec2 oTexCoord;
    out vec4 oPositionLightSpace;
    out vec3 oCameraPosition;
    out vec3 oFragPos;
    out vec3 oLightDirection;
    out vec3 oNormal;

    void main()
    {
        oCameraPosition = uCameraPosition;
        oTexCoord = aTexCoord;
        vec3 fragPos = vec3(uModelMatrix * vec4(aPosition, 1.0));
        oFragPos = fragPos;
        oPositionLightSpace = uLightViewProjectionMatrix * vec4(fragPos, 1.0);
        oNormal = aNormal;
        oLightDirection = normalize(uLightPosition);
        oDiffuseIntensity = dot(normalize(uLightPosition), aNormal);

        gl_Position = uViewProjection * vec4(fragPos, 1.0f);
    }

#type fragment
#version 330 core

    out vec4 FragColor;

    in vec2 oTexCoord;
    in vec4 oPositionLightSpace;
    in float oDiffuseIntensity;
    in vec3 oCameraPosition;
    in vec3 oFragPos;
    in vec3 oLightDirection;
    in vec3 oNormal;

    uniform sampler2D uTexture;
    uniform sampler2D uShadowMap;

    void main()
    {

        vec3 projCoords = oPositionLightSpace.xyz / oPositionLightSpace.w;
        projCoords = projCoords * 0.5 + 0.5; 

        float closestDepth = texture(uShadowMap, projCoords.xy).r;   

        float currentDepth = projCoords.z;  

        float bias = -0.0005;

        float shadow = (currentDepth - bias) > closestDepth ? 1.0 : 0.0;  



        vec3 viewDir = normalize(oCameraPosition - oFragPos);
        vec3 reflectDir = reflect(-oLightDirection, oNormal);  
        float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);


        float specular = spec;  

        float diffuse = oDiffuseIntensity;
        float ambient = 0.1f;
        float intensity = clamp( ((1 - shadow) + 0.1f) + clamp(diffuse, 0, 1), 0, 1) + specular * 2;

        vec4 col = texture(uTexture, oTexCoord);
        col.rgb *= intensity;
        FragColor = col;
    }