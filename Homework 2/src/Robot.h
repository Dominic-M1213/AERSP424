# ifndef ROBOT_H
# define ROBOT_H

# include <iostream>
# include <thread>
# include <mutex>
# include <vector>
# include <chrono>
#include <cstdlib>  // For std::rand()

// Robot Class Definition
class Robot {
public:
    Robot(int id, std::mutex& left_tool, std::mutex& right_tool);   // Robot Constructor
    void operator()();  // Future function to operate/control each robot

private:
    int id_;                    // Contains the ID of each robot
    std::mutex& left_tool_;     // References the memory location of the left_tool
    std::mutex& right_tool_;    // References the memory location of the right_tool
};

#endif // ROBOT_H