#include <bits/stdc++.h>
using namespace std;
int main(){
	int x;
	cin >> x;
	deque<int> g, w;
	for(int i = 0; i < x; ++i){
		char y;
		cin >> y;
		if(y == '+'){
			int g_num;
			cin >> g_num;
			g.push_back(g_num);
		}
		else if(y == '*'){
			int g_num;
			cin >> g_num;
			g.push_front(g_num);
		}
		else{
			cout << w.front() << endl;
			w.pop_front();
		}
		if(w.size() < g.size()){
			w.push_back(g.front());
			g.pop_front();
		}
	}	
}