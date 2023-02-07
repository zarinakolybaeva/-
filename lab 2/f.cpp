#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    int index;
    Node * next;
    Node * prev;
    Node(int val) {
        this->val=val;
        next=nullptr;
        prev=nullptr;
    }
};


class Linkedlist{
    Node * head;
    Node * tail;
public:
    Linkedlist() {
        head=tail=nullptr;
    }

    void push(int val) {
        Node * newNode = new Node(val);
        if(head==nullptr) {
            head=newNode;
            tail=newNode;
        }
        else {
            tail->next=newNode;
            newNode->prev=tail;
            tail=newNode;
        }
    }


    void insertion(int pos, int val) {
        Node * newNode=new Node(val);
        if(head==nullptr) {
            head=newNode;
        }
        else{
            Node * cur = head;
            int i=1;
            while(cur!=nullptr) {
                if(pos==0) {
                    head->prev=newNode;
                    newNode->next=head;
                    head=newNode;
                    break;
                }

                else if(i==pos) {
                    newNode->next=cur->next;
                    cur->next=newNode;
                    break;
                }
                cur=cur->next;
                i++;

            }
        }
    }

    void print() {
        Node * cur =head;
        while(cur!=nullptr) {
            cout<<cur->val<<" ";
            cur=cur->next;
        }
    }
};


int main() {
    Linkedlist list;
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        list.push(x);
    }
    int number, position;
    cin>>number>>position;
    list.insertion(position, number);
    list.print();

}