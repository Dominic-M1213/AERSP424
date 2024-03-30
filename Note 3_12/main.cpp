# include <iostream>
# include <thread> // for multithreading program
# include <chrono>


// 3/12
// Multiprocessing without resource sharing
//

// create a task, i.e., a function
void doNothing() {
	while (1);
}

void wait(int count) {
	std::this_thread::sleep_for(std::chrono::seconds(count));
}

void count(int n) {
	while (n-- > 0) {
		std::cout << n << std::endl;
	}
	std::this_thread::sleep_for(std::chrono::seconds(3)); // this task takes 3 seconds
}

void add_one(int* x) {
	*x = *x + 1;

	std::cout << *x << ",    ";
}

void add_two(int* x) {
	*x = *x + 2;

	std::cout << *x << ",    ";
}

typedef unsigned long long ull;

void sumOdd(ull from, ull to, ull* sum) {
	for (ull i = from; i <= to; i++) {
		if ((i & 1) == 1) {
			*sum = *sum + i;
		}
	}
}

void sumEven(ull from, ull to, ull* sum) {
	for (ull i = from; i <= to; i++) {
		if ((i & 1) == 0) {
			*sum = *sum + i;
		}
	}
}

int main() {

	// create threads to run a task
	//std::thread t1; // thread variable
	//t1 = std::thread(doNothing); // assign a task to a thread

	//std::thread t2(doNothing); // assigning a task at thread call

	//t1.join();

	ull startOdd = 0, endOdd = 5'000'000'000;
	ull startEven = 0, endEven = 5'000'000'000;
	ull sum_of_odd_numbers = 0;
	ull sum_of_even_numbers = 0;

	auto startTime = std::chrono::high_resolution_clock::now();

	// not using mutlithreading
	//wait(3);
	//wait(3);

	// using multithreading
	//std::thread t1(wait, 3); // a task "wait" starts here
	//std::thread t2(wait, 3); // another task "wait" also starts here
	//t1.join(); // main thread waits here for ~3 seconds for hte thread t1 to join
	//t2.join(); // the thread t2 also finishes running roughly at the same time as the thread t1, so the main thread didn't need to wait for t2.

/*
	std::thread t1(count, 10);
	std::cout << "we can still do something else before joining" << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(1)); // this thread takes 1 second
	t1.join(); // the main thread waits here
	//t1.detach(); // the main thread will no wait for the thread t1

	//
		//you have a really long code here. And you forget if you have already joined the thread
	//

	if (t1.joinable()) { // to check if join() is already called
		t1.join(); // double joining error. There is no task for a thread t1 to join the main thread.
	}


	int a = 0, b = 10;
	std::thread t2(add_one, &a);
	std::thread t3(add_one, &b);

	int c = 1, d = 2;
	std::thread t4(&add_two, std::ref(c));
	std::thread t5(&add_two, std::ref(d));

	t2.join();
	t3.join();
	t4.join();
	t5.join();
*/

	sumOdd(startOdd, endOdd, &sum_of_odd_numbers);
	sumEven(startEven, endEven, &sum_of_even_numbers);
/*
	std::thread t1(sumOdd, startOdd, endOdd, &sum_of_odd_numbers);
	std::thread t2(sumEven, startEven, endEven, &sum_of_even_numbers);
	t1.join();
	t2.join();
	*/
	auto stopTime = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::seconds>(stopTime - startTime );
	std::cout << "\nduration : " << duration.count() << " seconds" << std::endl;

	std::cout << "sumOdd : " << sum_of_odd_numbers << std::endl;
	std::cout << "sumEven : " << sum_of_even_numbers << std::endl;

	return 0;
}