int dp[100];

int coin(int n, int coins[]){
    dp[0] = 1;

    for(int i=0;i<n;i++){
        for(int j=coins[i]; j<=100; j++){
            dp[j] += dp[j - coins[i]];
        }
    }
}