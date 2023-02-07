#include <bits/stdc++.h>
using namespace std;
#define ll long long int
struct Node {
    ll val;
    Node * next;
    Node * prev;

    Node(ll val) {
        this->val=val;
        next=nullptr;
        prev=nullptr;
    }
};


class Linkedlist{
    Node * head;
    Node* tail;
public:
    Linkedlist() {
        head=nullptr;
        tail=nullptr;
    }
    void pushBack(ll val) {
        Node * newNode = new Node(val);
        if(head==nullptr) {
            head=newNode;
            tail=newNode;
        }
        else {
            tail->next=newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    void less_number(int target) {
        Node* cur = head;
        int res = 1000000;
        int i=0;
        int res_i;
        while(cur!=nullptr) {
            if(abs(target-cur->val)<res) {
                res=abs(target-cur->val);
                res_i = i;
            }
            cur=cur->next;
            i++;
        }
        cout<<res_i;
    }
};


int main() {
    Linkedlist list;
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++) {
        int x;
        cin>>x;
        list.pushBack(x);
    }
    ll t;
    cin>>t;
    list.less_number(t);
    
}