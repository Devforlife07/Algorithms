#include <iostream>
using namespace std;
#define ll long long
ll getResult(int i, int n) {
    if (n==0)
        return 1;
    if (n<0)
        return 0;
    ll count = 0;
    count+= getResult(i, n-1);
    count+= (n-1)*getResult(i, n-2);
    return count;


}
int main() {
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        cout<<getResult(0, n)<<'\n';
    }
}