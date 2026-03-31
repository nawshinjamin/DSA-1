#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> adj[100];

void dijkstra(int src){
    vector<int> dist(100, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while(!pq.empty()){
        auto [d, node] = pq.top();
        pq.pop();

        for(auto [child, weight] : adj[node]){
            if(dist[node] + weight < dist[child]){
                dist[child] = dist[node] + weight;
                pq.push({dist[child], child});
            }
        }
    }
}