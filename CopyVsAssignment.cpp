#include "CopyVsAssignment.h"



CopyVsAssignment::CopyVsAssignment(int data)
{
	this->data = data;
}

CopyVsAssignment& CopyVsAssignment::operator=(const CopyVsAssignment& other)
{
	data = other.data;
	return *this;
}

CopyVsAssignment::CopyVsAssignment(const CopyVsAssignment& other)
{
	this->data = other.data;
}

CopyVsAssignment::~CopyVsAssignment()
{
}
