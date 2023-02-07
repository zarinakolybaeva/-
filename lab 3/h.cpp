#include <bits/stdc++.h>
using namespace std;
int n, m;
void bin(vector<int> &v, int k) {
    int l = -1, r = n-1;
        while(l + 1 < r) {
            int mid = (l+r)/2;
            if(v[mid] >= k)
                r = mid;
            else
                l = mid;
        }
        cout << r + 1 << '\n';
    }
int main() {
    cin >> n >> m;
    vector<int> v(n);
    for(int i = 0 ; i < n; i++) {
        cin >> v[i];
        if(i) v[i] += v[i-1];
    }

    for(int i = 0; i < m; i++) {
        int k;
        cin >> k;
        bin(v, k);
}
}
