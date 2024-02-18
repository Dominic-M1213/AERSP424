# include <iostream>
# include <memory>

// 1/25
// Scope (local, global)
// Memory Storage (Stack, head, static ,etc.)
// Memory Address (array, pointers, reference)
// Parameter passing (value, address, referance)

// Any Global variables will be stored in a static memory
// These variables will remain in a memory until the program stops running.
char c = 'a'; // this is a global variable. It is in a global scope


void pass_by_value_func(int z)
{
	z = 3;
	std::cout << z << std::endl;
	std::cout << &z << std::endl;
}

void pass_by_pointer_func(int* z)
{
	std::cout << z << std::endl;
	std::cout << &z << std::endl;
	std::cout << *z << std::endl;
	*z = 3;
	std::cout << z << std::endl;
	std::cout << &z << std::endl;
	std::cout << *z << std::endl;
}

void pass_by_reference_func(int& z)
{
	std::cout << "In a function" << std::endl;
	std::cout << z << std::endl;
	std::cout << &z << std::endl;
	z = 3;
	std::cout << z << std::endl;
	std::cout << &z << std::endl;
	std::cout << "Going out of a function" << std::endl;
}


int main() {
// this is a scope of the main function
	int x = 1;
	int l = 2;
	std::cout << l << std::endl;
	std::cout << &l << std::endl;
	pass_by_value_func(l);
	std::cout << l << std::endl;
	std::cout << &l << std::endl;
	pass_by_pointer_func(&l);
	std::cout << l << std::endl;
	std::cout << &l << std::endl;
	pass_by_reference_func(l);
	std::cout << l << std::endl;
	std::cout << &l << std::endl;

	if (true)
	{
		// this is the scope of the if function
	}

	{ // this is another scope, inside the scope of the main function
		double y = 1.1;
		std::cout << c << std::endl;
		std::cout << x << ", " << y << std::endl;
	} // at this line (end of the scope), all variables inside the scoep will be destroyed


	std::cout << x << std::endl;
	// std::cout << y << std::endl; // gives error since variable is destroyed

	// _________________________________________________________________________

	// Memory 

	std::cout << "The value of x is " << x << std::endl; // this is the number inside the memory address where x is stored
	std::cout << "The meomry address of x is " << &x << std::endl;  // where x is stored in RAM

			// any local variables in a scope will be stored in a stack memory
			// all these local variables will be destoryed at the end of the scope, which means the stack memory will be cleared
			

	// _________________________________________________________________________

	// Pointer

	int* p;  // a pointer is a variable that stores a memory address
			 // the pointer itself is also stored somewhere inside the memory

	p = &x;

	std::cout << "The value of p is " << p << std::endl; // this is the number inside the memory address where x is stored
	std::cout << "The memory address of p is " << &p <<std::endl; // the memory address of p
	std::cout << "The dereference value of p is " << *p << std::endl; // the value stored at the memory address where p is pointing at

	std::cout << "The memory address of c (a global variable) is " << &c << std::endl; // the memory address of c

	// _________________________________________________________________________________

	// Arrays

	int arr[3] = { 1,2,3 }; // is also inside a stack memory
	std::cout << "The memory address of arr is " << &arr << std::endl; // the memory address of arr
	std::cout << "The memory address of arr[0] is " << &arr[0] << std::endl; // the memory address of arr
	std::cout << "The memory address of arr[1] is " << &arr[1] << std::endl; // the memory address of arr
	std::cout << "The memory address of arr[2] is " << &arr[2] << std::endl; // the memory address of arr

	// _________________________________________________________________________________

	// Heap Memory
	// this is where you can ask for as many memory blocks you want from a computer
	// you can use a pointer to point a block of memory where it hasn't been allocated to any existing variable
	// When working with a heap memory; there's a chance of "memory leak"
	// Memory leak means that we may lose access to the dynamically allocated memory
	
		int* ptr = new int;
		

		std::cout << "The value of ptr is " << ptr << std::endl; // this is the number inside the memory address where ptr is stored
		std::cout << "The memory address of ptr is " << &ptr << std::endl; // the memory address of ptr

		delete p, ptr; // 1 way to prevent a memory leak;

		// another way to prevent a memory leak is to use a smart pointer # include <memory>
		std::unique_ptr<int> sp = std::make_unique<int>();
		auto sp2 = std::make_unique<int>();

	
	// whatever block of memory ptr is pointing at, we cannot access it if ptr goes out of the scope
	// we lose 4 bytes of memory
	
	// _________________________________________________________________________________

	// Reference
		// reference is an alias of a variable (rename a variable)

		double abc = 4.5;
		double& def = abc; // def is a reference of abc

		def = 6.7;
		std::cout << abc << std::endl;
		std::cout << def << std::endl;

		abc = 8.9;
		std::cout << abc << std::endl;
		std::cout << def << std::endl;

	return 0;
	// this is the end of the scope of the main function
}