# include "Robot.h"

Robot::Robot(int id, std::mutex& left_tool, std::mutex& right_tool)
    : id_(id), left_tool_(left_tool), right_tool_(right_tool) {}

void Robot::operator()() {
    while (true) {
        // Try to acquire both tools without blocking.
        std::unique_lock<std::mutex> lock_left(left_tool_, std::try_to_lock);
        std::unique_lock<std::mutex> lock_right(right_tool_, std::try_to_lock);

        if (lock_left.owns_lock() && lock_right.owns_lock()) {
            std::cout << "Robot " << id_ << " has both tools and is performing the task." << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(5));
            std::cout << "Robot " << id_ << " has completed the task." << std::endl;
            break;
        }

        // Wait a random amount of time before retrying to avoid collision.
        std::this_thread::sleep_for(std::chrono::milliseconds(10 + (std::rand() % 100)));
    }
}

