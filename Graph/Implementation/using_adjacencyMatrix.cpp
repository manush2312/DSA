#include<iostream>
#include<list>
using namespace std;

int main(){
    int n, m;
    cout << "Enter the number of Vertices: " << endl;
    cin >> n;
    cout << "Enter the number of Edges: " << endl;
    cin >> m;
    
    int g[n+1][n+1];   // declaring the matrix.. 


    // initialising all the elements as 0 in the matrix:
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            g[i][j] = 0;
        }
    }

    // taking the edges:
    cout << "Enter the edges: " << endl;
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        g[u][v] = 1;
        g[v][u] = 1;
    }

    // printing the matrix:
    for(int i=0; i<n; i++){
        cout << i << " --> ";
        for(int j=0; j<n; j++){
            cout << g[i][j] << " ";
        }
        cout << endl;
    }

}