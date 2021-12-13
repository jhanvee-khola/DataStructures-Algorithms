//Given only a pointer/reference to a node to be deleted in a singly linked list, how do you delete it?

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

void deleteNode(node* n){
  if(n==NULL){
    return;
  }
  node* prev=node;
  while(node->next!=NULL){
    node->data=node->next->data;
    prev=node;
    node=node->next;
  }
  prev->next=NULL;
}
//This method does not work when the node to be deleted is the last node of the LL
