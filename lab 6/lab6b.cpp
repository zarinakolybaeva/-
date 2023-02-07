#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r){
    int sub1 = m - l + 1;
    int sub2 = r - m;

    int* leftArray = new int[sub1];
    int* rigthArray = new int[sub2];

    for(int i = 0 ; i < sub1; i++){
        leftArray[i] = arr[i+l];
    }
    for(int i = 0 ; i< sub2; i++){
        rigthArray[i] = arr[m+i+1];
    }

    int leftIndex = 0;
    int rigthIndex = 0;
    int mergeIndex = l;

    while(leftIndex < sub1 && rigthIndex < sub2){
        if(leftArray[leftIndex] <= rigthArray[rigthIndex]){
            arr[mergeIndex] = leftArray[leftIndex];
            leftIndex ++;
        }
        else{
            arr[mergeIndex] = rigthArray[rigthIndex];
            rigthIndex ++;
        }
        mergeIndex ++;
    }

    while(leftIndex < sub1){
        arr[mergeIndex] = leftArray[leftIndex];
        leftIndex++;
        mergeIndex++;
    }

    while(rigthIndex < sub2){
        arr[mergeIndex] = rigthArray[rigthIndex];
        rigthIndex++;
        mergeIndex++;
    }
    delete[] leftArray;
    delete[] rigthArray;
}

void mergeSort(int arr[], int l, int r){
    if(l >= r) return;
    int mid = l + (r-l)/2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid+1, r);
    merge(arr, l, mid, r);
}

int binaryRigth(int arr[], int size, int val){
    int l = 0, r = size - 1;
    while(l <= r){
        int mid = (l + r)/2;
        if(arr[mid] <= val) l = mid + 1;
        else r = mid - 1;
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
    int a[n], b[m];
    for(int i = 0 ; i < n ;i++){
        cin >> a[i];
    }
    for(int i = 0 ; i < m ; i++){
        cin >> b[i];
    }

    mergeSort(a, 0, n-1);
    mergeSort(b, 0, m-1);

    for(int i = 0 ; i < m ; i++){
        int cnt1 = binaryRigth(a, n, b[i]) - binaryLeft(a, n , b[i]) + 1;
        int cnt2 = binaryRigth(b, m, b[i]) - binaryLeft(b, m , b[i]) + 1;
        for(int j = 0; j < min(cnt1, cnt2); j++){
            cout << b[i] << ' ';
        }
        i += cnt2 - 1;
    }

    return 0;
}
//2
#include <iostream>
using namespace std;
void merge(int *,int, int , int );
void mergesort(int a[], int lw, int ub)
{
    int mid;
    if (lw < ub){
        mid=(lw+ub)/2;
        mergesort(a,lw,mid);
        mergesort(a,mid+1,ub);
    
        merge(a,lw,ub,mid);
    }
}
void merge(int a[], int lw, int ub, int mid)
{
    int i, j, k, b[100000];
    i = lw;
    k = lw;
    j = mid + 1;
    while (i <= mid && j <= ub) {
        if (a[i] < a[j]) {
            b[k] = a[i];
            k++;
            i++;
        }
        else  {
            b[k] = a[j];
            k++;
            j++;
        }
    }
    while (i <= mid) {
        b[k] = a[i];
        k++;
        i++;
    }
    while (j <= ub) {
        b[k] = a[j];
        k++;
        j++;
    }
    for (i = lw; i < k; i++)  {
        a[i] = b[i];
    }
}
int searchl(int a[], int sz, int x){
    int lb = 0;
    int  ub = sz - 1;
    while(lb <= ub){
        int mid = lb + (ub - lb) / 2;
        if(a[mid] >= x)
        {
        ub = mid - 1;
        }
        else{
        lb = mid + 1;
        }
    }
    return lb;
}
int searchr(int a[], int sz, int x){
    int lb = 0;
    int ub = sz- 1;
    while(lb <= ub){
        int mid = (lb + ub)/2;
        if(a[mid] <= x){
        lb = mid + 1;
        }
        else{
         ub = mid - 1;
        }
    }
    return ub;
}

int main()
{    int n, k; 
    cin >> n >> k;
    int a[n], b[k];
    for(int i = 0 ; i < n ;i++){
        cin >> a[i];
    }
    for(int i = 0 ; i < k ; i++){
        cin >> b[i];
    }
    mergesort(a, 0, n-1);
    mergesort(b, 0, k-1);

    for(int i = 0 ; i < k ; i++){
        int count1 = 1+searchr(a, n, b[i]) - searchl(a, n , b[i]) ;
        int count2 = 1+searchr(b, k, b[i]) - searchl(b, k , b[i]);
        for(int j = 0; j < min(count1, count2); j++){
            cout << b[i] << ' ';
        }
        i += count2 - 1;
    }
}