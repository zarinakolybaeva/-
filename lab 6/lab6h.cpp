#include <iostream>

using namespace std;

int search(char a[], int size, char value){
    int l = 0, r = size - 1;
    while(l <= r){
        int m = l + (r - l) / 2;
        if(a[m] <= value){
            l = m + 1;}
        else{r = m - 1;}
    }
    return r;
}

int main(){
    
    int n;
    cin >> n;
    char a[n];
    
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    char k;
    cin >> k;
    int ans = search(a, n, k);
    if(ans == -1){
    cout << a[0]; 
    return 0;
    }
    if(ans == n - 1){
        cout << a[0];
        break;
    }
    if(a[ans] == k && ans < n - 1){
        cout << a[ans + 1];
        break;
    }

    if(a[ans] != k){
        cout << a[ans];
    }

    return 0;
}
//2
#include <bits/stdc++.h>
using namespace std;
int search(char a[], int sz, char c){
    int left = 0, right = sz - 1;
    while(left <= right){
        int mid = left + (right - left) / 2;
        if(a[mid] <= c){
            left = mid + 1;
            }
        else{
            right = mid - 1;
            }
    }
    return right;
}

int main(){
    int n;
    cin >> n;
    char c[n];
    
    for(int i = 0; i < n; i++){
        cin >> c[i];
    }

    char ch;
    cin >> ch;
    int blnc = search(c, n, ch);
     if(blnc == n - 1){
    cout << c[0];
    return 0;
    }
    if(blnc == -1){
    cout << c[0]; 
    return 0;
    }
    if(c[blnc] != ch){
    cout << c[blnc];
    }
    if(c[blnc] == ch && blnc < n - 1){
    cout << c[blnc + 1];
    return 0;
    }
}