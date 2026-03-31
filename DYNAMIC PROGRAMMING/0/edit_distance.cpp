int dp[100][100];

int editDist(string s, string t, int n, int m){
    if(n==0) return m;
    if(m==0) return n;

    if(dp[n][m] != -1) return dp[n][m];

    if(s[n-1] == t[m-1]){
        return dp[n][m] = editDist(s,t,n-1,m-1);
    }

    return dp[n][m] = 1 + min({
        editDist(s,t,n,m-1),   // insert
        editDist(s,t,n-1,m),   // delete
        editDist(s,t,n-1,m-1)  // replace
    });
}