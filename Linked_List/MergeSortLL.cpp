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

//Finding mid-point
node* midPoint(node*head){
  if(head->next==NULL || head==NULL){
    return head;
  }
  node* f=head->next,s=head;
  while(f!=NULL && f->next!=NULL){
    f=f->next->next;
    s=s->next;
  }
  return s;
}

//Merging 2 sorted LLs
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

node* mergeSort(node* head){
  if(head==NULL || head->next=NULL){
    return head;
  }
  node* mid=midPoint(head);
  node* h1=head;
  node*h2=mid->next;
  mid->next=NULL;
  h1=mergeSort(h1);
  h2=mergeSort(h2);
  return merge(h1,h2);
}
