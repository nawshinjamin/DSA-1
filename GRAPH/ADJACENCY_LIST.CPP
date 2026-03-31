#include<iostream>
#include<vector>
using namespace std;

vector<int> adj[100];

int main() {
    int n = 4;

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[2].push_back(3);
    adj[3].push_back(2);

    for(int i=1;i<=n;i++){
        cout << i << ": ";
        for(int x : adj[i]){
            cout << x << " ";
        }
        cout << endl;
    }
}