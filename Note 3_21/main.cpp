# include <iostream>
# include <thread>
# include <queue>
# include <mutex>
# include <condition_variable>
# include <chrono>
# include <string>
# include <future>
# include <functional>

// 3/12
// Queue and Buffer
// Conditional Vairable
// Promise and Future
// Async
// Library

void producer(std::queue<int>& itemQueue) {
	int size = 100;
	for (int i = 0; i < size; i++) 
		itemQueue.push(i);
}

void consumer(std::queue<int>& itemQueue) {
	while (!itemQueue.empty()) { 
		std::cout << itemQueue.front() << std::endl; 
		itemQueue.pop(); 
	}
}


// Using mutex
/*
template<typename T>
class MutexQueue {
	std::queue<T> queue_;
	mutable std::mutex mutex_;
public:
	MutexQueue() = default;
	MutexQueue(const MutexQueue<T>&) = delete;
	MutexQueue& operator=(const MutexQueue<T>&) = delete;
	MutexQueue(MutexQueue<T>&& other) {
		std::lock_guard<std::mutex> lock(mutex_);
		queue_ = std::move(other.queue_);
	}
	virtual ~MutexQueue() { }
	unsigned long size() const {
		std::lock_guard<std::mutex> lock(mutex_);
		return queue_.size();
	}
	T pop() {
		std::lock_guard<std::mutex> lock(mutex_);
		if (queue_.empty()) {
			return {};
		}
		T tmp = queue_.front();
		queue_.pop();
		return tmp;
	}
	void push(const T& item) {
		std::lock_guard<std::mutex> lock(mutex_);
		queue_.push(item);
	}
	bool empty() const {
		std::lock_guard<std::mutex> lock(mutex_);
		return queue_.empty();
	}
};
void producer(MutexQueue<int>& itemQueue) {
	int size = 100;
	for (int i = 0; i < size; i++)
		itemQueue.push(i);
}
void consumer(MutexQueue<int>& itemQueue) {
	while (!itemQueue.empty()) {
		std::cout << itemQueue.pop() << std::endl;
	}
}
*/


// Conditional Variabl (cv) is another application of mutex
// Instead of using lock() and unlock() from mutex, cv uses signaling and waiting mechanism
// You may need to use cv instead of a pure mutex when the first thread (the fastes thread) 
//


std::condition_variable cv;
std::mutex m;
unsigned long balance = 0;
void addMoney(int money) {
	std::lock_guard<std::mutex> lg(m);
	balance += money;
	std::cout << "Amount Added Current Balance: " << balance << std::endl;
	cv.notify_one();
}
void withdrawMoney(int money) {
	std::unique_lock<std::mutex> ul(m);
	std::cout << "Cannot withdrawn without adding money. Waiting..." << std::endl;
	cv.wait(ul);
	if (balance >= money) {
		balance -= money;
		std::cout << "Deducted: " << money << std::endl;
	}
	else {
		std::cout << "Cannot withdraw. Balance is less than: " << money << std::endl;
	}
	std::cout << "Current Balance: " << balance << std::endl;
}


// Promise and Future
void first() { printf("first"); }
void second() { printf("second"); }
void third() { printf("third"); }
class Foo {
	std::promise<void> p1, p2;
public:
	Foo() {}
	void first(std::function<void()> printFirst) {
		printFirst();	// thread t1, print "first"
		p1.set_value();	// set the variable p1
	}
	void second(std::function<void()> printSecond) {
		p1.get_future().wait();	// initially thread t2 is waiting for a varibale p1 to be set
		// after the variable p1 has been set by thread t1, the thread t2 can be set
		printSecond();
		p2.set_value();
	}
	void third(std::function<void()> printThird) {
		p2.get_future().wait();
		printThird();
	}
};

// Async
// std::async is similar to std::thread but you can get a return value (output) from a task
// For std::thread, you will need to use either global variables, pointers, or references to update
// a value of a variable
// For std::async, you can get the output from a thread simialr to calling a regular function.


// a task : doing a summation of odd numbers from an integer 'from' to an integer 'to'
typedef unsigned long long ull;
ull findOddSum(ull from, ull to) {
	ull OddSum = 0;
	std::cout << "ThreadID" << std::this_thread::get_id() << std::endl;
	for (ull i = from; i <= to; i++)
		if (i & 1)
			OddSum += i;
	return OddSum;
}

int main() {
	std::queue<int> itemQueue; // no-thread safe guarantee
	//MutexQueue<int> itemQueue;
	std::jthread t1(producer, itemQueue);
	std::jthread t2(producer, itemQueue);
	std::jthread t3(consumer, itemQueue);
	t1.join();
	t2.join();
	t3.join();

	// Conditional Variable
	std::jthread t4(withdrawMoney, 600);
	std::this_thread::sleep_for(std::chrono::seconds(2));
	std::jthread t5(addMoney, 500);
	t4.join();
	t5.join();
	// Promise and Future
	Foo bar;
	std::jthread t6(&Foo::first, &bar, first);
	std::jthread t7(&Foo::second, &bar, second);
	std::jthread t8(&Foo::third, &bar, third);
	t6.join();
	t7.join();
	t8.join();

	// Asynce
	std::cout << "Launch Async" << std::endl; 
	std::cout << "ThreadID" << std::this_thread::get_id() << std::endl; 
	// std::future<ull> OddSum variable receives an output from std::async, which we cannot be done with std::thread
	std::future<ull> OddSum = std::async(std::launch::async, findOddSum, 0, 
		50000000); 
	std::cout << "Waiting for Result..." << std::endl;  
	std::cout << "OddSum: " << OddSum.get() << std::endl; 


	return 0;
}