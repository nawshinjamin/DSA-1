bool dfs(int node, int parent) {
    visited[node] = true;

    for(int child : adj[node]) {
        if(!visited[child]) {
            if(dfs(child, node)) return true;
        }
        else if(child != parent) {
            return true;
        }
    }
    return false;
}