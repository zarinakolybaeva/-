#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main(){
    int n,i,j;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    
    for(int i=0; i<n; i++){
        if(i==0) {
            cout << "-1 ";
            continue;
        }
        else {
            for(int j=i-1; j>=0; j--){
            //    cout<<a[j];
                if(a[i] >= a[j]){
                    cout << a[j] << " ";
                    break;
                }
                else if (j==0)
                {
                    cout << "-1 ";
                } 
            }
        }
       
    }

    return 0;
}