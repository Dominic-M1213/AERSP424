// Q2.cpp
# include <../src/Q2.h>

void runQ2() {
    std::cout << "Running Q2...\n" << "-----------------------------------------------" << std::endl;

    const int num_robots = 5;                   // Declares 5 robots for this program
    std::vector<std::mutex> tools(num_robots);  // Declares 5 tools (represented as mutex resources)
    std::vector<std::thread> robot_threads;     // Declares a vector of threads for each robot

    // Start the timer
    auto start = std::chrono::high_resolution_clock::now();

    // Establish a thread for each robot, defines its two tools (resources)
    for (int i = 0; i < num_robots; ++i) {
        robot_threads.emplace_back(Robot(i, tools[i], tools[(i + 1) % num_robots]));
    }

    // calls each robot to begin completing the tasks one by one.
    for (auto& thread : robot_threads) {
        thread.join();
    }

    // Stop the timer
    auto end = std::chrono::high_resolution_clock::now();

    // Calculate the duration
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start).count();

    std::cout << "All robots have completed their tasks." << std::endl;
    std::cout << "Total duration: " << duration << " seconds." << std::endl;

    std::cout << "\nEnding Q2.\n" << "-----------------------------------------------" << std::endl;
}
