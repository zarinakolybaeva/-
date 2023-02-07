#include<bits/stdc++.h>
using namespace std;
struct node{
    node* left;
    node* right;
    int key;
    node(){
        left=right=NULL;
        key=0;
    }
    node(int _key=0){
        left=right=NULL;
        key=_key;
    }
    node(int key,node*left,node*right)
        : key(key), left(left),right(right){

        }
};
struct BST{ 
    node* root;
    void insert(node*cur,int x){
     node* next=NULL;
     if(x<=cur->key){
        if(cur->left==NULL){
            cur->left=new node(x);
            return ;
        }
      next=cur->left;
     }
     else {
        if(cur->right==NULL){
            cur->right=new node(x);
            return ;
        }
     next=cur->right;
     }
    insert(next,x);
    }
    void insert(int x){
        if(root==NULL)
        root=new node(x);
        else
        insert(root,x);
    }

    node* find(node* cur,int x){
    if(x==cur->key)
      return cur;
    if(x<cur->key)
      return cur->left==NULL ? NULL : find(cur->left,x) ;
      
      // if left is null then return null ':' else 
      return cur->right==NULL 
      ? NULL 
      : find(cur->right,x);
    }    
    node* find(int x){
        return find(root,x);
    }
    void print(node*cur,int tab=1){
        if(cur!=NULL)
        printf("[%d]\n",cur->key);
        else
        puts("");
        for(int i=0;i<tab;i++) purchar('\t');
        printf('L');
        print(cur->left,tab+1);
        for(int i=0;i<tab;i++) purchar('\t'); 
        printf("R";
        print(cur->right,tab+1));

    }
    void print(){
    print(root);
    }
    node* del(node* cur,int x){
        if(cur==NULL)
        return NULL;
        if(x<cur->key){
            cur->left=del(cur->left,x);
        }
        else if(cur->key<x){
            cur->right=del(cur->right,x)
        }
        else { // cur->key=x
        if(cur->left==NULL && cur->right==NULL){
             delete cur;
             return NULL;
        }

        if(cur->left!=NULL || cur->right!=NULL){
        node* newnode=cur->left!=NULL;
        ?cur->left;
        ?cur->right;
        delete cur;
        return next;
        }
        node* next=cur->right;
        while(next->left!=NULL)
        next=next->left;
        cur->key=next->key;
        cur->right=del(cur->right,next->key);

        }
        }
    }
    void del(int x){
    root=del(root,x);
    }bst;

int main (){
BST bst;
bst.insert(6);
bst.insert(7);
bst.insert(4);
bst.insert(1);
bst.insert(5);
bst.print();
}