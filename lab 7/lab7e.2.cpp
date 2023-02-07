#include <bits/stdc++.h>

using namespace std;

struct Row{
    int cum, size;
    vector<int> v;
    Row(){
        cum = 0;
        size = 0;
    }
    void insert(int x){
        cum += x;
        v.push_back(x);
    }
    
    void print(){
        for(int i = 0; i < v.size(); ++i){
            cout << v[i] << " ";
        }
        cout << '\n';
    }
    
    bool isGreater(Row * b){
        if(cum > b->cum){
            return true;
        } 
        if(cum == b->cum){
            for(int i = 0; i < v.size(); ++i){
                if(v[i] == b->v[i]){
                    
                }else{
                    return v[i] < b->v[i];
                }
            }
            return false;
        }
        return false;
    }
};

void mergesortpartition(Row * a, int s, int e, int lx, int rx){
    int n = e - s + 1;
    Row l[n];
    for(int i = 0; i < n;i++){
        l[i] = a[s + i];
    }
    int g = rx - lx + 1;
    Row r[g];
    for(int i = 0; i < g; i++){
        r[i] = a[lx + i];
    }
    int i = s, i1 = 0, i2 = 0;
    while(i1 < n && i2 < g){
        if(l[i1].isGreater(&r[i2])){
            a[i++] = l[i1++];
        }else {
            a[i++] = r[i2++];
        }
    }

    while(i1 < n){
        a[i++] = l[i1++];
    }

    while(i2 < g){
        a[i++] = r[i2++];
    }

}

void mergesort(Row * a, int l, int r){
    if(l < r){
        int m = l + (r - l) / 2;
        mergesort(a, l, m);
        mergesort(a, m + 1, r);
        mergesortpartition(a, l, m , m + 1, r);
    }
}


int main(){
    int n, m;
    cin >> n >> m;
    Row v[n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int x; cin >> x;
            v[i].insert(x);
        }
    }
    mergesort(v, 0, n - 1);
    for(int i = 0; i < n; ++i){
        v[i].print();
    }

    return 0;
}