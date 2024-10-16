#include <iostream>
#include <fstream>
#include <sstream>
#include "bmplib.h"
#include "drawing.h"

using namespace std;

int main(int argc, char* argv[])
{
	//use the structs/classes you defined in drawing.h to implement the program in this file
	//ColorImage test(100, 100); 
	//ColorPixel white = {255, 255, 255}; 
	//for(int i=0; i < 100; i++){
	//	for(int i=0; i<100; j++){
		//	test.setPixel(white, j, i); 
		//}
	//}

	string file = argv[1]; 
	Drawing drawing; 
	drawing.parse(file); 
	drawing.draw(); 
	drawing.write("output.bmp"); 


	return 0; 
}