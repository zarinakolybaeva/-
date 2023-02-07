#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m, q, ar[700500LL];

ll bin_search(ll x){
    ll l = -1, r = n;
    while(r > l+1){
        ll m = (l+r)/2;
        (ar[m] > x ? r : l) = m;
    }
    return ++l;
}

int main(){
    cin>>n>>q;
    for(int i=0;i<n;i++) cin>>ar[i];
    sort(ar, ar+n);

    for(int i=0;i<q;i++){
        ll l1, r1, l2, r2;
        cin>>l1>>r1>>l2>>r2;
        ll ans = 0;
        if (l1 > l2) swap(l1, l2), swap(r1, r2);
        
        if (r1 + 1 >= l2){
            ans = bin_search(max(r1, r2)) - bin_search(l1-1);
        }else{
            ans = bin_search(r1) - bin_search(l1-1) + bin_search(r2) - bin_search(l2-1);
        }
        cout<<ans<<'\n';
    }
    return 0;
}