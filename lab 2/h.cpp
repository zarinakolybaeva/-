#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node* prev;
    Node(int val) {
        this->val=val;
        next=nullptr;
        prev=nullptr;

    }
};

class Zoro {
public:
    Node* head;
    Node* tail;
    int size;
    Zoro() {
        head=tail=nullptr;
        size=0;
    }
    void insert(int pos, int val) {
        Node* newNode = new Node(val);
        if(head==nullptr && pos==0) {
            head=tail=newNode;
        }
        else if(pos==0 && head!=nullptr) {
            head->prev=newNode;
            newNode->next=head;
            head=newNode;
        }
            Node * cur = head;
            int i=1;
            while(cur!=nullptr) {
                if(pos==i) {
                    newNode->next=cur->next;
                    cur->next=newNode;
                    break;

                }
                cur=cur->next;
                i++;
            }
        if(pos>size) {
            tail->next=newNode;
            newNode->prev=tail;
            tail=newNode;
        }
        size++;
    }

    void del_pos(int pos) {
        int i=1;
        if(pos==1) {
            head=head->next;
        }
        else{
            Node * cur =head;
            Node * prev = nullptr;
            while(cur!=nullptr) {
                if(i==pos) {
                    prev->next=cur->next;
                    delete cur;
                    return;
                }
                prev=cur;
                cur=cur->next;
                i++;
            }
        }
        size--;
    }

    void replace(int pos1, int pos2){
        Node * cur =head;
        int i=1;
        while(cur!=nullptr) {
            int k1, k2, t;
            if(i==pos1) {
                k1=cur->val;
            }
            if(i==pos2) {
                k2=cur->val;
            }
            // t=k1;
            if(i==pos2) cur->val=k1;
            if(i==pos1) cur->val=k2;
            
            i++;
            cur=cur->next;
        }
    }
    void reverse() {
        Node * cur = head;
        Node * prev = nullptr;
        Node * next = nullptr;
        while(cur!=nullptr) {
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
    head=prev;
    }
    void cyclic_left(int k){
        Node* cur = head;
        while(cur -> next != NULL){
            cur = cur -> next;
        }
        while(k--){
            Node* NewNode = new Node(head -> val);
            cur -> next = NewNode;
            NewNode -> prev = cur;
            cur = NewNode;
            Node* temp = head;
            head = temp -> next;
            head -> prev = NULL;
        }
    }
    void cyclic_right(int k){
        Node* cur = head;
        while(cur -> next != NULL){
            cur = cur -> next;
        }
        while(k--){
            Node* NewNode = new Node(cur -> val);
            head -> prev = NewNode;
            NewNode -> next = head;
            head = NewNode;
            Node* temp = cur;
            cur = temp -> prev;
            cur -> next = NULL;
        }
    }

    void print() {
        Node * cur = head;
        while(cur!=nullptr){
            cout<<cur->val<<" ";
            cur=cur->next;
        }
        cout<<endl;
    }
};

int main(){
    Zoro list;
    int m;
    while(cin>>m){
        int x, p;
        int p1, p2;
        if(m==1) {
            cin>>x>>p;
            list.insert(p, x);
        }
        if(m==2) {
            cin>>p;
            list.del_pos(p);
        }
        if(m==3) {
            if(list.size == 0) cout<<-1<<endl;
            else {
                list.print();
            }
        }
        if(m==4) {
            cin>>p1>>p2;
            list.replace(p1, p2);
        }
        if(m==5) {
            list.reverse();
        }
        if(m==6) {
            cin>>x;
                list.cyclic_left(x);
        }
        if(m==7) {
            cin>>x;
                list.cyclic_right(x);
        }
        if(m==0) {
            return 0;
        }
    }
}