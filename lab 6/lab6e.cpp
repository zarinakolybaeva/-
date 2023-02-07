#include <iostream>
using namespace std;

void heapify(int a[], int size, int index){
    int l = index*2 + 1;
    int r = index*2 + 2;
    int min = index;
    if(l < size && a[min] > a[l]) min = l;
    if(r < size && a[min] > a[r]) min = r;
    if(min != index){
        swap(a[min], a[index]);
        heapify(a, size, min);
    }
}
void heapSort(int a[], int size){
    for(int i = size/2; i >= 0; i--){
        heapify(a, size, i);
    }
    for(int i = size-1; i >= 0; i--){
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

int main() {
    int n, m; cin >> n >> m;
    int arr[m][n];
    for(int i = 0; i < n; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> arr[j][i];
        }
    }
    for(int i = 0; i < m ;i++){
        heapSort(arr[i], n);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0 ; j < m ; j++){
            cout << arr[j][i] << " ";
        }
        cout << endl;
    }
    return 0;
}