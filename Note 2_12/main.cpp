# include <iostream>
# include <array>
# include <vector>
# include <map>
# include "Plane.h"

// 2/15
// static and global
// const
// template function
// template class

int global = 5;

// const in front of a function means that the function is returning a constant variable
const double func(const float a) { // a is read-only
	// a++ is not possible
	return a;
}

const double& func2() {
	int b = 2;
	std::cout << &b << std::endl;
	return b;
}

template <typename MyDataType >
void myFunction(MyDataType input, MyDataType input2) {
	std::cout << input << std::endl;
	std::cout << input2 << std::endl; // need to print an input here regardless of the datatype of this
}

template <typename MyDataType , typename Type2>
void TypesFunction(MyDataType input, Type2 input2, int input3) {
	std::cout << input << std::endl; // need to print an input here regardless of the datatype of this
	std::cout << input2 << std::endl; // need to print an input here regardless of the datatype of this
	std::cout << input3 << std::endl; // need to print an input here regardless of the datatype of this
}

void myFunction(int input) {
	std::cout << input << std::endl; // need to print an input here regardless of the datatype of this input varibale
}
void myFunction(double input) {
	std::cout << input << std::endl; // need to print an input here regardless of the datatype of this input varibale
}

template <typename T>  // Template clss
class MyClass { // MyClass is the nae of the class
private:
	T x;
public:
	MyClass(T xx)
		:x{ xx }
	{
	}

		T getvalue() {
			return x;
		}
};


int main() {

	// static keyword
	// there are two scenarios for static
	// 1. static variable
	// 2. static function

	for (int i = 0; i < 3; i++) {
		// static keyword for a variable makes the variable act like a global variable
		static int x = 0;
		int y = 1;
		x++;
		std::cout << x << "," << & x << std::endl;
	}
	another_print();

	// global variables
	int global = 2;
	std::cout << ::global << std::endl;

	// const
	 const int c = 1; // const is typically used as a warning (so that you get a compilation error)
	// c = c + 1; // Cannot change x

	const int* p = &c; // const pointer pointing to a const variable
	double z = func(10);
	z++;

	double v = func2();
	std::cout << &v << std::endl;


	// template
	// template allows you to use a datatype as an input to a function or a class
	// All containers utilize template
	std::array<int, 3> a = { 1,2,3 };
	std::array<float, 3> b = { 1,2,3 };
	std::vector<char> n = { 'a','b','c' };
	std::map< int, std::array<int,8> > d;

	myFunction(1);
	myFunction(1.1);

	myFunction<char>('a','b');
	myFunction<int>(6,5);
	myFunction<float>(5.34,5);
	TypesFunction<float, double>(5.34, 0.2, 8);

	// Template Class
	MyClass<int> obj(5);
	std::cout << obj.getvalue() << std::endl;
	MyClass<char> obj2('v');
	std::cout << obj2.getvalue() << std::endl;

	return 0;
}