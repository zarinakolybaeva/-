#include <iostream>
using namespace std;

int main(){
    int n, q; cin >> n >> q;
    int arr[n][n];
    for(int i = 0 ; i < n ; i++){
        for(int j = 0; j < n ;j++){
            int val; cin >> val;
            arr[i][j] = val;
        }
    }
    for(int i = 0 ; i < q; i++){
        int a, b, c; cin >> a >> b >> c;
        a -= 1; b -=1; c -=1;
        if(arr[a][b] == 1 && arr[b][a] == 1 && arr[c][a] == 1
        && arr[a][c] == 1 && arr[b][c] == 1 && arr[c][b] == 1){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }

    return 0;
}