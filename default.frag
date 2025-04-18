#version 330 core
out vec4 FragColor;

// Input the color from vertex shader
in vec3 color;
// Input the texture coordinates from vertex shader
in vec2 texCoord;
// Gets the texture unit from the main function
uniform sampler2D tex0;

void main()
{
	FragColor = texture(tex0, texCoord);
};