# include <iostream>
# include <thread> // for multithreading program
# include <chrono>

void wait(int count) {
	std::this_thread::sleep_for(std::chrono::seconds(count));
}
void printAERSP() {

	while (1) {
		std::cout << "AERSP";
		wait(1);
	}
}

void print424() {
	while (1) {
		std::cout << " 424" << std::endl;
		wait(1);
	}
}

int main() {
	auto startTime = std::chrono::high_resolution_clock::now();
	int i = 0;
	while ( i < 10) {
		std::thread t1(printAERSP);
		std::thread t2(print424);
		t1.join();
		t2.join();
		i++;
	}

	return 0;
}