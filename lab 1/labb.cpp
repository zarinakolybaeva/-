#include <deque>
#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    
    deque<int> a;
    deque<int> b;
    int i =0;
    while(i<n){
        int num;
        cin>>num;
        a.push_back(num);
        i++;
    }
   b.push_front(-1);
   
    for(int i=0;i<a.size()-1;i++){
        if(a[i]>a[i+1]){
            b.push_back(-1);
            
        }
        
        else if(a[i]<a[i+1]){
            b.push_back(a[i]);
            
        }

    }
    for(int i=0;i<b.size();i++){
        cout<<b[i]<<" ";
    }
}