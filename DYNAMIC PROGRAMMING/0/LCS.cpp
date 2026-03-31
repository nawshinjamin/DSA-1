int dp[100][100];

int lcs(string s, string t, int n, int m){
    if(n==0 || m==0) return 0;

    if(dp[n][m] != -1) return dp[n][m];

    if(s[n-1] == t[m-1]){
        return dp[n][m] = 1 + lcs(s, t, n-1, m-1);
    }
    else{
        return dp[n][m] = max(
            lcs(s, t, n-1, m),
            lcs(s, t, n, m-1)
        );
    }
}