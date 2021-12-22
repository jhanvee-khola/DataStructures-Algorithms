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
  node* curr=head,prev=NULL,temp;
  while(curr!=NULL){
    temp=curr->next;
    curr->next=prev;
    prev=curr;
    curr=temp;
  }
  head=prev;
}

//Recursive Approach
node* recReverse(node*head){
  if(head==NULL || head->next==NULL){
    return head;
  }
  node* shead=recReverse(head->next);
  node* temp=shead;
  while(temp->next!=NULL){
    temp=temp->next;
  }
  temp->next=head;
  head->next=NULL;
  return shead;
}

//Optimised Recursive Approach
node* reverse(node*&head){
  if(head==NULL || head->next==NULL){
    return head;
  }
  node* shead=reverse(head->next);
  head->next->next=head;
  head->next=NULL;
  return shead;
}
