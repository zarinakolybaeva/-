#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r){
    int sub1 = m - l + 1;
    int sub2 = r - m;
    int * left = new int[sub1];
    int * rigth = new int[sub2];
    for(int i = 0; i < sub1; i++){
        left[i] = arr[l+i];
    }
    for(int i = 0 ; i < sub2; i++){
        rigth[i] = arr[m+i+1];
    }
    int leftI=0, rigthI = 0, mergeI = l;
    while(leftI < sub1 && rigthI < sub2){
        if(left[leftI] < rigth[rigthI]){
            arr[mergeI] = left[leftI];
            leftI++;
        }
        else{
            arr[mergeI] = rigth[rigthI];
            rigthI++;
        }
        mergeI++;
    }
    while(leftI < sub1){
        arr[mergeI] = left[leftI];
        leftI++;
        mergeI++;
    }
    while(rigthI < sub2){
        arr[mergeI] = rigth[rigthI];
        rigthI++;
        mergeI++;
    }
    delete[] left;
    delete[] rigth;
}

void mergeSort(int arr[], int l, int r){
    if(l >= r) return;
    int mid = (l + r)/2;
    mergeSort(arr,l, mid);
    mergeSort(arr,mid+1, r);
    merge(arr,l, mid, r);
}


int main() {
    int n, m; cin >> n;
    int arr1[n];
    for(int i = 0 ; i < n ;i++){
        cin >> arr1[i];
    }
    cin >> m;
    int arr2[n+m];
    for(int i = 0 ; i < m ;i++){
        cin >> arr2[n+i];
    }
    for(int i = 0 ; i < n ;i++){
        arr2[i] = arr1[i];
    }
    mergeSort(arr2,0,n+m-1);
    for(int i = 0; i < (n+m) ; i++){
        cout << arr2[i] << " ";
    }

    return 0;
}