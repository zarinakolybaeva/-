#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node* prev;
    Node(int val) {
        this->val=val;
        next=NULL;
        prev=NULL;
    }
};
class Kuanyshbek{
    Node* head;
    Node* tail;
public:
    Kuanyshbek() {
        head=NULL;
        tail=NULL;
    }

    void push(int val) {
        Node * newNode = new Node(val);
        if(head==NULL) {
            head=tail=newNode;
        }
        else{
            tail->next=newNode;
            newNode->prev=tail;
            tail=newNode;
        }
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
    Kuanyshbek list;
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        if(i%2==0) list.push(x);
    }
    list.print();

}