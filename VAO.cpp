#include"VAO.h"

// Constructor that generates a VAO Id
VAO::VAO()
{
	glGenVertexArrays(1, &ID);
}

// Links a VBO to VAO using certain layout
void VAO::LinkAttrib(VBO& VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset)
{
	VBO.Bind();

	// Configure the vetex attrubute so that  OpenGL knows how to read the VBO
	glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride, offset);
	// Enable the vertex attribute so that OpenGL knows to use it
	glEnableVertexAttribArray(layout);

	VBO.Unbind();
}

// Binds the VAO
void VAO::Bind()
{
	// Make the VAO the current Vertex array object by binding it
	glBindVertexArray(ID);
}

// Unbinds the VAO
void VAO::Unbind()
{
	glBindVertexArray(0);
}

// Deletes the VAO
void VAO::Delete()
{
	glDeleteVertexArrays(1, &ID);
}