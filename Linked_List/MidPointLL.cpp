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

//Length
int length(node*head){
  int l=0;
  while(head!=NULL){
    head=head->next;
    l++;
  }
  return l;
}

//Brute Force
node* midPoint(node*head){
  if(head->next==NULL || head==NULL){
    return head;
  }
  int l=length(head);
  int n=l/2,c=0;
  if(n%2==0){
    n-=1;
  }
  node* temp=head;
  while(c<n){
    temp=temp->next;
    c++;
  }
  return temp;
}

//Runner Technique(2-pointer)
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
