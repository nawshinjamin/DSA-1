#include<iostream>
#include<cstring>

using namespace std;

const int MAX = 5005;

int dp[MAX][MAX];
char S[MAX] , T[MAX];
int I,D,R;

void print(int i, int j){
    if(i==0 && j==0){
        return;
    }
    if(i == 0){
    print(i, j-1);
    cout << "Insert " << T[j-1] << endl;
    return;
}

if(j == 0){
    print(i-1, j);
    cout << "Delete " << S[i-1] << endl;
    return;
}

    if(S[i-1] == T[j-1] && dp[i][j] == dp[i-1][j-1]){
        print(i-1 , j-1);
        cout << "Match " << S[i-1] << endl;
    }
else if(dp[i][j] == dp[i][j-1] + I ){
    print(i , j-1);
    cout << "Insert " << T[j-1] << endl;
}
else if( dp[i][j] == dp[i-1][j] + D){
    print(i-1, j);
cout << "Delete " << S[i-1] << endl;
}
else if(dp[i][j] == dp[i-1][j-1] + R){
        print(i-1, j-1);
        cout << "Replace " << S[i-1] << " with " << T[j-1] << endl;
    }
    
}


int main(){
cin >> I >> D >> R;
cin.ignore();
cin.getline(S,MAX);
cin.getline(T,MAX);

int l1 = strlen(S);
int l2 = strlen(T);

for(int x=0; x<=l1; x++){
    dp[x][0] = x * D;
}
for(int y=0; y<=l2; y++){
    dp[0][y] = y *I;
}

for(int i=1; i<=l1; i++){
    for(int j=1; j<=l2; j++){
        if(S[i-1] == T[j-1]){
dp[i][j] = dp[i-1][j-1];
        }
        else{
            int insertCost = dp[i][j-1] + I;
            int deleteCost = dp[i-1][j] + D;
            int replaceCost = dp[i-1][j-1] + R;

            dp[i][j] = insertCost;
            if(deleteCost < dp[i][j])
            dp[i][j] = deleteCost;
            if(replaceCost < dp[i][j])
            dp[i][j] = replaceCost;
        }

    }

}

cout << "Minimum Cost : " << dp[l1][l2] << endl;
cout << "Operations : " << endl;
print(l1, l2);
return 0;
}