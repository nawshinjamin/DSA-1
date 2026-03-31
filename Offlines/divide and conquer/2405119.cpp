#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

const int MAXNUMBER = 100000;

struct city {
    int id;
    double x, y;
};

struct edge {
    int city1Id;
    int city2Id;
    double cost;
};

city cities[MAXNUMBER];
city temp[MAXNUMBER];
edge finalEdges[MAXNUMBER];

vector<int> adj[MAXNUMBER];
bool visited[MAXNUMBER];

int edgeCount = 0;
double costTotal = 0;
int N , M;;


double distance_between_cities(city city1, city city2) {
    double dx = city1.x - city2.x;
    double dy = city1.y - city2.y;
    double d = sqrt(dx*dx + dy*dy);
    return d;
}


void search_dfs(int node) {
    visited[node] = true;

    for(int i = 0; i < adj[node].size(); i++) {
        int next = adj[node][i];
        if(!visited[next])
            search_dfs(next);
    }
}

bool isConnected(int node1, int node2) {

    for(int i = 0; i < N + 1; i++)
        visited[i] = false;

    search_dfs(node1);

    return visited[node2];
}


void merge(int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;

    while(i <= mid && j <= right) {
        if(cities[i].x <= cities[j].x)
            temp[k++] = cities[i++];
        else
            temp[k++] = cities[j++];
    }

    while(i <= mid) temp[k++] = cities[i++];
    while(j <= right) temp[k++] = cities[j++];

    for(int l = left; l <= right; l++)
        cities[l] = temp[l];
}

void mergeSort(int left, int right) {
    if(left >= right) return;
    int mid = (left + right) / 2;
    mergeSort(left, mid);
    mergeSort(mid + 1, right);
    merge(left, mid, right);
}


void soln_BaseCase(int left, int right) {

    vector<edge> edges;

   
    for(int i = left; i <= right; i++)
        adj[cities[i].id].clear();

  
    for(int i = left; i <= right; i++) {
        for(int j = i + 1; j <= right; j++) {
            edge e;
            e.city1Id = cities[i].id;
            e.city2Id = cities[j].id;
            e.cost = distance_between_cities(cities[i], cities[j]);
            edges.push_back(e);
        }
    }

    int neededEdges = (right - left);
    int count = 0;

    while(count < neededEdges) {

        double best = 1e18;
        int bestIndex = -1;

        
        for(int i = 0; i < edges.size(); i++) {
            if(edges[i].cost < best) {
                best = edges[i].cost;
                bestIndex = i;
            }
        }

        int city1 = edges[bestIndex].city1Id;
        int city2 = edges[bestIndex].city2Id;

        
        if(!isConnected(city1, city2)) {

            adj[city1].push_back(city2);
            adj[city2].push_back(city1);

            finalEdges[edgeCount++] = edges[bestIndex];
            costTotal += edges[bestIndex].cost;

            count++;
        }

        
        edges[bestIndex].cost = 1e18;
    }
}


void final_connect(int left, int right) {

    int size = right - left + 1;

    if(size <= M) {
        soln_BaseCase(left, right);
        return;
    }

    int mid = (left + right) / 2;

    final_connect(left, mid);
    final_connect(mid + 1, right);

    
    double best = 1e18;
    edge bestEdge;

    int leftStart = mid - M + 1;
    if(leftStart < left)
        leftStart = left;

    int rightEnd = mid + M;
    if(rightEnd > right)
        rightEnd = right;

    for(int i = leftStart; i <= mid; i++) {
        for(int j = mid + 1; j <= rightEnd; j++) {

            double d = distance_between_cities(cities[i], cities[j]);

            if(d < best) {
                best = d;
                bestEdge.city1Id = cities[i].id;
                bestEdge.city2Id = cities[j].id;
                bestEdge.cost = d;
            }
        }
    }

    finalEdges[edgeCount++] = bestEdge;
    costTotal += bestEdge.cost;
}


int main() {

    cin >> N >> M;

    for(int i = 0; i < N; i++)
        cin >> cities[i].id >> cities[i].x >> cities[i].y;

    mergeSort(0, N - 1);

    final_connect(0, N - 1);

    double rounded = (int)(costTotal * 100 + 0.5) / 100.0;

    cout << "Total Cost: " << rounded << endl;
    cout << "Edges:" << endl;

    for(int i = 0; i < edgeCount; i++)
        cout << finalEdges[i].city1Id << " "
             << finalEdges[i].city2Id << endl;

    return 0;
}