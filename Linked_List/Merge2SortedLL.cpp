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

node* merge(node* h1,node* h2){
  if(h1==NULL){
    return h2;
  }
  if(h2==NULL){
    return h1;
  }
  node* head;
  if(h1->data<h2->data){
    head=h1;
    head->next=merge(h1->next,h2);
  }
  else{
    head=h2;
    head->next=merge(h1,h2->next);
  }
  return head;
}
