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

//Brute Force Approach
node* kthFromEnd(node*head,int k){
  if(head==NULL || head->next==NULL){
    return head;
  }
  int l=length(head),c=0;
  node*temp=head;
  while(){
    temp=temp->next;
    c++;
  }
  return temp;
}

//2-pointer Technique
node* kthFromEnd(node*head,int k){
  if(head==NULL || head->next==NULL){
    return head;
  }
  node* f=head,s=head;
  while(){}
  while(){}
  return s;
}
