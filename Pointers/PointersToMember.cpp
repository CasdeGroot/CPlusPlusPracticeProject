#include "PointersToMember.h"
#include <iostream>

namespace Pointers
{
	int PointersToMember::StaticMemberVar = 5;

	int myFn(int i) {
		return 2 * i;
	}

	void PointerToMemberVar()
	{
		PointersToMember p;
		p.MemberVar = 9;
		PointersToMember* ptr_p = &p;

		//membervar_ptr now points to the member var (MemberVar) of a PointsToMember object
		int PointersToMember::* membervar_ptr =  &PointersToMember::MemberVar;
		//static_membervar_ptr now points to the static member var (StaticMemberVar) of a PointsToMember object 
		int* static_membervar_ptr = &PointersToMember::StaticMemberVar;
		std::cout << "The value of membervar_ptr should be 9 => " << p.*membervar_ptr;
		std::cout << "The value of static_membervar_ptr should be 5 => " << *static_membervar_ptr;
	}
	
	void PointerToMemberFunc()
	{
		//fn points to the function myFn
		Func* fn = &myFn;
		std::cout << "fn now points to myFn" << std::endl;
		std::cout << "fn should return 6 => " << fn(3) << std::endl;

		//fn points to the static member function
		fn = &PointersToMember::StaticFn;
		std::cout << "fn now points to StaticFn" << std::endl;
		std::cout << "fn should return 9 => " << fn(3) << std::endl;

		PointersToMember p;
		PointersToMember* ptr_p = &p;

		//mfn points to MemberFnA
		MemberFunc mfn = &PointersToMember::MemberFnA;
		std::cout << "fn now points to MemberFnA" << std::endl;
		std::cout << "fn should return 20 => " << (p.*mfn)(5) << std::endl;

		//mfn points to MemberFnB
		mfn = &PointersToMember::MemberFnB;
		std::cout << "fn now points to MemberFnB" << std::endl;
		std::cout << "fn should return 25 => " << (ptr_p->*mfn)(5) << std::endl;
	}

	int PointersToMember::StaticFn(int i)
	{
		return i * 3;
	}

	int PointersToMember::MemberFnA(int i)
	{
		return i * 4;
	}

	int PointersToMember::MemberFnB(int i)
	{
		return i * 5;
	}

}
