//Cycle detection in an LL

bool detectCycle(node* head){
  node* s=head,f=head;
  while(f!=NULL && f->next!=NULL){
    if(f==s){
      return true;
    }
    s=s->next;
    f=f->next->next;
  }
  return false;
}

//Removal of cycle from an LL(Floyd's Algorithm)
void removeCycle(node* head){
  node* s=head,f=head;
  while(f!=NULL && f->next!=NULL){
    if(f==s){
      break;
    }
    s=s->next;
    f=f->next->next;
  }
  s=head;
  while(s->next!=f->next){
    s=s->next;
    f=f->next;
  }
  f->next=NULL;
}
