#include <bits/stdc++.h>
using namespace std;

struct Node{
    string val;
    Node* next;
    Node*prev;
    Node(string val) {
        this->val=val;
        next=nullptr;
        prev=nullptr;
    }
};

class Doubly{
public:
    Node* head;
    Node* tail;
    int sz;
    Doubly() {
        head=tail=nullptr;
        sz=0;
    }

    void push_back(string val) {
        Node* newNode = new Node(val);
        if(head==nullptr) {
            head=tail=newNode;
        }
        else{
            tail->next=newNode;
            newNode->prev=tail;
            tail=newNode;
        }
        sz++;
    }

    void push_front(string val) {
        Node * newNode = new Node(val);
        if(head==nullptr) {
            head=tail=newNode;
        }
        else{
            head->prev=newNode;
            newNode->next=head;
            head=newNode;
        }
        // cout<<head->val<<endl;
        sz++;
    }

    void erase_back() {
        // Node * cur = head;
        // while(cur!=nullptr) {
        //     if(cur->next=tail) {
        //         cur->next=nullptr;
        //     }
        // }
        cout<<tail->val<<endl;
        if(tail->prev==nullptr) {
            tail=head=nullptr;
        }
        else{
            tail=tail->prev;
            tail->next->prev=nullptr;
            tail->next=nullptr;
        }
        sz--;
    }
    void erase_front(){
        cout<<head->val<<endl;
        if(head->next==nullptr) {
            head=tail=nullptr;
        }
        else{
            head=head->next;
            head->prev->next=nullptr;
            head->prev=nullptr;
        }
        sz--;

    }

    void front() {
        cout<<head->val<<endl;
    }
    void back() {
        cout<<tail->val<<endl;
    }
    void clear() {
        head=tail=nullptr;
        sz=0;
    }

};

int main() {
    Doubly list;
    string s, t;
    while(cin>>s) {
        if(s=="add_front") {
            cin>>t;
            list.push_front(t);
            cout<<"ok"<<endl;
        }
        if(s=="add_back") {
            cin>>t;
            list.push_back(t);
            cout<<"ok"<<endl;
        }
        if(s=="front") {
            if(list.sz == 0) cout<<"error"<<endl;
            else list.front();
        }
        if(s=="back") {
            if(list.sz == 0) cout<<"error"<<endl;
            else list.back();
        }
        if(s=="erase_front") {
            if(list.sz == 0) cout<<"error"<<endl;
            else list.erase_front();
        }
        if(s=="erase_back") {
            if(list.sz == 0) cout<<"error"<<endl;
            else list.erase_back();
        }
        if(s=="clear") {
            list.clear();
            cout<<"ok"<<endl;
        }
        if(s=="exit") {
            cout<<"goodbye"<<endl;
            return 0;
        }
    }
}