#ifndef VBO_CLASS_H
#define VBO_CLASS_H

#include<glm/glm.hpp>
#include<glad/glad.h>
#include<vector>

// Structure to standarize the vertices used in the meshes
struct Vertex
{
	// Position
	glm::vec3 position;
	// Color
	glm::vec3 color;
	// Normals
	glm::vec3 normal;
	// Texture coordinates
	glm::vec2 texUV;
};

class VBO
{
public:
	// Reference ID of the Vertex Buffer Object
	GLuint ID;
	// Contructor that generates a Vertex Buffer Object and links it to vertices	
	VBO(std::vector<Vertex>& vertices);

	// Binds the VBO
	void Bind();
	// Unbinds the VBO
	void Unbind();
	// Deletes the VBO
	void Delete();
};

#endif