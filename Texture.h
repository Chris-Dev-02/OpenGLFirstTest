#pragma once
#ifndef TEXTURE_CLASS_H
#define TEXTURE_CLASS_H

#include<glad/glad.h>
#include<stb/stb_image.h>

#include"shaderClass.h"

class Texture
{
public:
	GLuint ID;
	GLenum type;
	Texture(const char* image, GLenum texType, GLenum slot, GLenum format, GLenum pixelType);

	// Assings a texture unit to the texture
	void texUnit(Shader shader, const char* uniform, GLuint unit);
	// Binds the texture
	void Bind();
	// Unbinds the texture
	void Unbind();
	// Deletes the texture
	void Delete();
};

#endif
