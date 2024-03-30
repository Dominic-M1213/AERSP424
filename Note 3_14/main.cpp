# include <iostream>
# include <thread> // for multithreading program
# include <chrono>
# include <vector>
# include <functional>
# include <algorithm>
# include <string>
# include <mutex>

/*

*/

# define size 1'000'000'000
# define num_thread 10
# define data 

void set_elem(char* arr, unsigned int bsize) {
	for (unsigned int i = 0; i < bsize; i++) {
		*arr = 'C';
		arr++;
	}
}

void wait(int count) {
	std::this_thread::sleep_for(std::chrono::seconds(count));
}

std::mutex m; // this is a mutex variable

void print(std::string s1, std::string s2) {
	while (1) {
		m.lock(); // at this line, whichever thread gets to this line first can move on to the next line
				  // the other thread will be stuck at m.lock() line
		std::cout << s1 << "," << s2 << std::endl; // this line of code uses a shared resource
		wait(1);
		m.unlock(); // the first thread that gets to the m.lock() will get to this m.unlock() and release a mutex
					// allowing the next thread that is waiting at m.lock() to continue its execution.
	}
}

std::mutex m1, m2;

void task_a() {
	while (1) {
		//m1.lock(); // the first thread may get to this line
		//m2.lock(); // the first thread may also get to this line before the seoncd thread
		std::lock(m1, m2); // m1 and m2 are locked at the same time preventing a deadlock.
		std::cout << "task a";
		m2.unlock();
		m1.unlock();
	}
}
void task_b() {
	while (1) {
		//m1.lock(); // the second thread is waiting here
		//m2.lock(); 
		std::lock(m1, m2);
		std::cout << "task b";
		m2.unlock();
		m1.unlock();
	}
}

int main() {
	/*
	
	char* arr = new char[size];
	unsigned int batch_size = size / num_thread;
	auto startTime = std::chrono::high_resolution_clock::now();

	// using single-threading
	// 654 ms
	// sing multi-threading
	// 1081 ms, 
	//

	std::vector<std::thread> my_threads(num_thread);
	for (unsigned int i = 0; i < num_thread; i++) {
		my_threads[i] = std::thread(set_elem, &arr[batch_size * i], batch_size);
	}
	std::for_each(my_threads.begin(), my_threads.end(), );
	*/

	/*
	std::thread t1(print, "Hello", "World");
	std::thread t2(print, "AERSP", "424");
	t1.join();
	t2.join();
	*/

	// deadlock threads
	std::thread t1(task_a);
	std::thread t2(task_b);
	t1.join();
	t2.join();

	return 0;
}
