// Q4.cpp
# include <../src/Q4.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}
void runQ4() {
    std::cout << "Running Q4...\n" << "-----------------------------------------------" << std::endl;

    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        return;
    }

    GLFWwindow* window = glfwCreateWindow(640, 480, "OpenGL Elliptical Lift Distribution Plotting", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return;
    }

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    glfwMakeContextCurrent(window);
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW\n";
        glfwDestroyWindow(window);
        glfwTerminate();
        return;
    }

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        double scale = 1.0; // Use this scale for both the width of the wing and the lift distribution

        // Draw the elliptical lift distribution
        glBegin(GL_LINE_STRIP);
        glColor3f(0.0f, 1.0f, 0.0f); // Green color
        for (double x = -scale; x <= scale; x += 0.01) {
            double L_prime = sqrt(1 - pow(x / scale, 2)); // Use scale for lift distribution width
            glVertex2f(x, L_prime);
        }
        glEnd();

        // Draw the wing beneath the lift distribution
        glBegin(GL_LINE_LOOP);
        glColor3f(1.0f, 1.0f, 1.0f); // White color for the wing
        for (double x = -scale; x <= scale; x += 0.01) {
            double y1 = -0.175 * sqrt(1 - pow(x / scale, 2)); // Adjusted for the wing width using the same scale
            double y2 = 0.1 * sqrt(1 - pow(x / scale, 2));
            glVertex2f(x, y1);
            glVertex2f(x, y2);
        }
        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    std::cout << "\nEnding Q4.\n" << "-----------------------------------------------" << std::endl;
}