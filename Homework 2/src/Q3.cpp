// Q3.cpp
# include <../src/Q3.h>

void runQ3() {
    std::cout << "Running Q3...\n" << "-----------------------------------------------" << std::endl;

    ATC atc;                            // Declares the ATC class
    std::vector<std::thread> threads;   // Declares the threads for each pilot
    const int num_pilots = 10;          // Declares the number of pilots

    // Start the timer
    auto start = std::chrono::high_resolution_clock::now();

    // Establishes each thread as a pilot and its operation
    for (int i = 0; i < num_pilots; ++i) {
        threads.emplace_back([&, i] {
            Pilot pilot(i, atc);
            pilot.operateAircraft();
        });
    }

    // Joins the threads to beginning operating the pilots
    for (auto& thread : threads) {
        thread.join();
    }

    // Stop the timer
    auto end = std::chrono::high_resolution_clock::now();

    // Calculate the duration
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start).count();
    std::cout << "Total duration: " << duration << " seconds." << std::endl;

    std::cout << "\nEnding Q3.\n" << "-----------------------------------------------" << std::endl;
}
