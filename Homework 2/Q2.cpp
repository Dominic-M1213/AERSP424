// Q2.cpp
# include "Q2.h"

void runQ2() {
    std::cout << "Running Q2...\n" << "-----------------------------------------------" << std::endl;

    const int num_robots = 5;
    std::vector<std::mutex> tools(num_robots);
    std::vector<std::thread> robot_threads;

    // Start the timer
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < num_robots; ++i) {
        robot_threads.emplace_back(Robot(i, tools[i], tools[(i + 1) % num_robots]));
    }

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
