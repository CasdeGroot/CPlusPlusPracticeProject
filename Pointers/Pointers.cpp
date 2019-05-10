// Pointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "structs.h"
#include "PointersToMember.h"

void CreatingAPointer()
{
	int number = 20; //on stack
	int* number_ptr; // on heap
	number_ptr = &number; //on stack

	std::cout << number << std::endl; //retrieves number value from stack
	std::cout << &number_ptr << std::endl; //retrieves number address from heap
	std::cout << *number_ptr << std::endl; //retrieves number value from heap

	delete number_ptr; //delete the pointer if its not needed anymore
}

void CreatingAPointerVariable()
{
	Pointers::myStruct foo; // On stack
	Pointers::myStruct* foo_ptr = nullptr; //On heap
	std::cout << "Size of the foo = " << sizeof(foo) << std::endl; //should be 4 bytes
	std::cout << "Size of foo_ptr = " << sizeof(foo_ptr) << std::endl; //should be size of 12 bytes

	Pointers::myStruct* bar_ptr;
	Pointers::myStruct* bar2_ptr = &foo;

	foo_ptr = bar2_ptr;
	std::cout << "Size of the foo = " << sizeof(foo) << std::endl; //should still be 4 bytes

	(*foo_ptr).variable1 = 5; //points to foo
	std::cout << "Variable 1 of foo = " << foo.variable1 << std::endl;  // == 5
	std::cout << "Variable 1 of foo_ptr = " << (*foo_ptr).variable1 << std::endl; // == 5
	std::cout << "Variable 1 of foo = " << foo_ptr->variable1 << std::endl; // == 5
	// std::cout << bar_ptr->variable1; //uninitialised gives warning

	//always delete pointers if they are not used anymore
	delete foo_ptr;
	delete bar2_ptr;
	//delete bar_ptr;
}

void IncrementingAPointer()
{
	char* str = new char[10]; //str = 0x010
	str++; //str = 0x011 => we move sizeof(char) once
	*str = 'a';
	std::cout << str[0];
	str += 2; //str = 0x012
	*str = 'b';
	std::cout << str[0];

	str -= 3;
	std::cout << str[1] << str[3];

	int* arr = new int[10]; //arr = 0x00100;
	++arr; //arr = 0x00104 => we move sizeof(int) once
	arr += 2; //arr = 0x0108;

	void* ptr = (void*)new char[10];
	// ++ptr; void is not a complete type
}

void PointerDifferencing()
{
	char* full = new char[10];
	char* start = &full[5];
	full += 5;
	char* end = &full[5];
	
	std::ptrdiff_t diff = full - start;
	std::ptrdiff_t diff2 = full - end;
	std::ptrdiff_t diff3 = end - full;
	std::ptrdiff_t diff4 = start - full;
	std::ptrdiff_t diff5 = start - end;

	std::cout << "Full - Start " << diff << std::endl;
	std::cout << "Full - End " << diff2 << std::endl;
	std::cout << "End - Full " << diff3 << std::endl;
	std::cout << "Start - Full " << diff4 << std::endl;
	std::cout << "Start - End " << diff5 << std::endl;
}

int main()
{
    std::cout << "Hello World!\n"; 
	//CreatingAPointer();
	//CreatingAPointerVariable();
	//IncrementingAPointer();
	//PointerDifferencing();
	Pointers::PointerToMemberFunc();
	Pointers::PointerToMemberVar();
}


