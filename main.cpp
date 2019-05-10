#include <iostream>
#include "CopyVsAssignment.h"

int main()
{
    std::cout << "Assignment vs Copy !\n"; 
	CopyVsAssignment obj(1);
	CopyVsAssignment assign(2);
	assign = obj; //assigment constructor is called
	CopyVsAssignment copy = obj; // copy constructor is called
	std::cout << "Assign" + assign.data << std::endl;
	std::cout << "Copy" + copy.data << std::endl;
}