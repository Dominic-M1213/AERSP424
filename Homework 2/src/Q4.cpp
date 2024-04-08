// Q4.cpp
# include <../src/Q4.h>

double calculateTW(double ws) {
    double TW = 1 / ws;
    return TW; // Example: Direct proportion for illustration purposes
}

void runQ4() {
    std::cout << "Running Q4...\n" << "-----------------------------------------------" << std::endl;

    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        //return -1;
    }

    // Create a windowed mode window and its OpenGL context
    GLFWwindow* window = glfwCreateWindow(1280, 960, "T/W vs W/S Plot", NULL, NULL);
    if (!window) {
        glfwTerminate();
        std::cerr << "Failed to create GLFW window\n";
        //return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    // Initialize GLEW
    glewExperimental = true; // Needed for core profile
    if (glewInit() != GLEW_OK) {
        glfwTerminate();
        std::cerr << "Failed to initialize GLEW\n";
        //return -1;
    }

    // Define the viewport dimensions
    glViewport(0, 0, 1280, 960);

    // Define the range of W/S values for which we want to plot T/W
    const double wsStart = 0.1;
    const double wsEnd = 1.0;
    const double wsIncrement = 0.1;
    std::vector<float> graphPoints;

    for (double ws = wsStart; ws <= wsEnd; ws += wsIncrement) {
        graphPoints.push_back(static_cast<float>(ws));    // x-coordinate (W/S)
        graphPoints.push_back(static_cast<float>(1/ws + ws)); // y-coordinate (T/W)
    }

    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window)) {
        // Render here
        glClear(GL_COLOR_BUFFER_BIT);

        // Draw the points
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(2, GL_FLOAT, 0, &graphPoints[0]);
        glDrawArrays(GL_LINE_STRIP, 0, graphPoints.size() / 2);
        glDisableClientState(GL_VERTEX_ARRAY);

        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();


    std::cout << "\nEnding Q4.\n" << "-----------------------------------------------" << std::endl;
}