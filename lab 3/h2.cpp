#include <iostream> 
using namespace std; 
 
void binSearch(int a[],int l, int r, int x){ 
    while(l <= r){ 
        int mid = (l + r)/2; 
        if(a[mid] >= x){ 
            r = mid - 1; 
        } 
        if(a[mid] <= x){ 
            l = mid + 1; 
        } 
    } 
    cout << r + 1 << endl; 
} 
int main(){ 
    int n, m; 
    cin >> n >> m; 
    int a[n]; 
    for(int i = 1;i <= n;i++) 
  { 
        int x; cin >> x; 
        if(i == 1) 
    { 
            a[i] = x; 
        } 
    else 
    { 
            a[i] = a[i - 1] + x; 
        } 
    } 
    for(int i = 1;i <= m;i++) 
  { 
        int x; cin >> x; 
        binSearch(a,1,n,x); 
    } 
    return 0; 
}