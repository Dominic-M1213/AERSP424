// .cpp is a source file
// To write a library, you don't need a main function

# include <iostream>
void print_hello() {
		std::cout << "Hello" << std::endl;
}

void add_one(int* x) {
	*x = *x + 1;
}

