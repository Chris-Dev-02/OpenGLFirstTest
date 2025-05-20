#include"Model.h"
#include <iostream>
#include <direct.h>
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

//Vertex vertices[] =
//{ //               COORDINATES           /            COLORS          /           NORMALS         /       TEXTURE COORDINATES    //
//	Vertex{glm::vec3(-1.0f, 0.0f,  1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f)},
//	Vertex{glm::vec3(-1.0f, 0.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f)},
//	Vertex{glm::vec3(1.0f, 0.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f)},
//	Vertex{glm::vec3(1.0f, 0.0f,  1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f)}
//};
//
//// Indices for vertices order
//GLuint indices[] =
//{
//	0, 1, 2,
//	0, 2, 3
//};
//
//Vertex lightVertices[] =
//{ //     COORDINATES     //
//	Vertex{glm::vec3(-0.1f, -0.1f,  0.1f)},
//	Vertex{glm::vec3(-0.1f, -0.1f, -0.1f)},
//	Vertex{glm::vec3(0.1f, -0.1f, -0.1f)},
//	Vertex{glm::vec3(0.1f, -0.1f,  0.1f)},
//	Vertex{glm::vec3(-0.1f,  0.1f,  0.1f)},
//	Vertex{glm::vec3(-0.1f,  0.1f, -0.1f)},
//	Vertex{glm::vec3(0.1f,  0.1f, -0.1f)},
//	Vertex{glm::vec3(0.1f,  0.1f,  0.1f)}
//};
//
//GLuint lightIndices[] =
//{
//	0, 1, 2,
//	0, 2, 3,
//	0, 4, 7,
//	0, 7, 3,
//	3, 7, 6,
//	3, 6, 2,
//	2, 6, 5,
//	2, 5, 1,
//	1, 5, 4,
//	1, 4, 0,
//	4, 5, 6,
//	4, 6, 7
//};

int main() {
	char cwd[1024];
	_getcwd(cwd, sizeof(cwd));
	std::cout << "Directorio de trabajo actual: " << cwd << std::endl;

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

	// Texture data
	//Texture textures[]
	//{
	//	// Textures
	//	Texture("Wood_Planks_014_basecolor_512.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
	//	//Texture woodTex("pop_cat_.jpg", GL_TEXTURE_2D, 0, GL_RGB, GL_UNSIGNED_BYTE);
	//	Texture("Wood_Planks_014_specular_512.png", "specular", 1, GL_RGBA, GL_UNSIGNED_BYTE)
	//};

	// Create Shader object using shaders default.vert and default.frag
	Shader shaderProgram("default.vert", "default.frag");
	//std::vector <Vertex> verts(vertices, vertices + sizeof(vertices) / sizeof(Vertex));
	//std::vector <GLuint> ind(indices, indices + sizeof(indices) / sizeof(GLuint));
	//std::vector <Texture> tex(textures, textures + sizeof(textures) / sizeof(Texture));
	//Mesh floor(verts, ind, tex);


	//// Shader for the light cube 
	//Shader lightShader("light.vert", "light.frag");
	//// Store mesh data in vectors for the mesh
	//std::vector <Vertex> lightVerts(lightVertices, lightVertices + sizeof(lightVertices) / sizeof(Vertex));
	//std::vector <GLuint> lightInd(lightIndices, lightIndices + sizeof(lightIndices) / sizeof(GLuint));
	//// Create light mesh
	//Mesh lightCube(lightVerts, lightInd, tex);

	glm::vec4 lightColor = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);

	glm::vec3 lightPos = glm::vec3(0.5f, 0.5f, 0.5f);
	glm::mat4 lightModel = glm::mat4(1.0f);
	lightModel = glm::translate(lightModel, lightPos);

	//glm::vec3 pyramidPos = glm::vec3(0.0f, 0.0f, 0.0f);
	//glm::mat4 pyramidModel = glm::mat4(1.0f);
	//pyramidModel = glm::translate(pyramidModel, pyramidPos);

	//lightShader.Activate();
	//glUniformMatrix4fv(glGetUniformLocation(lightShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(lightModel));
	//glUniform4f(glGetUniformLocation(lightShader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	shaderProgram.Activate();
	//glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "model"), 1, GL_FALSE, glm::value_ptr(pyramidModel));
	glUniform4f(glGetUniformLocation(shaderProgram.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	glUniform3f(glGetUniformLocation(shaderProgram.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);



	glEnable(GL_DEPTH_TEST); // Enable depth buffer

	// Creates Camera object
	Camera camera(width, height, glm::vec3(0.0f, 0.0f, 2.0f));

	Model model("Models/scene.gltf");

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

		model.Draw(shaderProgram, camera); // Draw the model

		//floor.Draw(shaderProgram, camera); // Draw the floor
		//lightCube.Draw(lightShader, camera); // Draw the light cube

		// Swap to the back buffer with the front buffer
		glfwSwapBuffers(window);
		// Take care of all GLFW events
		glfwPollEvents();
	}

	// Delete all the objects we've created
	shaderProgram.Delete();

	//lightShader.Delete();

	// Delete window before ending the program
	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}

