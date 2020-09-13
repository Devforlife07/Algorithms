#include <iostream>
using namespace std;
int getResult(int *a, int n, int s, int e, int key)
{
    if (s == e)
        return s;
    if (s > e)
        return -1;
    int mid = (s + e) / 2;
    if (a[mid] == key)
        return mid;
    else if (a[s] <= a[mid])
    {
        if (key >= a[s] and key <= a[mid])
            return getResult(a, n, s, mid - 1, key);
        else
            return getResult(a, n, mid + 1, e, key);
    }
    else
    {
        if (key > a[mid] and key <= a[e])
            return getResult(a, n, mid + 1, e, key);
        else
            return getResult(a, n, s, mid - 1, key);
    }
}
int main()
{
   int n;
   cin>>n;
   int *a= new int[n];
   int i =0;
	   int temp;
   while(i<n){
	   cin>>temp;
	   a[i] = temp;
	   i++;
   }
   int key;
   cin>>key;
   int output = getResult(a,n,0,n-1,key);
   cout<<output<<endl;
    return 0;
}