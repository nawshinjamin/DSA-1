int parent[100];

int find(int x){
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void unite(int a, int b){
    a = find(a);
    b = find(b);

    if(a != b){
        parent[a] = b;
    }
} // DSU ( DISJOINT SET UNION)