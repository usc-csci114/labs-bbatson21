#include <iostream>
#include "bmplib.h"
#include "shapes.h"

using namespace std;

uint8_t*** newImage(uint8_t bground[3], uint32_t h, uint32_t w)
{
	uint8_t*** img = new uint8_t**[h];
	for(int r=0; r < h; r++) {
		img[r] = new uint8_t*[w];
		for(int c = 0; c < w; c++) {
			img[r][c] = new uint8_t[3];
			img[r][c][0] = bground[0];
			img[r][c][1] = bground[1];
			img[r][c][2] = bground[2];
		}
	}
	return img;
}

int main(int argc, char* argv[])
{
	uint8_t bg[] = {255,255,255};
	uint8_t*** image = newImage(bg, 1024, 1024);
	
	//add your code here
	
	//ask the user what shape the want to draw
	//collect the required information
	//instantiate the shape, draw it into the image
	//loop and ask for another shape, "quit" to stop
	//Point p1 = {10, 10}; 
	//Point p2 = {110, 10}; 
	//Point p3 = {110, 110}; 
	//Point points[3] = {p1, p2, p3}; 
	Color red = {255,0,0}; 
	//Triangle tri(points, red); 
	//tri.draw(image, 1024, 1024); 

	Color blue = {0,0,255}; 
	//Point center = {512,512}; 
	//int rad = 200; 
	//Circle circle(center, rad, blue); 
	//circle.draw(image, 1024, 1024); 

	Color green = {0, 255, 0}; 
	Point center1 = {400, 600}; 
	int length = 400; 
	int width = 500; 
	Rectangle rect(length, width, center1, green); 
	rect.draw(image, 1024, 1024); 

	string input; 
	while(true){
		cout << "Would you like to draw a Triangle, Circle, or Rectangle?" << endl; 
		cin >> input; 
		if(input == "Quit"){
			break; 
		}
		else if(input == "Triangle"){
			Point p1, p2, p3;
			uint32_t x1, y1, x2, y2, x3, y3; 
			cout << "Enter the coordinates of the 3 points of the triangle:" << endl; 
			cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3; 
			p1.x = x1; 
			p1.y = y1; 
			p2.x = x2; 
			p2.y = y2; 
			p3.x = x3; 
			p3.y = y3; 
			Point points[3] = {p1, p2, p3}; 
			Triangle tri(points, red); 
			tri.draw(image, 1024, 1024); 
		}
		else if(input == "Rectangle"){
			int length, width; 
			Point center; 
			uint32_t r_x, r_y; 
			cout << "Enter the length and width of the rectangle: " << endl; 
			cin >> length >> width; 
			cout << "Enter the x and y coordinates of the center: " << endl; 
			cin >> r_x >> r_y; 
			center.x = r_x; 
			center.y = r_y; 
			Rectangle rect(length, width, center, green); 
			rect.draw(image, 1024, 1024); 
		}
		else if(input == "Circle"){
			Point center; 
			uint32_t c_x, c_y; 
			int radius; 
			cout << "Enter the radius of the circle: " << endl; 
			cin >> radius; 
			cout << "Enter the x and y coordinates of the center: " << endl; 
			cin >> c_x >> c_y; 
			center.x = c_x; 
			center.y = c_y; 
			Circle circle(center, radius, blue); 
			circle.draw(image, 1024, 1024); 
		}
		else{
			cout << "Invalid input. Try again." << endl; 
		}
	}
	
	writeRGBBMP("output.bmp", image, 1024, 1024);
}
