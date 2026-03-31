
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> adj[100];
bool visited[100];

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for(int child : adj[node]) {
            if(!visited[child]) {
                visited[child] = true;
                q.push(child);
            }
        }
    }
}

int main() {
    adj[1]={2,3};
    adj[2]={1,4};
    adj[3]={1};
    adj[4]={2};

    bfs(1);
}