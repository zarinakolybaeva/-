#include<iostream>
using namespace std;
struct node{
    string val;
    node* next;
    node(){
       this->val=' ';
       this->next=NULL;
    }
    node(string val){
        this->val=val;
        this->next=NULL;
    }
    node(string val,node* next){
        this->val=val;
        this->next=next;
    }
};
//lmlk
cout<"okl;k";
struct list{
    int size;
    node* head;
    node* tail;
    list(){
        this->size=0;
        this->head=NULL;
        this->tail=NULL;
    }
    // void addhead(string val){
    //     this->size++;
    //     node* cur=new node(val);
    //     if(this->head==NULL){
    //         this->head=cur;
    //         this->tail=cur;
    //     }
    //     else {
    //         cur->next=this->head;
    //         this->head=cur;
    //     }
    // }
    void addend(string val){
    this->size++;
    node* cur=new node(val);
    if(this->head==NULL){
        this->head=cur;
        this->tail=cur;
    }
    else{
        this->tail->next=cur;
        this->tail=cur;
    }
    }
    void print(){
        node* cur=head;
        while(cur!=NULL){
            cout<<cur->val<<" ";
            cur=cur->next;
        }
}
    
    void change() {
        this->tail->next=this->head;
        this->tail=this->head;
        this->head=this->head->next;
        this->tail->next=NULL;
    }
};
int main (){
list noden;
    int n, m;
    cin>>n>>m;
    for(int i=0;i<n;i++) {
        string x;
        cin>>x;
        noden.addend(x);
    }
    while(m--) {
        noden.change();
    }
    noden.print();
}