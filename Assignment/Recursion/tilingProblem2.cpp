#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1000000007;
void getResult(ll n, ll m, ll *count) {
    if (n==0) {

        *count=(*count%mod + 1)%mod;
        return;
    }
    if (n<0)
        return;
    getResult(n-1, m, count);
    getResult(n-m, m, count);
}
int main() {
    int t;
    cin>>t;
    while (t--) {
        ll count=0;
        ll n, m;
        cin>>n>>m;
        getResult(n, m, &count);
        cout<<count%mod<<'\n';
    }

}