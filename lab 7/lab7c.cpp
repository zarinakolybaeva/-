#include <iostream>
using namespace std;

void merge(int arr[], int l , int m , int r){
    int sub1 = m - l + 1;
    int sub2 = r - m;
    int* left = new int[sub1];
    int* rigth = new int[sub2];
    for(int i = 0 ; i < sub1; i++){
        left[i] = arr[l+i];
    }
    for(int i = 0 ; i < sub2; i++){
        rigth[i] = arr[m+i+1];
    }
    int leftI=0, rigthI=0, mergeI=l;
    while(leftI<sub1 && rigthI<sub2){
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
    while(leftI<sub1){
        arr[mergeI] = left[leftI];
        leftI++;
        mergeI++;
    }
    while(rigthI<sub2){
        arr[mergeI] = rigth[rigthI];
        rigthI++;
        mergeI++;
    }
    delete[] left; delete[] rigth;
}

void mergeSort(int arr[], int l, int r){
    if(l >= r) return;
    int mid = (l+r)/2;
    mergeSort(arr,l, mid);
    mergeSort(arr, mid+1, r);
    merge(arr,l, mid, r);
}

int binaryRight(int arr[], int size, int val){
    int l = 0, r = size - 1;
    while(l <= r){
        int m = l + (r - l) / 2;
        if(arr[m] <= val){l = m + 1;}
        else{r = m - 1;}
    }
    return r;
}

int binaryLeft(int arr[], int size, int val){
    int l = 0, r = size - 1;
    while(l <= r){
        int m = l + (r - l) / 2;
        if(arr[m] >= val){r = m - 1;}
        else{l = m + 1;}
    }
    return l;
}
int main() {
    int n, m; cin >> n >> m;
    int arr1[n], arr2[m];
    for(int i = 0; i < n; i++){
        cin >> arr1[i];
    }
    for(int i = 0; i < m; i++){
        cin >> arr2[i];
    }
    mergeSort(arr1,0,n-1);
    mergeSort(arr2,0,m-1);

    for(int i = 0; i < m; i++){
        int cnt1 = binaryRight(arr1, n, arr2[i]) - binaryLeft(arr1, n, arr2[i]) + 1;
        int cnt2 = binaryRight(arr2, m, arr2[i]) - binaryLeft(arr2, m, arr2[i]) + 1;
        for(int j = 0; j < min(cnt1, cnt2); j++){
            cout << arr2[i] << ' ';
        }
        i += cnt2 - 1;
    }

    return 0;
}