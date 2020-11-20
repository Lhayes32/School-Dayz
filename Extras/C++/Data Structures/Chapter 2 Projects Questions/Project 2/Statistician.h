#ifndef STATISTICIAN_H
#define STATISTICIAN_H

namespace ch2_p2_Leo_H {
	class statistician 
	{
	public:
		statistician();
		void set_length();
		void set_last(double n);
		void next_number(double n);
		void set_sum(double n);
		void set_mean();
		void set_smallest(double n);
		void set_largest(double n);
		int get_length();
		double get_last();
		double get_sum();
		double get_mean();
		double get_smallest();
		double get_largest();
		void operator +(statistician s2);
		
		bool is_empty();

	private:
		int length;
		double sum;
		double last;
		double smallest;
		double largest;
		double mean;
	};


}


#endif