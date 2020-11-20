#include "Statistician.h"

using namespace ch2_p2_Leo_H;

statistician::statistician()
{
	length = 0;
	sum = 0;
	last = 0;
	smallest = 0;
	largest = 0;
	mean = 0;
}
void statistician::set_length()
{
	++length;
}
void statistician::set_last(double n)
{
	last = n;
}
void statistician::next_number(double n)
{
	set_length();
	set_sum(n);
	set_mean();
	set_smallest(n);
	set_largest(n);
	set_last(n);
}
void statistician::set_sum(double n)
{
	sum += n;
}
void statistician::set_mean()
{
	if(is_empty()) mean = sum / length;
}
void statistician::set_smallest(double n)
{
	if (n < smallest)
	{
		smallest = n;
	}
}
void statistician::set_largest(double n)
{
	if (n > largest)
	{
		largest = n;
	}
}
int statistician::get_length()
{
	return length;
}
double statistician::get_last()
{
	return last;
}
double statistician::get_sum()
{
	return sum;
}
double statistician::get_mean()
{
	return mean;
}
double statistician::get_smallest()
{
	return smallest;
}
double statistician::get_largest()
{
	return largest;
}
bool statistician::is_empty()
{
	return(length > 0);
}

void statistician::operator +(statistician s2)
{
	set_largest(s2.get_largest());
	set_smallest(s2.get_smallest());
	set_last(s2.get_last());
	length = length + s2.get_length();
	set_sum(s2.get_sum());
	set_mean();

}