nt count = 0;

for(int i=1;i<=n;i++){
    if(!visited[i]){
        dfs(i);
        count++;
    }
}