#include <bits/stdc++.h>
using namespace std;

int bin(vector<pair<int, pair<int, int > > > &a, int x) {
    int l = 0, r = a.size()-1;
    while(l<=r) {
        int m = l+(r-l)/2;
        if(a[m].first==x) {
            return m;
        }
        if(a[m].first<x) l=m+1;
        else r=m-1;
    }
    return -1;
}

int main() {
    int n;
    cin>>n;
    int a[n];
    int x,y;
    vector<pair<int, pair<int, int> > > v;

    for(int i=0;i<n;i++) {
        cin >> a[i];
    }
    cin>>x>>y;
    int b[x][y];
    for(int i=0;i<x;i++) {
        for(int j=0;j<y;j++) {
            cin>>b[i][j];
            v.push_back(make_pair(b[i][j], make_pair(i, j)));
        }
    }
    sort(v.begin(), v.end());
    for(int i=0;i<n;i++) {
        int k = bin(v, a[i]);
        if(k == -1){
            cout << -1 << '\n';
            continue;
        }
        cout << v[k].second.first << ' '<< v[k].second.second << '\n';
    }

}