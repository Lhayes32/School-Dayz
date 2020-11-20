#ifndef LOCK_H
#define LOCK_H

namespace ch2_p1_Leo_H {
	class Lock
	{
	public:
		Lock(int A, int B, int C);
		void TurningToTheClockWiseDirection(int Clicks);
		void AntiClockWiseDirection(int Clicks);
		void Reset(void);
		void Open(void);
		void Top(void);

	private:
		bool LockIsNeutral = true;
		bool flag1, flag2, flag3;
		int X, Y, Z;
		bool unlock = true;
		int position = 0;
	};
}





#endif
