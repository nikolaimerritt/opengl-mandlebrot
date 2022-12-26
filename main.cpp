#include <glad/glad.h>
#include <glfw3.h>
#include <iostream>

void resize_window(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

int main() {
	// Setting up GLFW
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Setting up window
	GLFWwindow* window = glfwCreateWindow(800, 600, "Hello OpenGL :)", nullptr, nullptr);
	if (window == nullptr) {
		std::cout << "Sad :(( Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	// Setting up GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Sad :(( Failed to initialise GLAD" << std::endl;
		return -1;
	}

	glViewport(0, 0, 800, 600);
	glfwSetFramebufferSizeCallback(window, resize_window);

	while (!glfwWindowShouldClose(window)) {
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}