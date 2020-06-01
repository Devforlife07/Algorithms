#include <bits/stdc++.h>
using namespace std;
int getResult(int a,int n){
    if(n==0)
    return 1;
    int subproblem = getResult(a,n/2);
    if(n&1){
        return a*(subproblem*subproblem);
    }
    else
    return subproblem*subproblem;
}

int main() {
	// your code goes here
	int a,n;
	cin>>a>>n;
	int ans = getResult(a,n);
	cout<<ans<<"\n";
	return 0;
}
