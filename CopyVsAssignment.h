#pragma once
class CopyVsAssignment
{
public:
	CopyVsAssignment(int data);
	CopyVsAssignment& operator=(const CopyVsAssignment& other);
	CopyVsAssignment(const CopyVsAssignment& other);
	~CopyVsAssignment();
	int data;
};

