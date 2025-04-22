#include"Camera.h"

Camera::Camera(int width, int height, glm::vec3 position)
{
	Camera::width = width; // Accessing the class variable
	this->height = height; // Accessing the class variable
	Position = position;
}

void Camera::updateMatrix(float FOVdeg, float nearPlane, float farPlane)
{
	// Initializes matrices since otherwise they will be the null matrix
	glm::mat4 view = glm::mat4(1.0f); // Identity matrix
	glm::mat4 projection = glm::mat4(1.0f); // Identity matrix

	// Makes camera look in the right direction from the right position
	view = glm::lookAt(Position, Position + Orientation, Up); // View matrix
	// Adds perspective to the scene
	projection = glm::perspective(glm::radians(FOVdeg), (float)(width / height), nearPlane, farPlane); // Projection matrix

	// Sets new camera matrix	
	cameraMatrix = projection * view; // Camera matrix
}

void Camera::Matrix(Shader& shader, const char* uniform) 
{
	// Exports the camera matrix to the vertex shader 
	glUniformMatrix4fv(glGetUniformLocation(shader.ID, uniform), 1, GL_FALSE, glm::value_ptr(cameraMatrix)); // Outputs the matrix into the shader
}

void Camera::Inputs(GLFWwindow* window)
{
	// Handles key inputs
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
		Position += speed * Orientation;
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
		Position += speed * -Orientation;
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
		Position += speed * -glm::normalize(glm::cross(Orientation, Up));
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
		Position += speed * glm::normalize(glm::cross(Orientation, Up));
	}
	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
		Position += speed * Up;
	}
	if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS) {
		Position += speed * -Up;
	}
	if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) {
		speed = 0.04f;
	}
	else if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_RELEASE) {
		speed = 0.01f;
	}

	// Handles mouse inputs
	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN); // Hides the cursor

		// Prevents camera from jumping on the first click
		if (firstClick) {
			glfwSetCursorPos(window, (width / 2), (height / 2)); // Set the cursor position to the center of the window
			firstClick = false; // Set firstClick to false
		}

		// Stores the coordinates of the cursor
		double mouseX, mouseY;
		// Fetches the coordinates of the cursor
		glfwGetCursorPos(window, &mouseX, &mouseY); // Get the current mouse position

		// Normalizes and shifts the coordinates of the cursor such that they being in the middle of the screen 
		// And then "transforms" them into degrees 
		float rotX = sensitivity * (float)(mouseY - (height / 2)) / height;
		float rotY = sensitivity * (float)(mouseX - (height / 2)) / height;

		// Calculates upcoming vertical change in the orientation
		glm::vec3 newOrientation = glm::rotate(Orientation, glm::radians(rotX), glm::normalize(glm::cross(Orientation, Up))); // Rotate the camera around the X axis

		// Decides whether or not the next vertical orientation is legal or not
		if (!(glm::angle(newOrientation, Up) <= glm::radians(5.0f)) || glm::angle(newOrientation, -Up) <= glm::radians(5.0f)) {
			Orientation = newOrientation; // Update the camera orientation
		}

		// Rotates the orientation left and right 
		Orientation = glm::rotate(Orientation, glm::radians(rotY), Up); // Rotate the camera around the Y axis

		// Sets mouse cursor to the middle of the screen so that it doesn't move end up roaming around
		glfwSetCursorPos(window, (width / 2), (height / 2)); // Set the cursor position to the center of the window
	}	
	else if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE) {
		// Unhides cursor since camera is not looking around anymore
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL); // Hides the cursor
		// Makes sure the next time the camera looks around it doesn't jump
		firstClick = true; // Set firstClick to true
	}
}