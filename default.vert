#version 330 core

// Positions/Coordinates
layout (location = 0) in vec3 aPos;
// Colors
layout (location = 1) in vec3 aColor;
// Texture coordinates
layout (location = 2) in vec2 aTex;

// Output the color for the fragment shader 
out vec3 color;
// Outputs the texture coordinates for the fragment shader
out vec2 texCoord;
// Controls the scale of the vertices
uniform float scale;

void main()
{
	// Outputs the positions/coordinates of all vertices
	gl_Position = vec4(aPos.x + aPos.x * scale, aPos.y + aPos.y * scale, aPos.z + aPos.z * scale, 1.0);
	// Assings the color  from the vertex Data "Color"
	color = aColor;
	// Assings the texture coordinates from the vertex Data to "texCoord"
	texCoord = aTex;
};