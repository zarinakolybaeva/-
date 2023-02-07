#include <iostream>
using namespace std;

void heapify(string &a, int size, int index){
    int l = index*2 + 1;
    int r = index*2 + 2;
    int max = index;
    if(l < size && a[max] < a[l]) max = l;
    if(r < size && a[max] < a[r]) max = r;
    if(max != index){
        swap(a[max], a[index]);
        heapify(a,size,max);
    }
}

void heapSort(string &a){
    int size = a.size();
    for(int i = size/2; i >= 0; i--){
        heapify(a,size,i);
    }
    for(int i = size-1; i >= 0; i--){
        swap(a[0], a[i]);
        heapify(a,i,0);
    }
}

int main() {
    string s; cin >> s;
    heapSort(s);
    cout << s;

    return 0;
}
//2
#include <iostream>
using namespace std;
void quick_sort(string &a, int l, int r) {
    if (r < l + 1) return;
    int mid =(l + r) / 2;
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
    quick_sort(a, l, j-1 );
    quick_sort(a, j + 1, r);
}

int main() {
    string s; cin >> s;
    quick_sort(s,0,s.size()-1);
    cout << s;

    return 0;
}