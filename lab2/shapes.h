#ifndef __SHAPES_H__
#define __SHAPES_H__
#include <vector>

//define our (virtual) base class
using namespace std;

struct Color {
	uint8_t r, g, b;
};

struct Point {
	uint32_t x, y;
};

struct BoundingBox {
	Point ul, br;
};

bool PointInTriangle(Point p, Point tri[3]); 

class Shape {
public:
	Shape(Color c);
	~Shape(); 
	void draw(uint8_t*** image, uint32_t h, uint32_t w);
	virtual bool inside(uint32_t x, uint32_t y) = 0;
	virtual BoundingBox getBoundingBox() = 0;
private:
	Color m_color;
};

//define a derived class for Triangle, Rectagle, and Circle
class Triangle : public Shape {
public:
	//What data does the constructor need?
	Triangle(Point t[3], Color c);
	~Triangle(); 
	bool inside(uint32_t x, uint32_t y); //we'll give you this code
	BoundingBox getBoundingBox(); //how do you get the bounding box for a triangle?
private:
	//what data structures do we need to describe a triangle?
	Point m_tri[3]; 
};

//Now follow this pattern and create a derived class for the Circle and Rectangle

class Circle : public Shape{
	public: 
		Circle(Point center, uint32_t r, Color c); 
		~Circle(); 
		bool inside(uint32_t x, uint32_t y);
		BoundingBox getBoundingBox(); 
	private: 
		Point m_center; 
		uint32_t m_radius; 
}; 

class Rectangle : public Shape{
	public: 
		Rectangle(uint32_t length, uint32_t width, Point center, Color c); 
		~Rectangle(); 
		bool inside(uint32_t x, uint32_t y); 
		BoundingBox getBoundingBox(); 
	private:
		Point m_center; 
		uint32_t m_l; 
		uint32_t m_w; 
};

#endif