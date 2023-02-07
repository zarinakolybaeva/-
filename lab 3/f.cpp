#include <bits/stdc++.h>
using namespace std;
int binarySearch(int arr[], int n, int x)
{
    int left = 0;
    int right = n - 1;
    int count = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] <= x) {
            count = mid + 1;
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    return count;
}

int main()
{
    int n, summary = 0;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    } 
    sort(arr,arr + n);
    int key;
    cin>>key;
    for(int i = 0; i < key; i++) {
        int x;
        summary = 0;
        cin>>x;
        for(int j = 0; j < n; j++) {
            if(arr[j] <= x) summary += arr[j];
        }
    cout << binarySearch(arr, n, x) << " " << summary<<'\n';
    }
}