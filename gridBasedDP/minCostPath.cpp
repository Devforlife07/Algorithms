#include <iostream>
using namespace std;
int getResult(int matrix[4][5]){
    int dp[100][100];
    memset(dp,0,sizeof(dp));
    for(int i = 0;i<4;i++){
        for(int j = 0;j<5;j++){
            if(i==0 and j==0)
            dp[i][j] = matrix[i][j];
            else if(i==0){
                dp[i][j]=dp[i][j-1]+matrix[i][j];
            }
            else if(j==0)
            dp[i][j] = dp[i-1][j]+matrix[i][j];
            else
            dp[i][j]=min(dp[i-1][j],dp[i][j-1])+matrix[i][j];
        }
    }
return dp[3][4];
}
int main() {
  int matrix[4][5]={ {1, 8, 8, 1, 5},  
                      {4, 1, 1, 8, 1},  
                      {4, 2, 8, 8, 1}, 
                      {1, 5, 8, 8, 1} };
  int ans = getResult(matrix);
  cout<<ans<<endl;                    
}
