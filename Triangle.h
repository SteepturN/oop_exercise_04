#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include <vector>
#include <utility>
#include <iostream>
#include <cmath>
#define NUM_OF_VERTECES_OF_TRIANGLE 3
class Triangle {
	public:
    std::vector<std::pair<double, double>> verteces;
    Triangle(Triangle& t);
    Triangle(Triangle&& t);
    Triangle();
	std::pair<double, double> center() const noexcept;
	void coordinates() const noexcept;
	double area() const noexcept;
	Triangle& operator=(const Triangle& t);
	bool operator==(const Triangle& t);
	friend std::ostream& operator<<(std::ostream& cout, Triangle& t);
	friend std::istream& operator>>(std::istream& cin, Triangle& t);
};

#endif // TRIANGLE_H_
