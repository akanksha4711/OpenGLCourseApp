// OpenGLCourseApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file



#include <stdio.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

// Window Dimensions
// dimensions the window is going to take up on the screen
const GLint WIDTH = 800, HEIGHT = 600;

int main() {
	// Initialise GLFW

	if (!glfwInit()) // incase there is an error while initialising GLFW
	{
		printf("GLFW initialisation failed");
		glfwTerminate();
		// Standard value to return in case the program crashed
		return 1;
	}

	// Setup GLFW window properties
	
	// OpenGL version set to 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // if 2 instead of 3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); // and 1 instead of 3 here
												   // then OpenGl version would be 2.1
	// PS - Modern OpenGL is version 3.2 and above
	// Core profile = No Backwords Compatibility
	// which means we don't want to use deprecated features/code (of OpenGL)
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	// Allow forward Compatibility
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	// A pointer to GLFW window
	GLFWwindow* mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "Test Window", NULL, NULL);
	if (!mainWindow)
	{
		printf("GLFW window creation failed!");
		// same as before when GLFW initialisation failed
		glfwTerminate();
		return 1;
	}
	
	// Get Buffer size information
	// biffer - the actual area in the window where we can draw
	int bufferWidth, bufferHeight;
	glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

	// Set context for GLEW to use
	// let GLEW know that this window is where everything needs to be drawn
	glfwMakeContextCurrent(mainWindow);


	// Initialise GLEW

	// Allow modern extension features
	// good practice
	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK) // incase there is an error while initialising GLEW
	{
		printf("GLEW initialisation failed");
		// Need to first destroy the window we created above
		glfwDestroyWindow(mainWindow);
		// same as above
		glfwTerminate();
		return 1;
	}

	// Setup Viewport size - OpenGL function
	// which we can access thanks to GLEW
	// glViewport sets up the size of the part of the window we are drawing to
	glViewport(0, 0, bufferWidth, bufferHeight); // we have selected the entire window

	// loop until window closed
	// for eg until we click close button
	while (!glfwWindowShouldClose(mainWindow))
	{
		// Get + Handle user input events
		glfwPollEvents();

		// Clear window
		// setting the color and opacity of the window after clearing
		glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
		// there can be multiple kinds of information that a
		// screen pixel carries like color/depth/stencil etc
		// we have to specify what we need to clear in the window
		glClear(GL_COLOR_BUFFER_BIT); // in this case we are just
									  // clearing the color buffer
		
		// OpenGL works by having 2 buffers, one the user can see
		// and one that we are drawing to which the user cant see
		// Then we call SwapBuffers which then swaps them around
		// and we draw on the other one and the user sees the one
		// we drew on. Sometimes there can be 3 buffer.
		glfwSwapBuffers(mainWindow);
	}


	return 0;
}