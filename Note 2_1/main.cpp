# include <iostream>
# include <array>
# include <vector>
# include <algorithm>
# include <map>

// 2/1
// review function pointer
// lambda function
// containers

double derivative_func() {

	return 10;
}

int main() {
	std::cout << "Notes: 2/1" << std::endl;

	// function pointers
	std::cout << derivative_func() << std::endl; // function call
	std::cout << &derivative_func << std::endl; // memory address of a function
	std::cout << (*&derivative_func) () << std::endl; // dereference the memory address of a function

	double (*func_ptr)() = &derivative_func;

	// lambda function
	// is a function inside another function
	[]() {}; // An empty lambda function
	// () for input arguments
	// {} for a function implementation
	// [] for capturing variables in a larger scope of a function that the lamdba function lives in

	int x = 2, y = 3;
	// [] () {x + y;}; // this lambda function doesn't know/see x, y variables
	// [x, y] () -> {x + y; }; // performs a summation but returns nothing
	// [x, y]() -> int {return x + y; }; // returns a summation
	// auto val = [x, y]() -> int {return x + y; }; // assigns the value to 'val'
	auto val = [x, y](int a)->int {
		return (x + y) * a;
		};
	std::cout << val(10) << std::endl;

	// arrarys
	std::array<int, 3> arr;
	int x0 = 0;
	std::generate(arr.begin(), arr.end(), [x0]() mutable -> int {return x0++; });
	for (auto ar : arr)
		std::cout << ar << std::endl;

	// both arrays and vectors are containers
	std::array<int, 5> arrr = {1, 2, 3, 4, 5};
	std::vector<int> v = { 1,2,3 };
	v.push_back(10);
	v.push_back(20);
	for (auto i : v)
		std::cout << i << std::endl;

	// For array or vector, index (key) is a number and the value is based on the datatype
	std::cout << arrr[0] << std::endl;
	std::cout << v[1] << std::endl;

	// For map, you can use any datatype as a key
	std::map<char, double> m1;
	m1['a'] = 1.2;
	m1.insert({ 'b', 4.5 }); 
	std::cout << m1['a'] << std::endl;
	std::cout << m1['b'] << std::endl;

	// you can mix between multiple containers
	std::array<std::map<std::vector<char>, double>, 5> amv;
	std::vector<char> v1 = { 'a', 'b' };
	std::map<std::vector<char>, double> mm = {{v1, 5.6}};
		amv[4] = { {{'c', 'd' }, 1.3} };
		amv[3] = mm;
		std::cout << amv[3][{'a', 'b'}] << std::endl;
		std::cout << amv[3][{'c', 'd'}] << std::endl;
		std::cout << amv[4][{'c', 'd'}] << std::endl;

	return 0;
}