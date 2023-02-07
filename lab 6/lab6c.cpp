#include <iostream>
using namespace std;

void heapify(int arr[], int size, int index){
    int l = index*2 + 1;
    int r = index*2 + 2;
    int max = index;

    if(l < size && arr[max] < arr[l]) max = l;
    if(r < size && arr[max] < arr[r]) max = r;
    if(max != index){
        swap(arr[max], arr[index]);
        heapify(arr, size, max);
    }
}

void heapSort(int arr[], int size){
    for(int i = size/2; i >= 0 ;i--){
        heapify(arr,size, i);
    }
    for(int i = size-1; i>=0; i--){
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n ;i++){
        cin >> arr[i];
    }
    heapSort(arr, n);
    int min = abs(arr[1] - arr[0]);
    for(int i = 1; i < n; i++){
        if(min > abs(arr[i] - arr[i-1])){
            min = abs(arr[i] - arr[i-1]);
        }
    }
    for(int i = 1; i < n ;i++){
        if(abs(arr[i] - arr[i-1]) == min){
            cout << arr[i-1] << " " <<  arr[i] << " ";
        }
    }

    return 0;
}
// 2
#include<bits/stdc++.h>
using namespace std;
int sz=0;
void heapify(int a[], int sz, int i){
    int left = i+i + 1;
    int right = i+i + 2;
    int mx = i;

    if(left < sz &&  a[left]>a[mx]) 
    mx = left;
    if(right < sz &&  a[right]>a[mx]) 
    mx = right;
    if(mx != i){
        swap(a[i],a[mx]);
        heapify(a, sz, mx);
    }
}
void build(int a[]) {
    for (int i = (sz - 1) / 2; i >= 0; i--) {
        heapify(a,sz,i);
    }
}
void heapsort(int a[]) {
    build(a);
    // while (sz > 1) {
    //     swap(a[0], a[sz - 1]);
    //     sz--;
    //     heapify(a,sz-1,0);
    // }
     for(int i = sz-1; i>=0; i--){
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}
int main() {
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n ;i++){
        cin >> a[i];
    }
    sz=n;
    heapsort(a);
    int min = abs(a[1] - a[0]);
    for(int i = 1; i < n; i++){
        if(min > abs(a[i] - a[i-1])){
            min = abs(a[i] - a[i-1]);
        }
    }
    for(int i = 1; i < n ;i++){
        if(abs(a[i] - a[i-1]) == min){
            cout << a[i-1] << " " <<  a[i] << " ";
        }
    }
}