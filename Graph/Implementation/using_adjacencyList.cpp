#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

class Graph{
    public:
    unordered_map<int, list<int> > adj; // creation of unordered_map 

    void addEdge(int u, int v, bool direction){
        // direction = 0 --> undirected 
        // direction = 1 --> directed 

        // create an edge from u to v
        adj[u].push_back(v);

        if(direction == 0){   // because undirected graph..
            adj[v].push_back(u);  
        }
    }

    // printing adjacency list:
    void printAdjList(){
        for(auto i : adj){
            cout << i.first << " --> ";
            for(auto j : i.second){
                cout << j << ",";
            }
            cout << endl;
        }
    }
};

int main(){
    int m, n;
    cout << "Enter the number of Nodes:" << endl;
    cin >> n;
    cout << "Enter the number of edges:" << endl;
    cin >> m;

    Graph g ;  // creation of a graph.. basically creating an object of class Graph..

    // taking edges:
    cout << "Provide the " << m << " edges:" << endl;
    for(int i=0; i<m; i++){
        int u,v;
        cin >> u >> v;

        // creating an undirescted graph..
        g.addEdge(u,v,0);
    }

    // printing the Graph:
    g.printAdjList();


    return 0;
}