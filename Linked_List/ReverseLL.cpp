#inculde<iostream>
using namespace std;

//Creating
class node{
  public:
    int data;
    node* next;
  
    node(int d){
      data=d;
      next=NULL:
    }
};

//Iterative Approach
void reverse(node*&head){
  node* curr=head,prev=NULL,temp;;
  while(curr!=NULL){
    temp=curr->next;
    curr->next=prev;
    prev=curr;
    curr=temp;
  }
  head=prev;
}

//Recursive Approach
