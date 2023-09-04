#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

class Graph{
    public:
    unordered_map<int, list<int> >adj;
    vector<int> ans;  // creating the answer array..
    unordered_map<int, bool> visited;  // visited array..

    void addEdge(int u, int v, int direction){
        adj[u].push_back(v);

        if (direction == 0){
            adj[v].push_back(u);
        }
    }

   vector<int> BFS(int n){
        for(int i=0; i<n; i++){
            if(!visited[i]){
                bfs(i);
            }
        }

        return ans;
   }

    void bfs(int node){
        queue<int> q;
        q.push(node);
        visited[node] = 1; // marking node as visited..

        while(!q.empty()){
            int frontNode = q.front(); // storing the front node.. 
            q.pop();
            
            // storing the front node into the answer..
            ans.push_back(frontNode);

            // traversing the adjacent nodes..
            for(auto i : adj[frontNode]){
                if(!visited[i]){
                    q.push(i);
                    visited[i] = 1;
                }
            }
        }
    }

    void printBFSans(){
        cout << "BFS Traversal is: " << endl;
        for(auto i : ans){
            cout << i << "  ";
        }
        cout << endl;
    }


};

int main(){
    int m,n;
    cout << "Enter the number of Vertices: " << endl;
    cin >> n;
    cout << "Enter the number of Edges: " << endl;
    cin >> m;

    Graph g;

    cout << "Enter the edges: " << endl;
    for(int i=0; i<m; i++){
        int u,v;
        cin >> u >> v;

        g.addEdge(u,v,0);

    }

    g.BFS(n);

    g.printBFSans();
    



    return 0;
}