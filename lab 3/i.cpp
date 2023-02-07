#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin>>x;
    sort(a, a + n);
    int l, r;
    l = 0;
    r = n - 1;
    while (l <= r)
    {
        int m = l + (r-l) / 2;
        if(a[m]==x) {
            cout<<"Yes"<<endl;
            return 0;
        }
        if(a[m]<x) l=m+1;
        else r=m-1;
    }
    cout<<"No"<<endl;
}