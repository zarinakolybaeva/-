#include <bits/stdc++.h>
using namespace std;

struct Rec{
    int x1, x2;
    int y1, y2;
};

int get(vector<Rec> &Recs, int x) {
    int res = 0;
    for(auto &Rec : Recs) {
        if(Rec.x1 <= x && Rec.y1 <= x && Rec.x2 <= x && Rec.y2 <= x)
            res++;
    }
    return res;
}
void bin(vector<Rec> &Recs, int k) {
    int l = 0, r = 1e9+2;

    while(l + 1 < r) {
        int mid = (l+r)/2;
        if(get(Recs, mid) >= k)
            r = mid;
        else
            l = mid;
    }


int main() {

    int n, k;
    cin >> n >> k;

    vector<Rec> Recs(n);
    for(auto & Rec : Recs) {
        cin >> Rec.x1 >> Rec.y1 >> Rec.x2 >> Rec.y2;
    }

    bin(Recs, k);

    return 0;
}    cout << r;
}

