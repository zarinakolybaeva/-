#include<iostream>
using namespace std;
void primes(int n){
    for(int i=2;i<=n;i++){
        bool is_prime=true;
        for(int j=2;j*j<=i;j++){
            if(i%j==0){
                is_prime=false;
                break;
            }
        }
        if(is_prime)
        cout<<i<<" ";
    }
}
int main(){
    int n;
    cin>>n;
    primes(n);
    return 0;
}
