#include <vector>
#include <utility>
#include <iostream>
#include <cmath>

#include "Triangle.h"

Triangle::Triangle(Triangle& t)
	: verteces(t.verteces) {}
Triangle::Triangle(Triangle&& t)
	: verteces(t.verteces) {}

Triangle::Triangle()
	: verteces(std::vector<std::pair<double, double>>(3)) {}
Triangle& Triangle::operator=(const Triangle& t) {
	for(int i = 0, j = 0; i < NUM_OF_VERTECES_OF_TRIANGLE; i++, j++) {
		verteces[i] = t.verteces[i];
	}
	return *this;
}
bool Triangle::operator==(const Triangle& t) {
	bool result = true;
	for(int i = 0, j = 0; i < NUM_OF_VERTECES_OF_TRIANGLE; i++, j++) {
		if(verteces[i] != t.verteces[i]) result = false;
	}
	return result;
}
std::ostream& operator<<(std::ostream& cout, Triangle& t) {
	cout << "triangle: \nsides length:\t";
	for(int i = 0; i < NUM_OF_VERTECES_OF_TRIANGLE; ++i) {
		auto v1 = t.verteces[i-1<0?NUM_OF_VERTECES_OF_TRIANGLE:i-1];
		auto v2 = t.verteces[i];
		cout << sqrt(pow(v1.first-v2.first,2)+pow(v1.second-v2.second, 2)) << '\t';
	}
	cout << '\n' << "coordinates: ";
	for(int i = 0; i < NUM_OF_VERTECES_OF_TRIANGLE; ++i)
		cout << '(' << t.verteces[i].first << ", " << t.verteces[i].second << ")\n";
	return cout;
}

std::istream& operator>>(std::istream& cin, Triangle& t) {
	char ch(' ');
	Triangle copy;
	copy = t;
	for(int i = 0, j = 0; i < NUM_OF_VERTECES_OF_TRIANGLE*2; ++i, j=(j+1)%2) {
		while((ch == '\t') || (ch == ' ') || (ch == '\n')) {
			cin >> ch;
			if(cin.eof()) {
				cin.unget(); //?
				cin.setstate(std::ios_base::failbit);
				t = copy;
				return cin;
			}
		}
		cin.unget();
		if(j == 0)
			cin >> t.verteces[i].first;
		else
			cin >> t.verteces[i].second;
		if(cin.fail()) {
			t = copy;
			return cin;
		}
	}
	return cin;
}

std::pair<double, double> Triangle::center() const noexcept{
	std::pair<double, double> _center(0, 0);
	for(int i = 0; i < NUM_OF_VERTECES_OF_TRIANGLE; ++i) {
		_center.first+=verteces[i].first;
		_center.second+=verteces[i].second;
	}
	_center.first/=NUM_OF_VERTECES_OF_TRIANGLE;
	_center.second/=NUM_OF_VERTECES_OF_TRIANGLE;
	return _center;
}
void Triangle::coordinates() const noexcept {
	for(int i = 0; i < NUM_OF_VERTECES_OF_TRIANGLE; ++i)
		std::cout << '(' << verteces[i].first << ", " << verteces[i].second << ')';
}
double Triangle::area() const noexcept {
	double area(0);
	for(int i = 0; i< NUM_OF_VERTECES_OF_TRIANGLE; ++i) {
		area+=	verteces[i].first	*	verteces[(i+1)%NUM_OF_VERTECES_OF_TRIANGLE].second	-	\
			verteces[(i+1)%NUM_OF_VERTECES_OF_TRIANGLE].first	*	verteces[i].second;
	}
	area/=2;
	return area<0?-area:area;
}
