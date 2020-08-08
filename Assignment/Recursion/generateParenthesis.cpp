#include <bits/stdc++.h>
using namespace std;
void getResult(char *out, int n, int i, int j, int open, int close) {
    if (i==2*n) {
        out[j]='\0';
        cout<<out<<'\n';
        return;
    }
    if (open<n) {
        out[j]='(';
        getResult(out, n, i+1, j+1, open+1, close);
    }
    if (close<open) {
        out[j]=')';
        getResult(out, n, i+1, j+1, open, close+1);
    }

}
int main() {
    int n;
    cin>>n;
    char out[1000];
    getResult(out, n, 0, 0, 0, 0);
}