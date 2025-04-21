#include"Texture.h"

Texture::Texture(const char* image, GLenum texType, GLenum slot, GLenum format, GLenum pixelType)
{
	// Assings the type	of the texture to the texture object
	type = texType;

	// Stores the witdh, height, and number of color channels of the image
	int widthImg, heightImg, numColCh;
	
	stbi_set_flip_vertically_on_load(true); // Flips the image, so it appear right side up
	// Reads a image from a file and stores the pixel data in bytes
	unsigned char* bytes = stbi_load(image, &widthImg, &heightImg, &numColCh, 0);
	if (bytes == nullptr) {
		std::cout << "Error loading the image: " << stbi_failure_reason() << std::endl;
	}
	// Generates an OpenGL texture object
	glGenTextures(1, &ID);
	// Assigns the texture object to the texture unit
	glActiveTexture(slot);
	glBindTexture(texType, ID);

	// Configures the type of algorithm that is used to minimize and maximize the texture
	glTexParameteri(texType, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(texType, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	// Configure the way the texture is repeated (if it does at all)
	glTexParameteri(texType, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(texType, GL_TEXTURE_WRAP_T, GL_REPEAT);

	// Extra lines in case we choose to use CLAMP_TO_BORDER
	// float flatcolor[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	// glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, flatcolor);

	// Assigns the image to the OpenGL texture object
	glTexImage2D(texType, 0, GL_RGB, widthImg, heightImg, 0, format, pixelType, bytes);
	// Generates the mipmap of the texture
	glGenerateMipmap(texType);

	// Deletes the image data as it is already stored in the texture object
	stbi_image_free(bytes);
	// Unbinds the OpenGL texture object so that can't be modified accidentally
	glBindTexture(texType, 0);
}

void Texture::texUnit(Shader& shader, const char* uniform, GLuint unit)
{
	GLuint texUni = glGetUniformLocation(shader.ID, uniform);
	// Shader needs to be activated before changing the value of the uniform
	shader.Activate();
	glUniform1i(texUni, unit);
}

void Texture::Bind()
{
	glBindTexture(type, ID);
}

void Texture::Unbind()
{
	glBindTexture(type, 0);
}

void Texture::Delete()
{
	glDeleteTextures(1, &ID);
}
