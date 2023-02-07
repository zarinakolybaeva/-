#include <bits/stdc++.h>
using namespace std;

struct Node{
    string val;
    Node* next;
    Node* prev;
    Node(string val) {
        this->val=val;
        next=NULL;
        prev=NULL;
    }
};

class Jonathan{
    Node* head;
    Node* tail;
public:
    Jonathan() {
        head=tail=NULL;
    }

    void push(string val) {
        Node* newNode = new Node(val);
        if(head==NULL) {
            head=tail=newNode;
        }
        else{
            tail->next=newNode;
            newNode->prev=tail;
            tail=newNode;
        }
    }

    void change() {
        tail->next=head;
        tail=head;
        head=head->next;
        tail->next=NULL;
    }

    void print() {
        Node* cur = head;
        while(cur!=NULL) {
            cout<<cur->val<<" ";
            cur=cur->next;
        }
    }
};
int main() {
    Jonathan poet;
    int n, m;
    cin>>n>>m;
    for(int i=0;i<n;i++) {
        string x;
        cin>>x;
        poet.push(x);
    }
    while(m--) {
        poet.change();
    }
    poet.print();

}