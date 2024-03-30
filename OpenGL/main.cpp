#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>
#include <iostream>

int main() {
	if (!glfwInit()) {
		std::cerr << "Failed to initialize GLFW" << std::endl;
		return -1;
	}
	GLFWwindow* window = glfwCreateWindow(1260, 1260, "hi", NULL, NULL);
		if (!window) { 
			std::cerr << "Failed to create GLFW window" << std::endl; 
			glfwTerminate(); 
			return -1;
		}
	glfwMakeContextCurrent(window);
	if (glewInit() != GLEW_OK) {
		std::cerr << "Failed to initialize GLEW" << std::endl;
		return -1;
	}

	glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT);

		glColor3f(0.1, 0.3, 0.7);
		glBegin(GL_TRIANGLES);
		glVertex2f(-1, -0.5);
		glVertex2f(0.5, -0.5);
		glVertex2f(0, 1);
		glEnd();

		glColor3f(0.4, 0.3, 0.5);
		glBegin(GL_QUADS);
		glVertex2f(-0.25, -0.25);
		glVertex2f(-0.25, 0.3);
		glVertex2f(0.5, -0.2);
		glVertex2f(0.3, -0.4);
		glEnd();

		glColor3f(0.4, 0.2, 0.8);
		glBegin(GL_POLYGON);
		glVertex2f(0.0, 0.25);
		glVertex2f(-0.05, 0.6);
		glVertex2f(0.25, 0.75);
		glVertex2f(0.5, 0.5);
		glVertex2f(0.8, 0.35);
		glVertex2f(0.85, 0.1);
		glVertex2f(0.6, -0.1);
		glEnd();

		int i;
		double x, y;
		double radius = 0.30;   
		glColor3f(0.7, 0.3, 0.4);
		double twicePi = 2.0 * 3.142;
		x = .5, y = -.6;
		glBegin(GL_TRIANGLE_FAN); //BEGIN CIRCLE
		glVertex2f(x, y); // center of circle
		for (i = 0; i <= 100; i++) {
			glVertex2f(
				(x + (radius * cos(i * twicePi / 20))), (y + (radius * sin(i * twicePi / 20)))
			);
		}
		glEnd(); //END

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}
