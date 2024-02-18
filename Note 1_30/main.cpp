# include <iostream>
# include <array>
# include <memory>

// Day: 1/30
// weekly Q2, Q3
// pointer application (weekly Q1, fast inverse sqrt, embedded)
// more on dynamic allocation (pointers vs smart pointers)
// array vs pointers, weekly Q4
// C, old C++, modern C++
// sizeof pointer
// memory fragmentaiton
// function pointer
// lambda function
// weekly Q5
// Data structure (next class)
// Containers, Iterations, Algorithm (next class)

int func() {
	return 10;
}

int foo() {
	return 1;
}

int goo() {
	return 1;
}

double hoo(int) {
	return 1.1;
}

double ioo(int,char) {
	return 1.1;
}

double car_dynamics(double t) { return 1.1; }
double plane_dynamcis(double t) { return 1.1; }

double derivative_f(double (*f)(double)) {
	double t = 1;
	return (f(t - 0.0001) + f(t + 0.0001)) / 2 * t;
}

int main() {
	std::cout << "Notes: 1/30" << std::endl;

	// new and delete keywords are old Cpp-style
	int* x = new int; // ask for 1 int (4 bytes)
	int* y = new int[3]; // ask for 3 int (12 bytes)
	delete x;
	delete y;

	// C-style
	int* x2 = (int*)malloc(sizeof(int)); // ask for 1 int (4 bytes)
	free(x2);
	double* y2 = (double*)malloc(4 * sizeof(double)); // ask for 4 double (32 bytes)
	free(y2);

	// modewrn C++ style (smart pointer), need #include <memory>
	std::unique_ptr<float> f = std::make_unique<float>(); // ask for 1 float (4 bytes)
	std::unique_ptr<int[]> p3 = std::make_unique<int[]>(6); // asl for 6 integer (24 bytes)

	// array vs pointer
	int a[3];
	int* b = new int[3];
	a[0] = 1; a[1] = 2; a[2] = 3;
	b[0] = 1; b[1] = 2; b[2] = 3;

	std::cout << &a << ", " << &a[0] << ", " << &a[1] << ", " << &a[2] << std::endl;
	std::cout << &b << ", " << &b[0] << ", " << &b[1] << ", " << &b[2] << std::endl;

	std::cout << "char " << sizeof(char) << std::endl;
	std::cout << "short " << sizeof(short) << std::endl;
	std::cout << "int " << sizeof(int) << std::endl;
	std::cout << "float " << sizeof(float) << std::endl;
	std::cout << "double " << sizeof(double) << std::endl;

	std::cout << "char* " << sizeof(char*) << std::endl;
	std::cout << "short* " << sizeof(short*) << std::endl;
	std::cout << "int* " << sizeof(int*) << std::endl;
	std::cout << "float* " << sizeof(float*) << std::endl;
	std::cout << "double* " << sizeof(double*) << std::endl;

	// memory fragmentation
	
	// int* x = new int[4];
	// int* y = new int[6];
	// int* z = new int[10];
	// 
	// delete y;
	// int* y = new int[20];
	
	// function pointer
	// A function itself needs to be stored somewhere in memory
	// There will be a memory address where the function is stored
	std::cout << func() << std::endl;
	std::cout << func << std::endl;
	std::cout << &func << std::endl;
	std::cout << *&func << std::endl;

	// a function pointer needs to have the same datatype (for both input and output arguments)
	int (*func_ptr)() = (&foo);
	func_ptr = &goo;
	// func_ptr = &hoo; //ERROR by argument
	double (*fp)(int) = (&hoo);
	double (*fp2) (int, char) = (&ioo);

	// example
	// We can use a function pointer when we want to have a function to be an input to another function
	derivative_f(car_dynamics);
	derivative_f(plane_dynamcis);

	// variable pointer
	int x3 = 1;

	std::cout << x3 << std::endl; // value of x
	std::cout << &x3 << std::endl; // address of x
	std::cout << *&x3 << std::endl; // dereferenced an address of x



	return 0;
}