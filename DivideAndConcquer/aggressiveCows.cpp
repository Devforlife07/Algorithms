#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool isSafe(ll *a, ll n, ll mid, ll c) {
    ll count = 1;
    ll last = a[0];
    for (int i = 1;i<n;i++) {
        if (a[i]-last>=mid) {
            last = a[i];
            count++;
            if (count==c)
                return true;
        }
    }
    return false;

}
int main() {
    int t;
    cin>>t;
    while (t--) {
        ll n, c;
        cin>>n>>c;
        ll a[100009];
        int i = 0;
        while (i<n) {
            ll temp;
            cin>>temp;
            a[i] = temp;
            i++;
        }
        sort(a, a+n);
        ll s = 0;
        ll e = a[n-1]-a[0];
        ll ans = 0;
        while (s<=e) {
            int mid = (s+e)/2;
            if (isSafe(a, n, mid, c)) {
                ans = mid;
                s=mid+1;
            }
            else {
                e=mid-1;
            }
        }
        cout<<ans<<'\n';

    }
    return 0;
}