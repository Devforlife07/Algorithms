#include <bits/stdc++.h>
#define ll long long
using namespace std;
int pairExist(int *a, int s, int e, int key)
{
    // {   cout<<"Starting "<<s<<" "<<e<<endl;
    if (s > e)
        return -1;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (a[mid] == key)
            return mid;
        else if (a[mid] < key)
        {
            s = mid + 1;
        }
        else
            e = mid - 1;
    }
    return -1;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int *a = new int[n];
        int i = 0;
        while (i < n)
        {
            cin >> a[i];
            i++;
        }
        int amount;
        cin >> amount;
        sort(a, a + n);
        int ans = 0;
        int ans2 = 0;
        int diff = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            int index = pairExist(a, i + 1, n - 1, amount - a[i]);
            //    cout<<a[i]<<" "<<amount-a[i]<<" "<<index<<endl;

            // cout<<amount-a[i]<<" "<<index<<endl;
            // cout<<amount-a[i]<<" "<<index<<endl;
            // cout<<a[i]<<" "<<a[index]<<endl;
            if (index >= 0 and (abs(a[i] - a[index]) < diff))
            {
                // cout<<index<<" "<<a[index]<<endl;
                diff = abs(a[i] - a[index]);
                ans = a[i];
                ans2 = a[index];
            }
        }
        // cout << ans << ans + diff << endl;
        cout << "Deepak should buy roses whose prices are " << ans << " and " << ans2 << "." << endl;
    }

    return 0;
}