# ifndef ROBOT_H
# define ROBOT_H

# include <iostream>
# include <thread>
# include <mutex>
# include <vector>
# include <chrono>
#include <cstdlib>  // For std::rand()

class Robot {
public:
    Robot(int id, std::mutex& left_tool, std::mutex& right_tool);
    void operator()();

private:
    int id_;
    std::mutex& left_tool_;
    std::mutex& right_tool_;
};

#endif // ROBOT_H