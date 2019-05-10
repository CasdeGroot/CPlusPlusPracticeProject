#ifndef POINTERS_TO_MEMBER_H
#define POINTERS_TO_MEMBER_H

namespace Pointers
{
	class PointersToMember
	{
	public:
		static int StaticFn(int i);
		int MemberFnA(int i);
		int MemberFnB(int i);
		int MemberVar;
		static int StaticMemberVar;
	};

	void PointerToMemberVar();
	void PointerToMemberFunc();
	using MemberFunc = int (PointersToMember::*)(int);
	using Func = int(int);
}


#endif /* POINTERS_TO_MEMBER.H */

