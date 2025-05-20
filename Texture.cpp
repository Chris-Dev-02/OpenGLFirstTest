#include"Texture.h"

Texture::Texture(const char* image, const char* texType, GLenum slot)
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
	glActiveTexture(GL_TEXTURE0 + slot);
	unit = slot; // Assigns the texture unit to the texture object
	glBindTexture(GL_TEXTURE_2D, ID);

	// Configures the type of algorithm that is used to minimize and maximize the texture
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	// Configure the way the texture is repeated (if it does at all)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	// Extra lines in case we choose to use CLAMP_TO_BORDER
	// float flatcolor[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	// glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, flatcolor);

	if(numColCh == 4)
		glTexImage2D(
			GL_TEXTURE_2D, 
			0, 
			GL_RGBA, 
			widthImg, 
			heightImg, 
			0, 
			GL_RGBA, 
			GL_UNSIGNED_BYTE, 
			bytes);
	else if (numColCh == 3)
		glTexImage2D(
			GL_TEXTURE_2D,
			0,
			GL_RGBA,
			widthImg,
			heightImg,
			0,
			GL_RGB,
			GL_UNSIGNED_BYTE,
			bytes);
	else if (numColCh == 1)
		glTexImage2D(
			GL_TEXTURE_2D,
			0,
			GL_RGBA,
			widthImg,
			heightImg,
			0,
			GL_RED,
			GL_UNSIGNED_BYTE,
			bytes);
	else
		throw std::invalid_argument("Automatic Texture type recognition failed");
		//std::cout << "Texture error: number of color channels is not supported" << std::endl;

	// Generates the mipmap of the texture
	glGenerateMipmap(GL_TEXTURE_2D);

	// Deletes the image data as it is already stored in the texture object
	stbi_image_free(bytes);
	// Unbinds the OpenGL texture object so that can't be modified accidentally
	glBindTexture(GL_TEXTURE_2D, 0);
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
	glActiveTexture(GL_TEXTURE0 + unit); // Activate the texture unit
	glBindTexture(GL_TEXTURE_2D, ID);
}

void Texture::Unbind()
{
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::Delete()
{
	glDeleteTextures(1, &ID);
}
