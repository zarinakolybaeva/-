#include <iostream>
#include <queue>
using namespace std;

int n, m;
int arr[1000][1000];

queue<pair<int, int> > check;

void checkAdj(int x, int y){
    if(x-1 >= 0 && arr[x-1][y] == 1){
        arr[x - 1][y] = 2;
        check.push(make_pair(x - 1, y));
    }
    if(x+1 < n && arr[x+1][y] == 1){
        arr[x+1][y] = 2;
        check.push(make_pair(x+1, y));
    }
    if(y-1 >= 0 && arr[x][y-1] == 1){
        arr[x][y-1] = 2;
        check.push(make_pair(x, y-1));
    }
    if(y+1 < m && arr[x][y+1] == 1){
        arr[x][y+1] = 2;
        check.push(make_pair(x, y+1));
    }
}

void transform(){
    int cnt = 0;
    while(!check.empty()){
        int size = check.size();
        for(int i = 0 ; i < size; i++){
            int x = check.front().first;
            int y = check.front().second;
            check.pop();
            checkAdj(x, y);
        }
        if(!check.empty()){
            cnt++;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] == 1){
                cout << -1;
                return;
            }
        }
    }
    cout << cnt;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n;i++){
        for(int j =  0;  j < m; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 2){
                check.push(make_pair(i, j));
            }
        }
    }
    transform();

    return 0;
}
//2
#include <iostream>
#include<deque>
using namespace std;
int n, m;
int a[1000][1000];
deque<pair<int, int> > deq;
int main(){
cin >> n >> m;
for(int i = 0; i < n;i++){
  for(int j =  0;  j < m; j++){
      cin >> a[i][j];
      if(a[i][j] == 2){
        deq.push_front(make_pair(i, j));
            }
        }
    }
    int min = 0;
    while(!deq.empty()){
    int sz = deq.size();
    for(int i = 0 ; i < sz; i++){
            int x = deq.back().first;
            int y = deq.back().second;
            deq.pop_back();
    if(x-1 >= 0 && a[x-1][y] == 1){
        a[x - 1][y] = 2;
        deq.push_front(make_pair(x - 1, y));
    }
    if(y-1 >= 0 && a[x][y-1] == 1){
        a[x][y-1] = 2;
        deq.push_front(make_pair(x, y-1));
    }
    if(x+1 < n && a[x+1][y] == 1){
        a[x+1][y] = 2;
        deq.push_front(make_pair(x+1, y));
    }
    if(y+1 < m && a[x][y+1] == 1){
        a[x][y+1] = 2;
        deq.push_front(make_pair(x, y+1));
    }
    }
    if(!deq.empty()){
            min++;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == 1){
                cout << -1;
                return 0;
            }
        }
    }
 
    cout << min;
    
}