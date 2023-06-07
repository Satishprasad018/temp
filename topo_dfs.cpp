4#include<iostream>
using namespace std ;
#include<vector>
#include<stack>

void dfs( vector<vector<int>>& graph,vector<bool>& visited,stack<int>& result, int vertex) //dfs function
{
    visited[vertex] = true;  // vertex ko visited kiya
    for (int neighbor : graph[vertex]) { //for loop vertex kk all adjacent ko visit
        if (!visited[neighbor]) {   // vertex ka neighbour ko visit kiya
            dfs(graph, visited, result, neighbor); // neighbour pe dfs run kiya
        }
    }
    result.push(vertex);// vertex ko result stack me push kiya
}

vector<int> topologicalSortDFS(vector<vector<int>>& graph, int V) { //topo function
    vector<bool> visited(V, false); // all vertex false denote kiya initially
    stack<int> result; //result stack initialize
    for (int i = 0; i < V; ++i) { //for loop all vertex ko visit kiya
        if (!visited[i]) {
            dfs(graph, visited, result, i);//dfs function ko call
        }
    }
    vector<int> topologicalOrder;//new vector initialize
    while (!result.empty()) { //jab tak result stack empty nahi ho jata
        topologicalOrder.push_back(result.top());//result ka top ko vector me push kiya
        result.pop();//result kk top ko remove kar diya
    }
    return topologicalOrder; // output vector
}
int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;
    vector<vector<int>> graph(V);
    cout << "Enter the edges (u, v):\n";
    int u, v;
    for (int i = 0; i < E; ++i) {
        cin >> u >> v;
        graph[u].push_back(v);//user se input liya
    }
    vector<int> topologicalOrderDFS = topologicalSortDFS(graph, V); //func call
    cout << "Enter the edges (u, v):";
    for (int vertex : topologicalOrderDFS) {
        cout << vertex << " ";  // output
    }
    return 0;
}
