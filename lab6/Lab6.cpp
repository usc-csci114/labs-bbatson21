#include <iomanip>
#include <sstream>
#include <string>
#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib> 

using namespace std; 
int main(){
    vector<double> gpa_x(100); 
    vector<double> sat_y(100); 
    ifstream ifile("gpa_sat.csv"); 
    string line1; 
    getline(ifile, line1); 
    for(int i=0; i < 100; i++){
        string line; 
        getline(ifile, line);
        replace(line.begin(), line.end(), ',', ' '); 
        stringstream ss(line); 
        string x, y; 
        ss >> y >> x; 
        double x1 = stod(x); 
        double y1 = stod(y); 
        gpa_x[i] = x1;
        sat_y[i] = y1; 
    }
   
   //calculate mean of each 
   double gpa_mean; 
   double sat_mean; 

   double gpa_sum = 0; 
   double sat_sum = 0; 
   for(int i=0; i < gpa_x.size(); i++){
        gpa_sum += gpa_x[i]; 
        sat_sum += sat_y[i]; 
   }

   gpa_mean = gpa_sum / gpa_x.size(); 
   sat_mean = sat_sum / sat_y.size(); 

   cout << "gpa mean" << gpa_mean << endl; 
   cout << "sat mean" << sat_mean << endl; 

    //calculate beta and alpha 

    double beta; 
    double num = 0; 
    double denom = 0; 

    for(int i=0; i < gpa_x.size(); i++){
        double num_i, denom_i; 
        num_i = (gpa_x[i] - gpa_mean) * (sat_y[i] - sat_mean); 
        denom_i = (gpa_x[i] - gpa_mean) * (gpa_x[i] - gpa_mean); 

        num += num_i;
        denom += denom_i; 
    }

    beta = num / denom; 
    double alpha = sat_mean - (beta * gpa_mean); 

    vector<double> fi(100); 
    double ss_res = 0; 
    double ss_tot = 0; 

    for(int i=0; i < 100; i++){
        double f = alpha + (beta * gpa_x[i]); 
        fi[i] = f; 

        double sr, st; 
        sr = (sat_y[i] - f) * (sat_y[i] - f); 
        ss_res += sr; 
        st = (sat_y[i] - sat_mean) * (sat_y[i] - sat_mean); 
        ss_tot += st; 
    }

    double r_sq = 1 - (ss_res / ss_tot); 
    
    cout << "The model equation predicts: SAT score = " << alpha << " + " << beta << "*" << "GPA" << endl; 
    cout << "R squared value: " << r_sq << endl; 


}