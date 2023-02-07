#include<bits/stdc++.h>
using namespace std;
struct node{
    int val;
    node* next;
    node(){
        this->val=0;
        this->next=NULL;
    }
    node(int val){
        this->val=val;
        this->next=NULL;
    }
    node(int val,node* next){
        this->val=val;
        this->next=next;
    }
};
struct linked_list{
    int size;
    node* head;
    node* tail;
    linked_list(){
        this->size=0;
        this->head=NULL;
        this->tail=NULL;
    }
    
    void addend(int val){
        this->size++;
        node* cur=new node(val);
        if(this->head==NULL){
            this->head=cur;
            this->tail=cur;
        }
        else {
            this->tail->next=cur;
            this->tail=cur;
        }
    }

    void solve(int target){
        node* cur=this->head;
        int res=100000;
        int i=0;
        int res_i;
        while(cur!=NULL){
            if(abs(target-cur->val)<res){
                res=abs(target-cur->val);
                res_i=i;
            }
            cur=cur->next;
            i++;
        }
        cout<<res_i;
    }

};



int main (){
linked_list noden;
int n;
cin>>n;
for(int i=0;i<n;i++){
    int x;
    cin>>x;
    noden.addend(x);
}
int t;
cin>>t;
noden.solve(t);
}