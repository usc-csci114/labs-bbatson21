#include <iostream>
#include <set>
#include <fstream>
#include <map>
#include <sstream>
#include <queue>

using namespace std; 

int main(int argc, char* argv[]){
    ifstream ifile(argv[1]);
    string line; 

    map<char, set<char> > Graph;
    char row;  
 
    while(getline(ifile, line)){
        set<char> temp;
        stringstream ss(line);
        ss >> row;  
        //put rest of line in a set 
        char val; 
        while(ss >> val){
            if(val != '0'){
                temp.insert(val); 
            }
        }

        Graph[row] = temp;  
    }
    int row_cnt = Graph.size(); 
    cout << "Processed file " << argv[1] << ". Found " << row_cnt << " vertexes: ";
    for(auto it = Graph.begin(); it != Graph.end(); ++it){
        cout << it->first << " "; 
    }

    cout << endl; 

    cout << "Enter a starting vertex for BFS: " << endl;
    char v; 
    //map with key vertex, val bool 
    //if key is not visited
    while(cin >> v){
        if(v == 'q'){
            break; 
        }
        map<char, bool> Visited; 
        //initialize map 
        for(auto it = Graph.begin(); it != Graph.end(); ++it){
            Visited[it->first] = false; 
        }
        map<char, int> depth;  
        queue<char> q; 
        q.push(v); 
        depth[v] = 0; 
        Visited[v] = true; 
        while(! q.empty()){
            char curr = q.front(); 
            q.pop(); 
            for(auto it = Graph[curr].begin(); it != Graph[curr].end(); ++it){ //for all of neighbors 
                //access neighbors
                char neighb = *it;  
                if(!Visited[neighb]){
                    q.push(neighb); //add neighbor to queue 
                    Visited[neighb] = true; 
                    depth[neighb] = depth[curr] + 1; 
                }
            }
        }

        cout << "BFS starting at " << v << ": ";
        for(auto it = depth.begin(); it != depth.end(); ++it){
            cout << it->first << ":" << it->second << " ";
        }
        cout << endl; 


        cout << "Enter a starting vertex for BFS, or 'q' to quit" << endl; 
        

    }

    return 0; 
}