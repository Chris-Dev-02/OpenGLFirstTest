#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<stb/stb_image.h>

#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>

#include"shaderClass.h"
#include"VAO.h"
#include"VAO.h"
#include"EBO.h"
#include"Texture.h"
#include"Camera.h"

const unsigned int width = 800;
const unsigned int height = 800;

// Vertice coordinates
//GLfloat vertices[] =
//{   //     COORDINATES     /        COLORS       /   TexCoord  /        NORMALS       //
//	-0.5f, 0.0f,  0.5f,    0.83f, 0.70f, 0.44f,   0.0f, 0.0f,   0.0f, -1.0f,  0.0f, // Bottom side
//	-0.5f, 0.0f, -0.5f,    0.83f, 0.70f, 0.44f,   0.0f, 5.0f,   0.0f, -1.0f,  0.0f, // Bottom side
//	 0.5f, 0.0f, -0.5f,    0.83f, 0.70f, 0.44f,   5.0f, 5.0f,   0.0f, -1.0f,  0.0f, // Bottom side
//	 0.5f, 0.0f,  0.5f,    0.83f, 0.70f, 0.44f,   5.0f, 0.0f,   0.0f, -1.0f,  0.0f, // Bottom side
//
//	-0.5f, 0.0f, -0.5f,    0.83f, 0.70f, 0.44f,   0.0f, 0.0f,  -0.8f,  0.5f,  0.0f, // Left Side
//	-0.5f, 0.0f,  0.5f,    0.83f, 0.70f, 0.44f,   5.0f, 0.0f,  -0.8f,  0.5f,  0.0f, // Left Side
//	 0.0f, 0.8f,  0.0f,    0.92f, 0.86f, 0.76f,   2.5f, 5.0f,  -0.8f,  0.5f,  0.0f, // Left Side
//
//	-0.5f, 0.0f, -0.5f,    0.83f, 0.70f, 0.44f,   5.0f, 0.0f,   0.0f,  0.5f, -0.8f, // Non-facing side
//	 0.5f, 0.0f, -0.5f,    0.83f, 0.70f, 0.44f,   0.0f, 0.0f,   0.0f,  0.5f, -0.8f, // Non-facing side
//	 0.0f, 0.8f,  0.0f,    0.92f, 0.86f, 0.76f,   2.5f, 5.0f,   0.0f,  0.5f, -0.8f, // Non-facing side
//
//	 0.5f, 0.0f, -0.5f,    0.83f, 0.70f, 0.44f,   0.0f, 0.0f,   0.8f,  0.5f,  0.0f, // Right side
//	 0.5f, 0.0f,  0.5f,    0.83f, 0.70f, 0.44f,   5.0f, 0.0f,   0.8f,  0.5f,  0.0f, // Right side
//	 0.0f, 0.8f,  0.0f,    0.92f, 0.86f, 0.76f,   2.5f, 5.0f,   0.8f,  0.5f,  0.0f, // Right side
//
//	 0.5f, 0.0f,  0.5f,    0.83f, 0.70f, 0.44f,   5.0f, 0.0f,   0.0f,  0.5f,  0.8f, // Facing side
//	-0.5f, 0.0f,  0.5f,    0.83f, 0.70f, 0.44f,   0.0f, 0.0f,   0.0f,  0.5f,  0.8f, // Facing side
//	 0.0f, 0.8f,  0.0f,    0.92f, 0.86f, 0.76f,   2.5f, 5.0f,   0.0f,  0.5f,  0.8f  // Facing side
//};
//
//GLuint indices[] = {
//	0, 1, 2,	// Botton side
//	0, 2, 3,	// Botton side
//	4, 6, 5,	// Left side
//	7, 9, 8,	// Non-facing side
//	10, 11, 12,	// Right side
//	13, 15, 14,	// Facing side
//};

// Vertices coordinates
GLfloat vertices[] =
{ //     COORDINATES     /        COLORS        /    TexCoord    /       NORMALS     //
	-1.0f, 0.0f,  1.0f,		0.0f, 0.0f, 0.0f,		0.0f, 0.0f,		0.0f, 1.0f, 0.0f,
	-1.0f, 0.0f, -1.0f,		0.0f, 0.0f, 0.0f,		0.0f, 1.0f,		0.0f, 1.0f, 0.0f,
	 1.0f, 0.0f, -1.0f,		0.0f, 0.0f, 0.0f,		1.0f, 1.0f,		0.0f, 1.0f, 0.0f,
	 1.0f, 0.0f,  1.0f,		0.0f, 0.0f, 0.0f,		1.0f, 0.0f,		0.0f, 1.0f, 0.0f
};

// Indices for vertices order
GLuint indices[] =
{
	0, 1, 2,
	0, 2, 3
};

GLfloat lightVertices[] =
{ //     COORDINATES     //
	-0.1f, -0.1f,  0.1f,
	-0.1f, -0.1f, -0.1f,
	 0.1f, -0.1f, -0.1f,
	 0.1f, -0.1f,  0.1f,
	-0.1f,  0.1f,  0.1f,
	-0.1f,  0.1f, -0.1f,
	 0.1f,  0.1f, -0.1f,
	 0.1f,  0.1f,  0.1f
};

GLuint lightIndices[] =
{
	0, 1, 2,
	0, 2, 3,
	0, 4, 7,
	0, 7, 3,
	3, 7, 6,
	3, 6, 2,
	2, 6, 5,
	2, 5, 1,
	1, 5, 4,
	1, 4, 0,
	4, 5, 6,
	4, 6, 7
};

int main() {

	// Initialize GLFW
	glfwInit();

	// Tell GLFW what version of OpenGL is in use
	// In this case OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	// Tell GLFW the CORE Profile is been used
	// So this means only modern function are been used
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create a GLFWwindow object of 800 by 800 pixels, naming it "OpenGL_FirstTest"
	GLFWwindow* window = glfwCreateWindow(width, height, "OpenGL_FirstTest", NULL, NULL);
	// Error check if the window fails to create
	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	// Introduce the window into the current context
	glfwMakeContextCurrent(window);
	// Load GLAD so it configures OpenGL
	gladLoadGL();

	// Specify the viewport of OpenGL in the Window
	// In this case the viewport goes from x = 0, y = 0, to x = 800, y = 800
	glViewport(0, 0, width, height);

	// Create Shader object using shaders default.vert and default.frag
	Shader shaderProgram("default.vert", "default.frag");

	// Generates vertex array object and binds it
	VAO VAO1;
	VAO1.Bind();

	// Generate vertex buffer object and links it to vertices
	VBO VBO1(vertices, sizeof(vertices));
	// Generate element buffer object and links it to indices
	EBO EBO1(indices, sizeof(indices));

	// Links VBO attributes such as coordinates and colors to VAO
	VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 11 * sizeof(float), (void*)0);
	VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 11 * sizeof(float), (void*)(3 * sizeof(float)));
	VAO1.LinkAttrib(VBO1, 2, 2, GL_FLOAT, 11 * sizeof(float), (void*)(6 * sizeof(float)));
	VAO1.LinkAttrib(VBO1, 3, 3, GL_FLOAT, 11 * sizeof(float), (void*)(8 * sizeof(float)));
	// Unbind all to prevent accidentally modifying
	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();

	// Shader for the light cube 
	Shader lightShader("light.vert", "light.frag");
	VAO lightVAO;
	lightVAO.Bind();

	// Generate vertex buffer object and links it to vertices
	VBO lightVBO(lightVertices, sizeof(lightVertices));
	// Generate element buffer object and links it to indices
	EBO lightEBO(lightIndices, sizeof(lightIndices));

	// Links VBO attributes such as coordinates and colors to VAO
	lightVAO.LinkAttrib(lightVBO, 0, 3, GL_FLOAT, 3 * sizeof(float), (void*)0);

	// Unbind all to prevent accidentally modifying them
	lightVAO.Unbind();
	lightVBO.Unbind();
	lightEBO.Unbind();

	glm::vec4 lightColor = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);

	glm::vec3 lightPos = glm::vec3(0.5f, 0.5f, 0.5f);
	glm::mat4 lightModel = glm::mat4(1.0f);
	lightModel = glm::translate(lightModel, lightPos);

	glm::vec3 pyramidPos = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::mat4 pyramidModel = glm::mat4(1.0f);
	pyramidModel = glm::translate(pyramidModel, pyramidPos);

	lightShader.Activate();
	glUniformMatrix4fv(glGetUniformLocation(lightShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(lightModel));
	glUniform4f(glGetUniformLocation(lightShader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	shaderProgram.Activate();
	glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "model"), 1, GL_FALSE, glm::value_ptr(pyramidModel));
	glUniform4f(glGetUniformLocation(shaderProgram.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	glUniform3f(glGetUniformLocation(shaderProgram.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);

	// Textures
	Texture woodTex("Wood_Planks_014_basecolor_512.png", GL_TEXTURE_2D, 0, GL_RGBA, GL_UNSIGNED_BYTE);
	//Texture woodTex("pop_cat_.jpg", GL_TEXTURE_2D, 0, GL_RGB, GL_UNSIGNED_BYTE);
	woodTex.texUnit(shaderProgram, "tex0", 0);
	Texture woodSpec("Wood_Planks_014_specular_512.png", GL_TEXTURE_2D, 1, GL_RGBA, GL_UNSIGNED_BYTE);
	woodSpec.texUnit(shaderProgram, "tex1", 1);

	glEnable(GL_DEPTH_TEST); // Enable depth buffer

	// Creates Camera object
	Camera camera(width, height, glm::vec3(0.0f, 0.0f, 2.0f));

	// Main while loop
	while (!glfwWindowShouldClose(window)) {
		// Specify the color of the background
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		// Clean the back buffer and depth buffer and assigns the new color to it
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Handles camera inputs
		camera.Inputs(window); // Take care of camera inputs
		// Updates and exports the camera matrix to the Vertex Shader
		camera.updateMatrix(45.0f, 0.1f, 100.0f);

		// Tell OpenGL which shader program we want to use
		shaderProgram.Activate();
		// Exports the camera Position to the Fragment Shader for the specular lighting
		glUniform3f(glGetUniformLocation(shaderProgram.ID, "camPos"), camera.Position.x, camera.Position.y, camera.Position.z);
		// Exports the camMatrix to the Vertex Shader of the pyramid
		camera.Matrix(shaderProgram, "camMatrix");

		// Bind the texture so that appears in rendering 
		woodTex.Bind();
		woodSpec.Bind();
		// Bind the VAO so OpenGL knows to use it 
		VAO1.Bind();
		// Drawn the triangule using the GL_TRIANGLES primitive
		//glDrawArrays(GL_TRIANGLES, 0, 3);
		glDrawElements(GL_TRIANGLES, sizeof(indices)/sizeof(int), GL_UNSIGNED_INT, 0);

		// Tells OpenGL to use the light shader program we want to use
		lightShader.Activate();
		// Exports the camera Position to the Vertex Shader of the light cube
		camera.Matrix(lightShader, "camMatrix");
		// Bind the VAO so OpenGL knows to use it
		lightVAO.Bind();
		// Draw primitives , number of indices, datatype of indices, index of indices
		glDrawElements(GL_TRIANGLES, sizeof(lightIndices) / sizeof(int), GL_UNSIGNED_INT, 0);

		// Swap to the back buffer with the front buffer
		glfwSwapBuffers(window);
		// Take care of all GLFW events
		glfwPollEvents();
	}

	// Delete all the objects we've created
	VAO1.Delete();
	VBO1.Delete();
	EBO1.Delete();
	woodTex.Delete();
	woodSpec.Delete();
	shaderProgram.Delete();

	lightVAO.Delete();
	lightVBO.Delete();
	lightEBO.Delete();
	lightShader.Delete();

	// Delete window before ending the program
	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}

