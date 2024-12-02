#include <iostream>
#include <chrono>
#include <vector>
#include <queue> 
#include <string>
#include <stack>
#include <sstream>

using namespace std; 

int main(){
    string input; 
    cout << "Enter a string containing brackets from <>, (), {}, []" << endl;
    getline(cin, input); 

    char c; 
    bool valid = true; 
    string test = input; 
    stringstream ss(test); 
    while(ss >> c){
        if(c != '<' && c!= '>' && c!= '(' && c!= ')' && c!='[' && c!= ']' && c!= '{' && c!= '}'){
            cout << "Invalid input" << endl; 
            valid = false; 
            break; 
        }
    }

    if(valid == false){
        return 0; 
    }

    char c2; 
    stack<char> chars; 

    for(int i=0; i < input.size(); i++){
        c2 = input[i]; 
        if(c2 == '<' || c2 == '(' || c2 == '[' || c2 == '{'){ 
            chars.push(c2); //push opening bracket onto stack 
        }
        else if(c2 == '>'){
            if(chars.top() == '<'){
                chars.pop();
            } 
            //else{
                //cout << "Error. Found " << c2 << " at position " << i << ", expecting " << '<'; 
               // cout << " Replace " << c2 << 
            //}
        } 
        else if (c2 == ')'){
            if(chars.top() == '('){
                chars.pop();
            } 
        }  
        else if(c2 == ']'){
            if(chars.top() == '['){
                chars.pop();
            } 
        }
        else if(c2 == '}'){
            if(chars.top() == '{'){
                chars.pop();
            } 
        }    
            
        }
        
    
    //end of string 
    if(!chars.empty()){
        cout << "Error. Unmatched open parens/brackets." << endl; 
    }
    else{
        cout << "All brackets are correct." << endl; 
    }
}