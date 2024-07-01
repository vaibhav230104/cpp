#include <unordered_map>

#include <list>

#include <vector>

using namespace std;

 

void dfs(int node, int parent, int &timer, vector<int> &disc, vector<int> &low,

         unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj, vector<int> &ap) {

 

    visited[node] = true;

    disc[node] = low[node] = timer++;

    int child = 0;
 

    for (auto nbr : adj[node]) {

        if (nbr == parent)

            continue;

 

        if (!visited[nbr]) {

            dfs(nbr, node, timer, disc, low, visited, adj, ap);

            low[node] = min(low[node], low[nbr]);

 

            // check if edge is bridge

            if (low[nbr] >= disc[node]  &&  parent!=-1) {
                
                ap[node] = true;

            }
            child++;

        } else {

            // back-edges

            low[node] = min(low[node], disc[nbr]);

        }

    }
    if(parent == -1 && child > 1){
        ap[node] = 1;
    }

}

 

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {

    // create an adjList

    unordered_map<int, list<int>> adj;

 

    for (int i = 0; i < edges.size(); i++) {

        int u = edges[i][0];

        int v = edges[i][1];

 

        adj[u].push_back(v);

        adj[v].push_back(u);

    }

 

    int timer = 0;

    vector<int> disc(v);

    vector<int> low(v);

 

    int parent = -1;

    unordered_map<int, bool> visited;
    vector<int> ap(v,0);

 

    //initializing

    for (int i = 0; i < v; i++) {

        disc[i] = -1;

        low[i] = -1;

        visited[i] = false;

    }

 

    // do dfs

    // vector<vector<int>> result;

 

    for (int i = 0; i < v; i++) {

        if (!visited[i]) {

            dfs(i, parent, timer, disc, low, visited, adj, ap);

        }

    }

 

    return result; // Add this return statement

}
