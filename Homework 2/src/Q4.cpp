// Q4.cpp
# include <../src/Q4.h>

// Defines a function to allow for scaling the viewing window
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void runQ4() {
    std::cout << "Running Q4...\n" << "-----------------------------------------------" << std::endl;

    // Checks to see if GLFW was initialized
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        return;
    }

    // Checks to see if a window was properlly created
    GLFWwindow* window = glfwCreateWindow(640, 480, "OpenGL Elliptical Lift Distribution Plotting", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return;
    }

    // Callback function to dynamically change the window size by the user in real time
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    glfwMakeContextCurrent(window);
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW\n";
        glfwDestroyWindow(window);
        glfwTerminate();
        return;
    }

    // Sets background color
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    // While the window is open, plot... Else window was closed
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        double scale = 1.0; // Use this scale for both the width of the wing and the lift distribution

        // My equation for Q4 was the elliptical lift distribution of a wing. 
        // Below is my lines to plot the distribution.
        // Draw the elliptical lift distribution
        glBegin(GL_LINE_STRIP);
        glColor3f(0.0f, 1.0f, 0.0f); // Green color
        for (double x = -scale; x <= scale; x += 0.01) {
            double L_prime = sqrt(1 - pow(x / scale, 2)); // Use scale for lift distribution width
            glVertex2f(x, L_prime);
        }
        glEnd();

        // Below the Elliptical Lift distribution, I wanted to also visualize a general elliptical wing
        // Thought not necessarily the exact shape of an elliptical wing, it is a generally shaped 
        // planeform to represent the distribution. The way the lines were drawn allowed for a "shaded"
        // effect of the object. Difficulties rose when trying to define my own planform as a closed shape
        // to then color in as an elliptical wing is not actually an elipse. The centerline is skewed to 
        // about the 1/4 chord point.
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