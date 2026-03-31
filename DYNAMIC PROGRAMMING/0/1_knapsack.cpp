int dp[100][100];

int knapsack(int n, int W, int wt[], int val[]){
    if(n==0 || W==0) return 0;

    if(dp[n][W] != -1) return dp[n][W];

    if(wt[n-1] <= W){
        return dp[n][W] = max(
            val[n-1] + knapsack(n-1, W-wt[n-1], wt, val),
            knapsack(n-1, W, wt, val)
        );
    }
    else{
        return dp[n][W] = knapsack(n-1, W, wt, val);
    }
}