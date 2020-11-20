#include <cstdlib>
#include <cassert>
#include <ctime>  // used in initialization of random number generator
#include <iostream>
#include <stdlib.h>



using namespace std;

template <typename T>
bool is_sorted(T* a, size_t size)
{
	
	for (int i = 1; i < size; i++)
	{
		if (a[i] < a[i - 1])
			return false;
	}
	return true;
}
// precondition: a is not NULL
// returns: whether array a is sorted

template <typename T>
void shell_sort(T* a, size_t size)
{
	for (int presort = size / 5; presort > 0; presort /= 5)
	{
		for (int newsort = presort; newsort < size; newsort += 1)
		{
			int temp = a[newsort];
			int j;
			for (j = newsort; j >= presort && a[j - presort] > temp; j -= presort)
				a[j] = a[j - presort];
			a[j] = temp;
		}
	}
}
// precondition: a is not NULL
// postcondition: a is sorted in non-decreasing order

int* create_array(size_t size)
{
	int* a = new int[size];
	for (int i = 0; i < size; i++) {
		a[i] = rand() % 100 + 1;
	}
	
	return a;
}
// returns an array with size random integers

int main()
{
	size_t size = 1000;
	int* a = create_array(size);
	shell_sort(a, size);
	for (int i = 0; i < 20; i++)
	{
		cout << a[i] << endl;
	}
	assert(is_sorted(a, size));
	delete a;
	system("PAUSE");
	return EXIT_SUCCESS;
}

