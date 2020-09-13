#include <bits/stdc++.h>
using namespace std;
bool getResult(int *a, bool *taken, int subset, int *subsetSum, int k, int n, int i, int limit) {
    if (subsetSum[i]==subset) {
        if (i==k-2)
            return true;
        return getResult(a, taken, subset, subsetSum, k, n, i+1, n-1);
    }
    for (int j = limit;j>=0;j--) {
        if (taken[j])
            continue;
        int tmp = subsetSum[i]+a[j];
        if (tmp<=subset) {
            subsetSum[i]+=a[j];
            taken[j]= true;
            bool next = getResult(a, taken, subset, subsetSum, k, n, i, j-1);
            taken[j] = false;
            subsetSum[i]-=a[j];
            if (next)
                return true;

        }
    }
    return false;

}
bool isPartitionPossible(int *a, int n, int k) {
    if (k==1)
        return true;
    if (n<k)
        return false;
    int sum = 0;
    for (int i = 0;i<n;i++) {
        sum+=*(a+i);
    }
    if (sum%k!=0) {
        return false;
    }
    int subset = sum/k;
    int subsetSum[k];
    bool taken[n];
    for (int i = 0;i<n;i++)
        taken[i] = false;
    for (int i = 0;i<k;i++)
        subsetSum[i]=0;
    subsetSum[0]=a[n-1];
    taken[n-1] = true;
    return getResult(a, taken, subset, subsetSum, k, n, 0, n-1);

}
int main() {
    int n;
    cin>>n;
    int *a = new int[n];

    int k;
    cin>>k;
    int i = 0;
    int temp;
    while (i<n) {
        cin>>temp;
        a[i]= temp;
        i++;
    }
    if (isPartitionPossible(a, n, k))
        cout<<"Yes Partition Possible"<<'\n';
    else
        cout<<"No Partition Not Possible"<<'\n';
    return 0;

}