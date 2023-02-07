#include <iostream> 
using namespace std; 
 
int main(){ 
    int n, k; cin >> n >> k; 
    int a[n]; 
    for(int i = 0; i < n; i++){ 
        int t; cin >> t; 
        a[i] = t; 
    } 
    unsigned long long l = 0, r = 10000000000000, m, cnt, cnt2; 
    while(l < r){ 
        cnt = 1; 
        cnt2 = 0; 
        m = l + (r - l) / 2; 
        for(int i = 0; i < n; i++){ 
            if(m < cnt2 + a[i]){ 
    cnt2 = 0; 
    cnt++; 
   } 
   if(m < a[i]) cnt = k + 1; 
   cnt2 += a[i]; 
        } 
        if(cnt > k) l = m + 1; 
        else if(cnt <= k) r = m; 
    } 
    cout << l; 
    return 0; 
}