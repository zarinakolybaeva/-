#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n; cin >> n;
    string oldName, newName;
    vector <pair<string, string> > names;
    for(int i = 0 ; i < n ;i++){
        cin >> oldName >> newName;
        for(int j = 0; j < names.size(); j++){
            if(names[j].second == oldName){
                names[j].second = newName;
                goto skip;
            }
        }
        names.push_back(make_pair(oldName, newName));
        skip:;
    }
    cout << names.size() << endl; 
    for(int i = names.size() - 1; i >= 0; i--){
        cout << names[i].first << ' ' << names[i].second << endl;
    }
    return 0;
}
//2
#include <iostream>
#include <vector>
using namespace std;
void quick_sort(vector<int> &a, int l, int r) {
    if (r < l + 1) return;
    int mid = (l + r) / 2;
    int pivot = a[mid];
    int j = l;
    swap(a[r], a[mid]);
    for (int i = l; i <= r; i++) {
        if (a[i] < pivot) {
            swap(a[i], a[j]);
            j++;
        }
    }
    swap(a[j], a[r]);
    quick_sort(a, l, j - 1);
    quick_sort(a, j + 1, r);
}
int main(){
    int n;
    cin >> n;
    string was;
    string now;
    vector <pair<string, string> > full;
    for(int i = 0 ; i < n ;i++){
        cin >> was >> now;
        for(int j = 0; j < full.size(); j++){
            if(full[j].second == was){
                full[j].second = now;
                goto skip;
            }
        }
        full.push_back(make_pair(was, now));
         skip:;
    }
    cout << full.size() << endl; 
    for(int i = full.size() - 1; i >= 0; i--){
        cout << full[i].first << ' ' << full[i].second << endl;
    }
}