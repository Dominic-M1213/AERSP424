# ifndef ATC_H
# define ATC_H

// Class Headers
# include <mutex>
# include <condition_variable>
# include <queue>
# include <string>
# include <iostream>

class ATC {
private:
    mutable std::mutex mtx;         // General Mutex to control the engagement of ATC
    std::condition_variable cv;     // General Conditional Variable used with mtx to control engagement of ATC
    std::queue<int> landing_queue;  // Initializing of the landing queue for the pilots
    bool inCommunication;           // Initializing a boolean to represent the status of the ATC (busy = true)

public:
    ATC();                          // ATC Constructor
    bool tryToConnect(int id);      // Connection Request Function
    bool tryToQueue(int id);        // Queue Request Function
    void land(int id);              // Landing Request
    void notifyNextInQueue(int id); // Notifying the next pilot to land
};

# endif // ATC_H
