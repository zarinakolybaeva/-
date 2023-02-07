#include <bits/stdc++.h>
using namespace std;

struct Node{
    char val;
    Node * next;
    Node(char val) {
        this->val = val;
        next=nullptr;
    }
};

class Guests{
public:
    int a[26];
    Node * head;
    Guests() {
        for (int i = 0; i < 26; i ++) {
            a[i] = 0;
        }
        head=nullptr;
    }
    void push(char val) {
        Node * newNode = new Node(val);
        if(head==nullptr) {
            cout << val << " ";
            a[val - 'a']++;
            head=newNode;
        }
        else{
            Node * cur = head;
            char result = '!';
            a[val - 'a']++;
            bool ok = false;
            while(cur!=nullptr){
                if (a[cur -> val - 'a'] == 1 && !ok){
                    ok = 1;
                    result = cur -> val;
                }
                if(cur->next==nullptr) {
                    if (a[val - 'a'] == 1 && !ok) result = val;
                    cur->next=newNode;
                    break;
                }
                cur=cur->next;
            }
            if (result == '!') cout << -1 << " ";
            else cout << result << " ";
        }

    }
};

void solve() {
    Guests list;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        char x;
        cin>>x;
        list.push(x);
    }
    cout<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
    solve();
    }
}