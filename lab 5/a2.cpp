#include<iostream>
#include<bits/stdc++.h>
using namespace std;
unsigned long long heap[1000000];
int sz=0;
void heapify(unsigned long long i){
   int left=i+i+1;
   int right=i+i+2;
   int mx=i;
   if(left<sz && heap[left]<heap[mx]){
    mx=left;
   }
   if(right<sz && heap[right]<heap[mx]){
    mx=right;
   }
   if(mx!=i){
    swap(heap[i],heap[mx]);
    heapify(mx);
   }
}

void build( ){
   for(int i=sz/2;i>=0;i--){
    heapify(i);
   }
}
void insert(int val){
    heap[sz++]=val;
    int i=sz-1;
while(i>0){
    int p=(i-1)/2;
    if(heap[i]<heap[p]){
        swap(heap[i],heap[p]);
        i=p;
    }
    else {
        break;
    }
}
}
void deletemin(){
   swap(heap[0],heap[sz-1]);
   sz--;
   heapify(0);
}
void print(){
    for(int i=0;i<sz;i++){
        cout<<heap[i]<<" ";
    }
    cout<<endl;
}

void heapSort() {
    build();
    while (sz > 1) {
        swap(heap[0], heap[sz - 1]);
        sz--;
        heapify(0);
    }
}

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> heap[i];
    }
    sz = n;
   build();
   unsigned long long ans=0;
    while(sz>1){
    int a=heap[0];
    deletemin();
    int b=heap[0];
    deletemin();
    ans+=a+b;
    insert(a+b);
} 
cout<<ans<<endl;
}
