#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll check(vector<ll> &v, ll &mid) {
    ll res = 0;
    for(auto i : v) {
        res += i / mid;
        if(i % mid)
            res++;
    }
    return res;
}

void bin(vector<ll> v, ll &h){
    ll l = 0, r = 1e18;
    while(l + 1 < r) {
        ll mid = (l + r)/2;
        ll k = check(v, mid);
        if(k <= h)
            r = mid;
        else
            l = mid;
    }
    cout << r;
}
int main() {
    ll n, h;
    cin >> n >> h;
    vector<ll> v(n);
    for(auto &i: v) cin >> i;
    bin(v, h);
    return 0;
}