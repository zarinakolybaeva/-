#include<iostream>
using namespace std;
class Solution{
    public:
    Node* middlenode(Node* head){
      Node* bolek=head,*lelek=head;
      while(lelek->next!=NULL){
        if(lelek->next->next!=NULL)
        lelek=lelek->next->next;
      else {
        lelek=lelek->next;
      }
      bolek=bolek->next;
      }
      return bolek;
    }

};
int main (){

}