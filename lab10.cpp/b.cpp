#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int arr[100][100];
int n;
vector<int> visited;

int findPath(int start, int end){
    visited[start] = 0;
    queue<int> check;
    check.push(start);
    while(!check.empty()){
        int s = check.front();
        check.pop();
        for(int i = 0; i < n ;i++){
            if(arr[i][s] == 1 && visited[i] == -1){
                visited[i] = visited[s] + 1;
                check.push(i);
                if(i == end){
                    return visited[i];
                }
            }
        }
    }
    return -1;
}

int main(){
    cin >> n;
    for(int i = 0 ; i < n; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> arr[i][j];
        }
    }
    for(int i = 0 ; i < n ;i++){
        visited.push_back(-1);
    }
    int start, end;
    cin >> start >> end;
    start -= 1; end -= 1;
    cout << findPath(start, end);
    return 0;
}
//2
#include <bits/stdc++.h>
using namespace std;
int a[100][100];
vector<int> used;
int n;
int bfs(int b, int e){
    used[b] = 0;
    queue<int> qu;
    qu.push(b);
    while(!qu.empty()){
        int s = qu.front();
        qu.pop();
        for(int i = 0; i < n ;i++){
            if(a[i][s] == 1 && used[i] == -1){
                used[i] = used[s] + 1;
                qu.push(i);
                if(i == e){
                    return used[i];
                }
            }
        }
    }
    return -1;
}

int main(){
    cin >> n;
    for(int i = 0 ; i < n; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0 ; i < n ;i++){
        used.push_back(-1);
    }
    int b, e;
    cin >> b >> e;
    b --;
    e --;
    cout << bfs(b, e);
    
}
//3
#include <bits/stdc++.h>
using namespace std;
int main(){
int a[100][100];
vector<int> used;
    int n;
    cin >> n;
    for(int i = 0 ; i < n; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0 ; i < n ;i++){
        used.push_back(-1);
    }
    int b, e;
    cin >> b >> e;
    while(b-- && e--){
    used[b] = 0;
    queue<int> qu;
    qu.push(b);
    while(!qu.empty()){
        int front = qu.front();
        qu.pop();
        for(int i = 0; i < n ;i++){
            if(a[i][front] == 1 && used[i] == -1){
                used[i] = used[front] + 1;
                qu.push(i);
                if(i == e){
                    cout<< used[i];
                    return 0;
                }
            }
        }
    }
 }
    cout << -1;
    
}