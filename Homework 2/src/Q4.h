// Q4.h
# ifndef Q4_H
# define Q4_H

// Q4 Headers
# include <iostream>
# include <GL/glew.h>
# include <GLFW/glfw3.h>
# include <vector>
# include <cmath>

// Defines a PI preprocessor constant if not properlly included by <cmath>.
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Function to run Q4
void runQ4();

# endif // Q4_h