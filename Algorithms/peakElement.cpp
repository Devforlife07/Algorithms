#include <bits/stdc++.h>
using namespace std;
int getResult(int a[],int s,int e,int n){
    if(n==1)
    return 0;
    int mid = (s+e)/2;
    if(mid==0 and a[mid]>=a[mid+1]||a[mid-1]<=a[mid] and mid==n-1||a[mid+1]<=a[mid])
    return mid;
    if(mid>0 and a[mid-1]> a[mid])
    return getResult(a,s,mid-1,n);

    return getResult(a,mid+1,e,n);

}
int main() {
    int a[] = {10,15,20, 2, 23, 90, 67};
     int n = sizeof(a)/sizeof(a[0]);
    int ans = getResult(a,0,n-1,n);
    cout<<ans<<'\n';

   
}
