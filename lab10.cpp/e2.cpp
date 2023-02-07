#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, q;
    cin >> n >> q;
    int a[n][n];
    for(int i = 0; i < n; i++){
        for(int j  = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    while(q > 0){
        int x, y, z;
        cin >> x >> y >> z;
        int cnt = 0;
        if(a[x-1][y-1] == 1 && a[x-1][z-1] == 1 && a[y-1][z-1] == 1){
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
        q--;
    }


    return 0;
}