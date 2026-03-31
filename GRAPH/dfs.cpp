#include<iostream>
#include<vector>
using namespace std;

vector<int> adj[100];
bool visited[100];

void dfs(int node) {
    visited[node] = true;
    cout << node << " ";

    for(int child : adj[node]) {
        if(!visited[child]) {
            dfs(child);
        }
    }
}

int main() {
    adj[1]={2,3};
    adj[2]={1,4};
    adj[3]={1};
    adj[4]={2};

    dfs(1);
}