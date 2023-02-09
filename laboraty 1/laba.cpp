#include <iostream>
#include <math.h>
#include <deque>
#include <stack>
#include <queue>

using namespace std;


int main() {
    int k;
    cin >> k;
    while(k--){
        int n;
        cin >> n;
        queue<int> q;
        vector<int> a(10005);
        for(int i = 1; i <= n; i++){
            q.push(i);
        }
        // while(!q.empty()){
        //     cout<<q.front();
        //     q.pop();
        // }
        int i = 1;
        while(!q.empty()){
            int j = 0;
            while(j < i){
                int x = q.front();
                q.pop();
                q.push(x);
                j++;
                // while(!q.empty()){
                //     cout<<q.front();
                //     q.pop();
                // }
                // return 0;
            }
            int x = q.front();
          //  cout<< x<<"x";
            if(a[x] != 0){
                cout << -1 << endl;
                return 0;
            }
            a[x] = i; //a[2]=1 самый важный момент a[x]=2  i=1 значить   1 сан турады 2 индексте 
                      //a[5]=2   -> a[x]=5 --> 2 сан турады 5 индексте
         // cout<<a[x]<<"x";
         // cout<<i;
         
            q.pop();
            // while(!q.empty()){
            //     cout<<q.front();
            //     q.pop();
            // }
            i++;
        //  for (int i = 1; i <= n; i ++){
        // cout << a[i] << " ";
        
        // }
        // cout<<":";
          //  cout<<i;
         
        }
        //    while(!q.empty()){
        //         cout<<q.front();
        //         q.pop();
        //     }
        for (int i = 1; i <= n; i ++){
        cout << a[i] << " ";
        }
        cout << endl;
    }

}
