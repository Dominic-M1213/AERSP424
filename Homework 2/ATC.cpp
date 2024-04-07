# include "ATC.h"

ATC::ATC() : inCommunication(false) {}

bool ATC::tryToLand(int id) {
    if (!inCommunication) {
        return true;
    }
    return false;
}

bool ATC::tryToQueue(int id) {
    if (landing_queue.size() < 3) {
        landing_queue.push(id);
        return true;
    }
    return false;
}

void ATC::land(int id) {
    {
        std::unique_lock<std::mutex> lock(mtx);
        inCommunication = true; // ATC is now in communication for the landing process
        notifyNextInQueue(id);
        std::this_thread::sleep_for(std::chrono::seconds(1)); // Simulate the landing
    } // Release the lock by exiting scope

    {
        std::unique_lock<std::mutex> lock(mtx);
        inCommunication = false; // Landing process is complete, ready for next.
    }
}

void ATC::notifyNextInQueue(int id) {
    // This function assumes it is called while the mutex is already locked.
    if (!landing_queue.empty()) {
        int next_id = landing_queue.front();
        landing_queue.pop();
    }
}

