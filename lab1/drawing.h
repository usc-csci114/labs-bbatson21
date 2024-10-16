#include "bmplib.h"
#include <string>
#include <vector>

#ifndef DRAWING_H
#define DRAWING_H

using namespace std; 

//Define your structs/classes in this file
struct ColorPixel { //finish this 
	uint8_t red, green, blue;
};

class ColorImage { //finish this 
	public:
		ColorImage(uint32_t xdim, uint32_t ydim); //constructor to initialize
		void setPixel(ColorPixel p, uint32_t x, uint32_t y);
		ColorPixel getPixel(uint32_t x, uint32_t y);
		void render(string filename);
			
	private:
		vector< vector<ColorPixel> > data;
}; 

struct Point {
	double x, y;
};

struct Line {
	Point start, end;
	ColorPixel c;
};

class Drawing {
	public:
		Drawing(); 
		void parse(string filename);
		void draw();
		void write(string filename);
	private:
		ColorImage image;
		vector<Line> lines;
};



#endif