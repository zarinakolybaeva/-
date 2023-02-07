#include <bits/stdc++.h>
using namespace std;

void MergeSortedIntervals(vector<pair< double, string > >& v, int s, int m, int e) {
	vector<pair< double, string > > temp;

	int i, j;
	i = s;
	j = m + 1;

	while (i <= m && j <= e) {
		if (v[i].first < v[j].first) {
		    temp.push_back(v[i]);
		    ++i;
		}else if(v[i].first == v[j].first){
		    if(v[i].second < v[j].second){
		        temp.push_back(v[i]);
		        ++i;
		    }else{
		        temp.push_back(v[j]);
		        ++j;
		    }
		}else{
		    temp.push_back(v[j]);
		    ++j;
		}

	}

	while (i <= m) {
		temp.push_back(v[i]);
		++i;
	}

	while (j <= e) {
		temp.push_back(v[j]);
		++j;
	}

	for (int i = s; i <= e; ++i)
		v[i] = temp[i - s];

}

bool cmp(pair<string, string> &p1, pair<string, string> &p2){
    if(p1.first == p2.first){
        return p1.second < p2.second;
    }else{
        return p1.first < p2.first;
    }
}

void MergeSort(vector<pair< double, string > >& v, int s, int e) {
	if (s < e) {
		int m = (s + e) / 2;
		MergeSort(v, s, m);
		MergeSort(v, m + 1, e);
		MergeSortedIntervals(v, s, m, e);
	}
}

int main(){
    int n; cin >> n;
    vector< pair< double, string > > v;
    while(n--){
        string last, first; cin >> last >> first;
        string s = last + " " + first;
        double cntgpa = 0, gpa = 0;
        int cnt, c= 0; cin >> cnt;
        while(cnt--){
            string s; int ects; cin >> s >> ects;
            if(s == "A+"){
                cntgpa+=4.0*ects;
            }
            if(s == "A"){
                cntgpa+=3.75*ects;
            }
            if(s == "B+"){
                cntgpa+=3.5*ects;
            }
            if(s == "B"){
                cntgpa+=3.0*ects;
            }
            if(s == "C+"){
                cntgpa+=2.5*ects;
            }
            if(s == "C"){
                cntgpa+=2.0*ects;
            }
            if(s == "D+"){
                cntgpa+=1.5*ects;
            }
            if(s == "D"){
                cntgpa+=1.0*ects;
            }
            if(s == "F"){
                cntgpa+=0*ects;
            }
            
            c+=ects;
        }
        gpa+=cntgpa/c;
        v.push_back({gpa, s});
    }
    MergeSort(v, 0, v.size() - 1);
    for(auto i : v){
        cout << i.second << ' ' << fixed << setprecision(3) << i.first << '\n';
    }
}