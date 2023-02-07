#include <iostream> 
#include <cmath> 
#include<algorithm> 
using namespace std; 
 
bool check(int mid, int a[], int n, int k) 
{ 
    int cnt = 0; 
    for(int i = 0; i < n; i++) 
  { 
        cnt = cnt + ceil(double(a[i]) / mid); 
    } 
    return(cnt <= k); 
} 
 
 
int main() 
{ 
    int n, k; 
    cin >> n >> k; 
    int a[n]; 
    long long l = 0, r = 0; 
    for(int i = 0; i < n; i++) 
  { 
        cin >> a[i]; 
        r += a[i]; 
    } 
  long long mid; 
    while(l<=r) 
  { 
         mid= (l + r) / 2; 
        if(check(mid, a, n, k)) 
    { 
            r = mid - 1; 
        } 
        else{ 
            l = mid + 1; 
        } 
    } 
    if(l == 0) 
  { 
        l += 1; 
    } 
    cout << l; 
}