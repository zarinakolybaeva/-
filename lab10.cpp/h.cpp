#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int> >& matrix, vector<vector<bool> >& visited, int x, int y, int n, int m){
    if (x < 0 || y < 0 || x >= n || y >= m || visited[x][y] == true || matrix[x][y] == 0) 
    return;
    visited[x][y] = true;
    dfs(matrix, visited, x + 1, y, n, m);
    dfs(matrix, visited, x, y + 1, n, m);
    dfs(matrix, visited, x - 1, y, n, m);
    dfs(matrix, visited, x, y - 1, n, m);
}

int count(vector<vector<int> >& matrix, int n, int m){
    vector<vector<bool> > visited(n, vector<bool>(m, false));
    int res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (visited[i][j] == false && matrix[i][j] == 1){
                res++;
                dfs(matrix, visited, i, j, n, m);
            }
        }
    }
    return res;
}
int main(){
    int n, m; cin >> n >> m;
    vector<vector<int> > island_map(n);
    for(int i = 0 ; i < n; i++){
        for(int j = 0 ; j < m ; j++){
            char val; cin >> val;
            island_map[i].push_back(int(val)-48);
        }
    }
    cout << count(island_map, n ,m);

    return 0;
}