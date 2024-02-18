# include <iostream>

// 2/6
// week 3 hw solution
// struct
// sizeof struct / struct padding
// members
// class, include guard, constructor/deconstructor
// encapsulation / get&set
// overloading
// static keyword


// struct is a set of variables with different datatypes
struct { // this is a struct without a name
	char c;
	int a;
};

struct {
	char c;
	int a;
}A; // A is not a struct. A is a global variable with an unnamed struct as a type

struct S
{ // S is a struct
	char c;
	int a;
}; // There is no global variable initialized with this struct

struct T_t{ // T_t is a struct
	char c;
	int a;
}T; // T is not a struct. T is a global variable with a struct T as a type 

struct Person { // Person is a struct
	// each of the following variables is called 'variable member'
	char initial; // 1 byte
	char lastname_initial; // 1 byte
	int home_address; // 4 bytes 
	int height; // 4 bytes
	int weight; // 4 bytes
	double age; // 8 bytes 

	// In C++, we can also have a function member
	void greeting() {
		std::cout << "hi" << std::endl;
	}
}; // there is no global variable initialized with this struct


class Person2 {// Person is a struct
	// For a class, by default, every member is private
	// each of the following variables is called 'variable member'
// private:
	char initial; // 1 byte
	char lastname_initial; // 1 byte
	int home_address; // 4 bytes 
	int height; // 4 bytes
	int weight; // 4 bytes

public:
	double age; // 8 bytes 

	// In C++, we can also have a function member
	void greeting() {
		std::cout << "hi" << std::endl;
		this->initial = 'a'; // this is inside a class
		home_address = 123;
	}

	void greeting(std::string word) { // this greeting function is not the smae as the above greeting function because of the input arguments 
		std::cout << word << std::endl;
	} 

	// having multiple function with the same name but different input arguments is a function overloading
	// This can be used outside of a struct/class
	void greeting(int x) {
		std::cout << x << std::endl;
	}
};


int main() {
	std::cout << "Notes: 02/06" << std::endl;
	
	A.a = 1; // a is a member of S
	std::cout << A.a << std::endl;

	S s;
	s.c = 'b';
	std::cout << s.c << std::endl;

	T_t b;
	b.a = 2;
	std::cout << b.a << std::endl;

	Person me; // me is an object instantiatied from a struct. (datatype & variable)
	me.initial = 'D';
	me.age = 20;
	std::cout << sizeof(me) << "," << sizeof(Person) << std::endl;
	me.greeting();
	char* p = &me.initial;
	std::cout << p << "," << &me.home_address << "," << &me.age << std::endl;
	// 18 19 1A 1B, 1C 1D 1E 1F
	// 20                    27
	// 28 29 2A 2B, [ padding ]

	Person2 you;
	// you.initial = 'T'; // error






	// week 3 hw solution
	// 1. Access a memory address and change a value of bit 6 & 7
	// unit8_t* p = 0x80; // 0x80 is a number 80 in base-16
	// unit8_t* p = (unit8_t*)0x80; // 0x80 is recast as a memory address for a pointer
	// 2. To change a value of bit 6&7
	// ???? ???? // we do not kow what thevalue of each bit is (could be either 0 or 1)
	// ? | 1 = 1 (bitwise operator |)
	// ? | 0 = ? (bitwise operator |)
	// ? & 0 = 0 (bitwise operator &)
	// ? & 1 = 1 (bitwise operator &)	
	
	// ???? ???? // we do not know the value of each bit
	// 1000 0000 (|)
	// 1??? ????
	// 1011 1111 (&)
	// 10?? ???? // we want bit 7 to be 1 and bit 6 to be 0

	// To get 1000 0000 = (1 << 7)
	// To get 1011 111 = ~(1 << 6)


		
	return 0;
}