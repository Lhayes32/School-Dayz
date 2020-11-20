#ifndef LINES_H
#define LINES_H

#include "points.h"
using namespace ch2_p5_Leo_H;
namespace ch2_p6_Leo_H {
	class lines {
	public:
		lines(points p1, points p2) { po1 = p1; po2 = p2; };
		double find_line_segment();
	private:
		points po1;
		points po2;
		double distance;
	};
}






#endif
