#include <iostream>
#include <cmath>
#include <vector>

#include "bmplib.h"
#include "drawing.h"

//implement your classes in this file
//Point is given for the line drawing algorithm
struct Point {
	double x, y;
};

//adapted from https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
std::vector<Point> plotLine(Point start, Point end)
{
	int x0 = start.x;
	int y0 = start.y;
	int x1 = end.x;
	int y1 = end.y;
	
	int dx = abs(x1 - x0);
	int sx = x0 < x1 ? 1 : -1;
	int dy = -abs(y1 - y0);
	int sy = y0 < y1 ? 1 : -1;
	int error = dx + dy;
	
	std::vector<Point> line;
	
	while(true)
	{
		Point p = {x0, y0};
		line.push_back(p);
		if (x0 == x1 && y0 == y1) break;
		int e2 = 2 * error;
		if(e2 >= dy) {
			error = error + dy;
			x0 = x0 + sx;
		}
		if(e2 <= dx) {
			error = error + dx;
			y0 = y0 + sy;
		}
	}
	return line;
}

ColorImage::ColorImage(uint32_t xdim, uint32_t ydim){
    //need to initialize vector to make 2 dimensions
    data.resize(ydim); 
    for(size_t i = 0; i < data.size(); ++i){ //better practice to use ++i
        data[i].resize(xdim); 
    }
}

void ColorImage::setPixel(ColorPixel p, uint32_t x, uint32_t y){
	uint32_t ysize = data.size(); 
	uint32_t xsize = data[0].size(); 
	if(x < xsize && y < ysize){
		data[y][x] = p; 
	}
}

ColorPixel ColorImage::getPixel(uint32_t x, uint32_t y){
	uint32_t ysize = data.size(); 
	uint32_t xsize = data[0].size(); 
	if(x < xsize && y < ysize){
		return data[y][x]; 
	}
	throw std::range_error("bad size on getPixel"); 
}

void ColorImage::render(string filename){
//helppp
}

drawing::drawing(){
	//initialize lines? 
}

void drawing::parse(string filename){
	int xdim, ydim; 
	ifstream ifile(filename); 
	//check for errors 
	if(ifile.fail()){
		cout << "Could not open file" << endl; 
	}
	else{
		string line; 
		getline(ifile, line); 
		stringstream ss(line)
		ss >> xdim >> ydim; 
		image(xdim, ydim); 
		string line2; 
		int x1, y1, x2, y2; 
		int r, g, b; 
		while(getline(ifile, line2)){
			stringstream ss2(line2); 
			ss2 >> x1 >> y1 >> x2 >> y2 >> r >> g >> b; 
			Point p1; 
			Point p2; 
			ColorPixel col; 
			Line l; 
			p1.x = x1; 
			p1.y = y1; 
			p2.x = x2; 
			p2.y = y2; 
			col.red = r; 
			col.green = g; 
			col.blue = b; 
			l.start = p1; 
			l.end = p2; 
			l.c = col; 
			lines.push_back(l); 
		}
	}

	
}

void drawing::draw(){
	//how to use given function 
}
