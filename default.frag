#version 330 core
out vec4 FragColor;

// Imports the color from vertex shader
in vec3 color;
// Imports the texture coordinates from vertex shader
in vec2 texCoord;
// Imports the normal from the vertex shader
in vec3 Normal;
// Imports the current position from the vertex shader
in vec3 crntPos;

// Gets the texture unit from the main function
uniform sampler2D tex0;
// Gets the light color from the main function
uniform vec4 lightColor;
// Gets the light position from the main function
uniform vec3 lightPos;
// Gets the camera position from the main function
uniform vec3 camPos;

void main()
{
	// Ambient lighting
	float ambient = 0.20f;

	// Diffuse lighting
	vec3 normal = normalize(Normal);
	vec3 lightDirection = normalize(lightPos - crntPos);
	float diffuse = max(dot(normal, lightDirection), 0.0f);

	// Specular lighting
	float specularLight = 0.50f;
	vec3 viewDirection = normalize(camPos - crntPos);
	vec3 reflectDirection = reflect(-lightDirection, normal);
	float specAmount = pow(max(dot(viewDirection, reflectDirection), 0.0f), 8);
	float specular = specularLight * specAmount;

	// Outputs final color
	FragColor = texture(tex0, texCoord) * lightColor * (diffuse + ambient + specular);
};