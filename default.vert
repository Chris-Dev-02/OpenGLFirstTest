#version 330 core

// Positions/Coordinates
layout (location = 0) in vec3 aPos;
// Normals (not necessarily normalized)
layout (location = 1) in vec3 aNormal;
// Colors
layout (location = 2) in vec3 aColor;
// Texture coordinates
layout (location = 3) in vec2 aTex;


// Outputs the current position for the fragment shader
out vec3 crntPos;
// Outputs the normal for the fragment shader
out vec3 Normal;
// Output the color for the fragment shader 
out vec3 color;
// Outputs the texture coordinates for the fragment shader
out vec2 texCoord;


// Imports the camera matrix from the main function
uniform mat4 camMatrix; 
uniform mat4 model;

void main()
{
	// Calculates the current position 
	crntPos = vec3(model * vec4(aPos, 1.0f));
	// Assigns the normal from the Vertex Data to "Normal"
	Normal = aNormal;
	// Assings the color  from the vertex Data "Color"
	color = aColor;
	// Assings the texture coordinates from the vertex Data to "texCoord"
	texCoord = aTex;
	// Outputs the positions/coordinates of all vertices
	gl_Position = camMatrix * vec4(crntPos, 1.0f);
};