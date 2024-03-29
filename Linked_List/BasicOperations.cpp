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

//Insertion
void insertAtHead(node*&head, int d){
  if(head==NULL){
    head=new node(d);
    return;
  }
  node* n= new node(d);
  n->next=head;
  head=n;
}
void insertAtTail(node*&head, int d){
  if(head==NULL){
    head=new node(d);
    return;
  }
  node*tail=head;
  while(tail->next!=NULL){
    tail=tail->next;
  }
  head->next=new node(d);
}
void insertInMiddle(node*&head,int d,int p){
  if(head==NULL || p==0){
    insertAtHead(head,d);
  }
  else if(p>length(head)){
    insertAtTail(head,d);
  }
  else{
    int jump=1;
    node* n= new node(d);
    node* temp=head;
    while(jump<p){
      temp=temp->next;
      jump++;
    }
    n->next=temp->next;
    temp->next=n;
  }
}

//Printing
void print(node*head){
  while(head!=NULL){
    cout<<head->data<<" ";
    head=head->next;
  }
  cout<<endl;
}

//Deletion
void deleteHead(node*&head){
  if(head==NULL){
    return;
  }
  node* temp=head->next;
  delete head;
  head=temp;
}
void deleteTail(node*head){
  if(head==NULL){
    return;
  }
  if(head->next==NULL){
    delete head;
    return;
  }
  node* temp=head;
  while((temp->next)->next!=NULL){
    temp=temp->next;
  }
  delete (temp->next);
  temp->next=NULL;
}
void deleteMiddle(node*head,int p){
  if(head==NULL){
    return;
  }
  if(p=0){
    deleteHead(head);
  }
  else if(p>length(head)){
    deleteTail(head);
  }
  else{
    int c=0;
    node* temp=head;
    while(c<p-1){
      temp=temp->next;
      c++;
    }
    temp->next=temp->next->next;
    delete (temp->next);
  }
  return;
}

//Input
node* input(){
  node* head=NULL;
  int d;
  cin>>d;
  while(d!=-1){
    insertAtTail(&head,d);
    cin>>d;
  }
  return head;
}

//Updation
void update(node*head,int p,int d){
  int c=0;
  node* temp=head;
  while(c<p){
    temp=temp->next;
    c++;
  }
  temp->data=d;
}

//Searching
int search(node*head,int k){
  node* temp=head;
  int c=0;
  while(temp!=NULL){
    if(temp->data==k){
      return c;
    }
    c++;
    temp=temp->next;
  }
  return -1;
}
