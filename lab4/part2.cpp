#include <iostream>
#include <chrono>
#include <list>

using namespace std;

template <typename T>
T at(list<T>& ll, size_t idx)
{
	auto it = ll.begin();
	for(int i=0; i < idx; ++i){
		++it;  
	}
	return *it; 
	//implement an access-by-index for a linked list

	//1. Use auto to create an iterator for the list ll and set it to the .begin() iterator
	
	//2. Increment the iterator idx times
	
	//3. Return *it
}

int main(){
	size_t size = 1000;
	
	for(int x = 0; x < 20; x++)
	{
		list<int> my_list;
		my_list.resize(size * x); 
		//1. Resize my_list to have size*x items
		const auto start = std::chrono::steady_clock::now();
		//2. log the start time (see part 1)
		for(int i=0; i < my_list.size(); i++){
			at<int>(my_list, i); 
		}
		//3. Use a for loop to iterate through all indexs of my_list by calling 
		//   at<int>(my_list, i)
		const auto end = std::chrono::steady_clock::now();
		const std::chrono::duration<double> diff = end - start;
		//4. log the end time and calculate the diff
		cout << "Iterating linked list for size " << my_list.size() << ": ";
		cout << diff.count() << endl;
	}
}
