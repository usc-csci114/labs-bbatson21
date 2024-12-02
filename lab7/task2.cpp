#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <matplot/matplot.h>

using namespace matplot;
//using namespace std; 
int main() {
	
	std::ifstream ifile("atmosphere.txt");
	std::string line;
	std::vector<double> p, h, t;
	//follow the lab instructions to generate task1.png, task2a.png and task2b.png

	for(int i=0; i < 4; i++){
		getline(ifile, line); 
	}

	while(getline(ifile, line)){ 
		std::stringstream ss(line); 
		double pr, hi, te; 
		for(int i=0; i < 3; i++){
			if(i == 0){
				ss >> pr;
			}
			else if(i == 1){
				ss >> hi; 
			}
			else if(i == 2){
				ss >> te;
			}
		}
		p.push_back(pr);
		h.push_back(hi);
		t.push_back(te); 
	}

	double t_min = *std::min_element(t.begin(), t.end());
	double t_max = *std::max_element(t.begin(), t.end());
	 
	plot(h, p, "-o");
	xlabel("Pressure hPa"); 
	ylabel("Height (meters)");
	hold(on);
	plot(h, t, "-rx")->use_y2(true);
	y2lim({t_min, t_max});
	y2label("Temperature (C)"); 
	show(); 
	save("task2a_1.png");

	
	return 0;
}
