#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node * prev;
    Node * next;
    Node(int val) {
        this->val=val;
        next=nullptr;
        prev=nullptr;
    }
};

class Ragnarok{
public:
    Node * head;
    Node * tail;
    int res, mx;
    Ragnarok() {
        head=tail=nullptr;
        res=-1e6;
        mx=0;
    }
    void push(int val) {
        Node * newNode = new Node(val);
        if(head==nullptr) {
            head=tail=newNode;
        }
        else {
            // if(sum_front>mx) cout<<mx<<endl;
            tail->next=newNode;
            newNode->prev=tail;
            tail=newNode;
        }
        // cout<<sum_front<<endl;
    }

    void sub() {
        Node * cur = head;
        while(cur!=nullptr) {
            mx+=cur->val;
            if(mx<cur->val) mx=cur->val;
            res=max(mx, res);
            cur=cur->next;
        }
        cout<<res<<endl;
    }
};

int main() {
    Ragnarok list;
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        list.push(x);
    }
    list.sub();

}