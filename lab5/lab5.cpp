#include <iostream>
#include <chrono>
#include <vector>
#include <queue> 
#include <cstdlib>
#include <list>

void fillrand(std::vector<int>& v);

using namespace std;

int main(){
	//vector<int> v(100); 
	//fillrand(v); 
	//priority_queue<int> pq(v.begin(), v.end()); 
	
	//list<int> l; 
	//while(!pq.empty()){
	//	int next_item = pq.top(); 
	//	l.push_front(next_item); 
	//	pq.pop(); 
	//}
	//cout << "Unsorted list" << endl;
	//for(int i=0; i < 100; i++){
	//	cout << v[i] << endl; 
	//}
	//cout << "Sorted list" << endl; 
	//for(auto it = l.begin(); it != l.end(); ++it){
	//	cout << *it << endl; 
	//}

//modify code for while loop 

	int size = 2000000;
	for(int i = 1; i < 20;i++)
	{
		vector<int> v;
		v.resize(size*i);
		fillrand(v); 
		priority_queue<int> pq(v.begin(), v.end()); 
		const auto start = std::chrono::steady_clock::now();
		while(!pq.empty()){
			int next_item = pq.top(); 
			pq.pop(); 
		}
		const auto end = std::chrono::steady_clock::now();
		const std::chrono::duration<double> diff = end - start;
		cout << "Sorting for size" << v.size() << " " << diff.count() << endl; 
	}
	return 0; 	
}

void fillrand(std::vector<int>& v){
	for(int i=0; i < v.size(); i++){
		double val = rand(); 
		v[i] = val;  
	}
}