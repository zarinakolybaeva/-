#include<bits/stdc++.h>
using namespace std;
int main (){
    int n;
    cin>>n;
    while(n--){
        int k;
        cin>>k;
        queue<int>q;
        vector<int>a(10000);
        for(int i=1;i<=k;i++){
            q.push(i);
        }
        int i=1;
        while(!q.empty()){
            int j=0;
            while(j<i){
                int x=q.front();
                q.pop();
                q.push(x);
                j++;
            }
            int x=q.front();
          //   cout<<a[x];
            if(a[x]!=0){ // должен быть a[x]==0 типа знать что оно 
                        // уже не занято и не стоит в другом месте
                cout<<-1;
                return 0;
            }
            a[x]=i;
            q.pop();
            i++;
        }
        for(int i=1;i<=k;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;

    }
}