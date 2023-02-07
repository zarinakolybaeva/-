#include <bits/stdc++.h>
using namespace std;


struct Node{
    int val;
    Node* next;
    Node* prev;
    int cnt;
    Node(int val) {
        this->val=val;
        cnt=1;
        next=NULL;
        prev=NULL;
    }
};

class Modes{
    Node* head;
    int max=-1e6;
public:
    Modes() {
        head=NULL;
    }
    void push(int val) {
        Node* newNode = new Node(val);

        if(head==NULL) {
            head=newNode;
        }
        else{
            Node * cur = head;
            while(cur!=NULL) {
                if(cur->val == val) {
                    cur->cnt++;
                    break;
                }
                if(cur->next==NULL) {
                    cur->next=newNode;
                    break;
                }
                cur=cur->next;
            }
        }
    }
    void maxi() {
        Node * cur = head;
        while(cur!=NULL) {
            if(cur->cnt>max) max=cur->cnt;
            cur=cur->next;
        }
    }
    void sort() {
        Node * first = head;
        Node * second = NULL;
        while(first!=NULL) {
            second=first->next;
             while(second!=NULL) {
                if(first->val < second->val) {
                    swap(first->val, second->val);
                    swap(first->cnt, second->cnt);
                }
                if(first->cnt > second->cnt){
                    swap(first->val, second->val);
                    swap(first->cnt, second->cnt);
                }
                second=second->next;
            }
            first=first->next;
        }
    }

    void print() {
        Node * cur = head;
        while(cur!=NULL) {
            sort();
            if(cur->cnt==max) cout<<cur->val<<" ";
            cur=cur->next;
        }
    }

};

int main() {
    Modes list;
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        list.push(x);
    }
    list.maxi();
    list.print();
}