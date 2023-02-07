#include <bits/stdc++.h>
using namespace std;



void BFS(long long x,long long arr[],vector<long long>v[],int cnt[]){
    arr[x ] = x;
    queue<long long>q;
    q.push(x);
    while(!q.empty()){
        long long t = q.front();
        q.pop();

        for(long long i=0;i<v[t].size();i++){
            long long num = v[t][i];
            if(arr[num] == 0){
                cnt[t] ++;
                q.push(num);
                arr[num] = t;
            }
        }
    }
}

int main(){
    long long n,m;
    cin>>n>>m;
    vector<long long> v[n+1];
    for(int i=0;i<m;i++){
        long long x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int cnt[n+10] = {0};
    long long arr[n+10] = {0};
    for(long long i=1;i<=n;i++){
        if(arr[i] == 0){
            BFS(i,arr,v,cnt);
        }
    }
    int cnt__= 0;
    for(long long i=1;i<=n;i++){
        if(arr[i]!=i){
            if(cnt[arr[i]] < cnt[i]) cnt__++;
        }
        else cnt__++;
    }
    cout<<cnt__;
}