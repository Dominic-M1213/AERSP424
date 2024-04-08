# ifndef ATC_H
# define ATC_H

# include <mutex>
# include <condition_variable>
# include <queue>
# include <string>
# include <iostream>

class ATC {
private:
    mutable std::mutex mtx;
    std::condition_variable cv;
    std::queue<int> landing_queue;
    bool inCommunication;

public:
    ATC();
    bool tryToLand(int id);
    bool tryToQueue(int id);
    void land(int id);
    void notifyNextInQueue(int id);
};

# endif // ATC_H
