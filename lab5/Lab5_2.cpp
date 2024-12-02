#include <iostream>
#include <chrono>
#include <vector>
#include <queue> 
#include <string>
#include <stack>

using namespace std; 

int main(){
    //task 1a
    int input; 
    vector<int> values; 
    cout << "Enter values, ctrl-d to quit" << endl; 
    while(cin >> input){ 
        values.push_back(input); 
    }

    cout << "Printing in order" << endl; 
    for(int i=0; i < values.size(); i++){
        cout << values[i] << endl; 
    }

    stack<int> ordered; 
    stack<int> reverse; 
    for(int i=0; i < values.size(); i++){
        ordered.push(values[i]); 
    }

    //reverse the order
    cout << "Printing reverse order" << endl; 
    for(int i=0; i < values.size(); i++){
        reverse.push(ordered.top()); 
        cout << ordered.top() << endl; 
        ordered.pop(); 
    }

}