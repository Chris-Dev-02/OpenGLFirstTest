#ifndef EBO_CLASS_H
#define EBO_CLASS_H

#include<glad/glad.h>

class EBO
{
public:
	// Reference ID of the Element Buffer Object
	GLuint ID;
	// Contructor that generates a Element Buffer Object and links it to vertices
	EBO(GLuint* vertices, GLsizeiptr size);

	// Binds the EBO
	void Bind();
	// Unbinds the EBO
	void Unbind();
	// Deletes the EBO
	void Delete();
};

#endif