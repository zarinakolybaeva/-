#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll check(vector<ll> &v, ll &mid) {
    ll cnt = 0;
    for(auto i : v) {
        cnt += i / mid;
        if(i % mid)
            cnt++;
    }
    return cnt;
}
void bin(vector<ll> &v, ll &f) {
    ll l = 0, r = 1e18;
    while(l + 1 < r) {
        ll mid = l + (r - l)/2;
        ll ans = check(v, mid);
        if(ans <= f)
            r = mid;
        else
            l = mid;
    }
    cout << r;
}

int main() {
    ll n, f;
    cin >> n >> f;
    vector<ll> v(n);
    for(auto &i : v) cin >> i;
    bin(v, f);
}
