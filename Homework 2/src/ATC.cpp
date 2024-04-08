# include <../src/ATC.h>

// ATC Class Constructor
ATC::ATC() : inCommunication(false) {}

// ATC Function for pilots to aquire communication with the ATC.
bool ATC::tryToConnect(int id) {
    if (!inCommunication) {
        inCommunication = true; // ATC is now in communication for the landing process
        return true;
    }
    return false;
}

// ATC Function for pilots to join the queue without contacting the ATC to wake up
bool ATC::tryToQueue(int id) {
    if (landing_queue.size() < 3) {
        landing_queue.push(id);
        return true;
    }
    return false;
}

// ATC Function for pilots to request landing clearence
void ATC::land(int id) {
    {
        std::unique_lock<std::mutex> lock(mtx);
        notifyNextInQueue(id);
        std::this_thread::sleep_for(std::chrono::seconds(1)); // Simulate the landing
    } // Release the lock by exiting scope

    {
        std::unique_lock<std::mutex> lock(mtx);
        inCommunication = false; // Landing process is complete, ready for next.
    }
}

// ATC Function to focus on the next airplane in queue
void ATC::notifyNextInQueue(int id) {
    // This function assumes it is called while the mutex is already locked.
    if (!landing_queue.empty()) {
        int next_id = landing_queue.front();
        landing_queue.pop();
    }
}

