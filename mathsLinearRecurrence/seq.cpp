#include <iostream>
#include <vector>
#define ll long long
#define pb push_back
#define MOD 1000000000
using namespace std;
vector <ll> a,b,c;
ll k;
vector<vector<ll> > multiply(vector<vector<ll>>K,vector<vector<ll>> L){
    //Matrix Multiplication
    vector<vector<ll> > sum(k+1,vector<ll>(k+1));
    for(int i = 1;i<=k;i++){
        for(int j = 1;j<=k;j++){
         for(int x = 1;x<=k;x++){
             sum[i][j] = (sum[i][j]+ (K[i][x]*L[x][j])%MOD)%MOD;
         }
        }
    }
    return sum;

}
vector<vector<ll>> pow(vector<vector<ll>> A,int p){
if(p==1){
    return A;
}
if(p&1){
    return multiply(A,pow(A,p-1));
}
vector<vector<ll> > X=pow(A,p/2);
return multiply(X,X); 

}
ll compute (ll n){
    if(n==0)
    return 0;
    if(n<=k){
        return b[n-1];
    }
    vector <ll> fi(k+1);
    for(int i = 1;i<=k;i++){
        fi[i] = b[i-1];
    }
    //matrix t
    vector<vector<ll>> T(k+1,vector<ll>(k+1));
    for(int i = 1;i<=k;i++){
        for(int j= 1;j<=k;j++){
            if(i<k){
                if(j==(i+1)){
                    T[i][j] = 1;
                }
                else
                T[i][j] = 0;

            }
            else{
                T[i][j] = c[k-j];
            }
        }
    }
    T = pow(T,n-1);
    ll res = 0;
    for(int i = 1;i<=k;i++)
    res = (res+(T[1][i]*fi[i])%MOD)%MOD;

    return res;

}

int main() {
    ll t,num,n;
    cin>>t;
    while(t--){
      cin>>k;
      for(int i = 0;i<k;i++){
          cin>>num;
          b.pb(num);
      }
      for(int i = 0;i<k;i++){
          cin>>num;
          c.pb(num);
      }
     cin>>n;
     cout<<compute(n)<<"\n";
     b.clear();
     c.clear();


    }
    return 0;
}
