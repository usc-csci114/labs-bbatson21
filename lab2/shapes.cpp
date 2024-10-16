#include "shapes.h"
#include <algorithm>
#include <cmath>


Shape::Shape(Color c){
    m_color = c; 
}

void Shape::draw(uint8_t*** image, uint32_t h, uint32_t w){ //input 
    BoundingBox bb = getBoundingBox(); 
    for(int r = bb.ul.y; r < bb.br.y; r++){
        for(int c = bb.ul.x; c < bb.br.x; c++){
            if(inside(c,r)){
                image[r][c][0] = m_color.r;
                image[r][c][1] = m_color.g;
                image[r][c][2] = m_color.b; 
            }
        }
    }
}

Shape::~Shape() {}


//Implement your shapes here
Triangle::Triangle(Point t[3], Color c) : Shape(c)
{
    m_tri[0] = t[0]; 
    m_tri[1] = t[1]; 
    m_tri[2] = t[2]; 
}

Triangle::~Triangle() {}

BoundingBox Triangle::getBoundingBox()
{
    BoundingBox b; 
    b.ul.x = min(min(m_tri[0].x, m_tri[1].x), m_tri[2].x); 
    b.ul.y = min(min(m_tri[0].y, m_tri[1].y), m_tri[2].y); 

    b.br.x = max(max(m_tri[0].x, m_tri[1].x), m_tri[2].x); 
    b.br.y = max(max(m_tri[0].y, m_tri[1].y), m_tri[2].y); 

    //find min x and min y (ul) and max x and max y (br)
    


    return b; 
}

bool Triangle::inside(uint32_t x, uint32_t y)
{
    Point p = {x, y}; 
    return PointInTriangle(p, m_tri); 
}

bool PointInTriangle(Point p, Point tri[3])
{
	int s = (tri[0].x - tri[2].x) * (p.y - tri[2].y) - (tri[0].y - tri[2].y) * (p.x - tri[2].x);
	int t = (tri[1].x - tri[0].x) * (p.y - tri[0].y) - (tri[1].y - tri[0].y) * (p.x - tri[0].x);

	if ((s < 0) != (t < 0) && s != 0 && t != 0)
		return false;

	int d = (tri[2].x - tri[1].x) * (p.y - tri[1].y) - (tri[2].y - tri[1].y) * (p.x - tri[1].x);
	return d == 0 || (d < 0) == (s + t <= 0);
}

Circle::Circle(Point center, uint32_t r, Color c) : Shape(c)
{
    m_center = center; 
    m_radius = r; 
}

Circle::~Circle() {}

BoundingBox Circle::getBoundingBox()
{
    BoundingBox b; 
    b.ul.x = m_center.x - m_radius; 
    b.ul.y = m_center.y - m_radius; 

    b.br.x = m_center.x + m_radius; 
    b.br.y = m_center.y + m_radius; 

    return b; 
}

bool Circle::inside(uint32_t x, uint32_t y)
{
    double dx = x; 
    double dy = y; 
    double distance = sqrt( (m_center.x - dx)*(m_center.x - dx) + (m_center.y - dy)*(m_center.y - dy) ); 
    return distance < m_radius; 
}

//try a rectangle 

Rectangle::Rectangle(uint32_t length, uint32_t width, Point center, Color c) : Shape(c)
{ 
    m_l = length; 
    m_w = width; 
    m_center = center;
}

Rectangle::~Rectangle() {}

BoundingBox Rectangle::getBoundingBox()
{
    BoundingBox b; 
    b.ul.x = m_center.x - (m_w / 2); 
    b.ul.y = m_center.y - (m_l / 2); 
    b.br.x = m_center.x + (m_w / 2); 
    b.br.y = m_center.y + (m_l / 2); 

    return b; 
}

bool Rectangle::inside(uint32_t x, uint32_t y){
    return (x >= m_center.x - (m_w / 2) && x <= m_center.x + (m_w / 2)) && 
           (y >= m_center.y - (m_l / 2) && y <= m_center.y + (m_l / 2)); 
}