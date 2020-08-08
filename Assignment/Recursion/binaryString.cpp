#include <bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin>>t;
    while (t--) {
        int dp[10000][2]={ 0 };
        dp[1][0]=1;
        dp[1][1]=1;
        int count = 0;
        int n;
        cin>>n;
        int i=2;
        while (i<=n) {
            dp[i][0]=dp[i-1][0]+dp[i-1][1];
            dp[i][1]=dp[i-1][0];
            i++;
        }
        cout<<dp[n][0]+dp[n][1]<<'\n';
    }
    return 0;
}