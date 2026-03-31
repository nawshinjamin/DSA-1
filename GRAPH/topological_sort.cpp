#include<stack>

vector<int> adj[100];
bool visited[100];
stack<int> st;

void topo(int node){
    visited[node] = true;

    for(int child : adj[node]){
        if(!visited[child]){
            topo(child);
        }
    }
    st.push(node);
}
