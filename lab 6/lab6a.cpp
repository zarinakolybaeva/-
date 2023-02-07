#include <iostream>
using namespace std;

bool cmp(char a, char b){
    bool isVowelA = (a == 'a'|| a == 'e'|| a=='i'|| a=='o'|| a=='u');
    bool isVowelB = (b == 'a'|| b == 'e'|| b=='i'|| b=='o'|| b=='u');
    if(isVowelA && !isVowelB) return false;
    if(!isVowelA && isVowelB) return true;
    return a > b;
}

void heapify(char a[], int size, int index){
    int max = index;
    int l = index*2 + 1;
    int r = index*2 + 2;

    if(l < size && cmp(a[l], a[max])) max = l;
    if(r < size && cmp(a[r], a[max])) max = r;
    if(max != index){
        swap(a[max], a[index]);
        heapify(a, size, max);
    }
}

void heap_sort(char a[], int size){
    for(int i = (size)/2; i >= 0; i--){
        heapify(a, size, i);
    }
    for(int i = size - 1; i >= 0;i--){
        swap(a[i], a[0]);
        heapify(a, i, 0);
    }
}

int main() {
    int n; cin >> n;
    char a[n];
    for(int i = 0 ; i < n; i++){
        cin >> a[i];
    }
    heap_sort(a, n);
    for(int i = 0; i < n; i++){
        cout << a[i];
    }

    return 0;
}

// my
#include <bits/stdc++.h>
using namespace std;
//unsigned long long heap[200010];
int sz = 0;

bool find(char x, char y){
    bool first = (x == 'a'|| x == 'e'|| x=='i'|| x=='o'|| x=='u');
    bool second = (y == 'a'|| y == 'e'|| y=='i'|| y=='o'|| y=='u');
    if(first && !second)
     return false;
    else if(!first && second)
     return true;
     else
    return x > y;
}

void heapify(char x[],int sz, int i){

    int left = i+i + 1;
    int right = i+i + 2;
    int mx = i;
    if(left < sz && find(x[left], x[mx])) 
    mx = left;
    if(right < sz && find(x[right], x[mx]))
     mx = right;
    if(mx != i){
        swap(x[mx], x[i]);
        heapify(x,sz, mx);
    }
}

void sorting(char x[]){
    for(int i = sz; i >= 0; i--){
        heapify(x ,sz, i);
    }
    for(int i = sz-1 ; i >= 0;i--){
        swap(x[i], x[0]);
        heapify(x,i,  0);
    }
}

int main() {
    int n; 
    cin >> n;
    char x[n];
    for(int i = 0 ; i < n; i++){
        cin >> x[i];
    }
    sz=n;
    sorting(x);
    for(int i = 0; i <n; i++){
        cout << x[i];
    }

}