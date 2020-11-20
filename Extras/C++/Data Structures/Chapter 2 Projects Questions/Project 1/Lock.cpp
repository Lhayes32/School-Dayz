#include "Lock.h"
#include <iostream>

using namespace std;
using namespace ch2_p1_Leo_H;

Lock::Lock(int A, int B, int C) 
{
	X = A;
	Y = B;
	Z = C;
}

void Lock::TurningToTheClockWiseDirection(int Clicks)
{
	if (LockIsNeutral)
	{
		if ((40 - Clicks) > 0)
			position = 40 - Clicks;
		else
			position = (40 - Clicks) + 40;
		flag1 = false;
		LockIsNeutral = false;
		if (position == X)
			flag1 = true;
	}
	else
	{
		if ((position - Clicks) > 0)
			position = position - Clicks;
		else
			position = (position - Clicks) + 40;
		flag3 = false;
		if (position == Z)
			flag3 = true;
	}
}

void Lock::AntiClockWiseDirection(int Clicks)
{
	position = (position + Clicks) % 40;
	flag2 = false;
	if (position = Y)
		flag2 = true;
}

void Lock::Top(void)
{
	cout << position << endl;
}

void Lock::Reset(void)
{
	LockIsNeutral = true;
	flag1 = false;
	flag2 = false;
	flag3 = false;
}

void Lock::Open(void)
{
	if (!(flag1 && flag2 && flag3))
	{
		unlock = false;
		cout << "Wrong Combination" << endl;
	}
	else
		cout << "Lock is open" << endl;
		
}