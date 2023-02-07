#include<iostream>
using namespace std;
bool prime(int n){
    if(n<=1){
        return false;
    }
   for(int i=2;i<n;i++){
     if(n%i==0){
        return false;

     }
   }
   return true;
}
int main(){
  int n ;
  int cnt=0;
  cin>>n;
  for(int i=1;i<n;i++){
    if(n%i==0 ){
        if(prime(i)){
            cnt++;
        }
    }
  }
  cout<<cnt;
}
// 2 3 5 11 13