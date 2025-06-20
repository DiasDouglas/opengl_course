#include <GLFW/glfw3.h>
#include <iostream>

int main()
{
    // Initialize GLFW
    glfwInit();

    // Tell GLFW what version of OpenGL we are using, 3.3 in this case
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    // Tell GLFW we are using the CORE profile, so we'll have only modern functions
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Creating a window. Params: width, height, name of the window, fullscreen, not important
    GLFWwindow* window = glfwCreateWindow(800, 800, "Learning OpenGL", NULL, NULL);

    // Error check if the window creation failed
    if(window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();

        return -1;
    }

    // Add the window to the current context
    glfwMakeContextCurrent(window);

    // Specify the viewport in the window, from coordinate on bottom left (0, 0) to (800, 800)
    glViewport(0, 0, 800, 800);

    // Defining the background color
    glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
    // Clear the back buffer and assign a new color to it
    glClear(GL_COLOR_BUFFER_BIT);
    // Swap the back buffer with the front buffer
    glfwSwapBuffers(window);

    // Main while loop
    while(!glfwWindowShouldClose(window))
    {
        // Take care of all GLFW events
        glfwPollEvents();
    }

    // Delete window before ending the program
    glfwDestroyWindow(window);
    // Terminate GLFW
    glfwTerminate();
    return 0;
}
