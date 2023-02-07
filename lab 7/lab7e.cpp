#include <iostream>
#include <vector>
using namespace std;

bool cmp(vector<int> a, vector<int> b){
    int sum1=0, sum2=0;
    for(int i = 0; i < a.size(); i++){
        sum1 += a[i];
        sum2 += b[i];
    }
    if(sum1 != sum2) return sum1 > sum2;
    for(int i = 0; i < a.size(); i++){
        if(a[i] != b[i]){
            return a[i] < b[i];
        }
    }
    return false;
}

void merge(vector<vector<int> > &v, int l, int m, int r){
    int sub1 = m - l + 1;
    int sub2 = r - m;

    vector<vector<int> > * left = new vector<vector<int> >();
    vector<vector<int> > * rigth = new vector<vector<int> >();
    for(int i = 0; i < sub1; i++){
        left->push_back(v[l+i]);
    }
    for(int i = 0; i < sub2; i++){
        rigth->push_back(v[m+i+1]);
    }
    int leftI=0, rigthI=0, mergeI=l;
    while(leftI<sub1 && rigthI<sub2){
        if(cmp(left->at(leftI), rigth->at(rigthI))){
            v[mergeI] = left->at(leftI);
            leftI++;
        }
        else{
            v[mergeI] = rigth->at(rigthI);
            rigthI++;
        }
        mergeI++;
    }
    while(leftI < sub1){
        v[mergeI] = left->at(leftI);
        leftI++;
        mergeI++;
    }
    while(rigthI < sub2){
        v[mergeI] = rigth->at(rigthI);
        rigthI++;
        mergeI++;
    }
    delete left; delete rigth;
}

void mergeSort(vector<vector<int> > &v, int l , int r){
    if(l >= r) return;
    int mid = (l+r)/2;
    mergeSort(v, l, mid);
    mergeSort(v, mid+1, r);
    merge(v,l, mid, r);
}

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int> > vec;
    for(int i = 0; i < n; i++){
        vector <int> tmp;
        for(int j = 0; j < m; j++){
            int val; cin >> val;
            tmp.push_back(val);
        }
        vec.push_back(tmp);
    }
    mergeSort(vec,0,n-1);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
//2
#include <iostream>
#include <vector>
using namespace std;

void merge(int *,int, int , int );

void merge(vector<int >&a, int lw, int ub, int mid)
{
    int i, j, k, b[100000];
    i = lw;
    k = lw;
    j = mid + 1;
    while (i <= mid && j <= ub) {
        if (a[i] < a[j]) {
            b[k] = a[i];
            k++;
            i++;
        }
        else  {
            b[k] = a[j];
            k++;
            j++;
        }
    }
    while (i <= mid) {
        b[k] = a[i];
        k++;
        i++;
    }
    while (j <= ub) {
        b[k] = a[j];
        k++;
        j++;
    }
    for (i = lw; i < k; i++)  {
        a[i] = b[i];
    }
}
void mergesort(vector<int > &a, int lw, int ub)
{
    int mid;
    if (lw < ub){
        mid=(lw+ub)/2;
        mergesort(a,lw,mid);
        mergesort(a,mid+1,ub);
    
        merge(a,lw,ub,mid);
    }
}

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int> > vec;
    for(int i = 0; i < n; i++){
        vector <int> tmp;
        for(int j = 0; j < m; j++){
            int val; cin >> val;
            tmp.push_back(val);
        }
        vec.push_back(tmp);
    }
    mergesort(vec,0,n-1);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
    
}