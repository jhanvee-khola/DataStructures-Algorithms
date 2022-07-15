#include<bits/stdc++.h> 
using namespace std; 

struct LNode{
    int data;
    struct LNode* next;
    struct LNode* prev;

    LNode(int x){
        data=x;
        next=NULL;
        prev=NULL;
    }
};

struct TNode  {  
    int data;  
    struct TNode* left;  
    struct TNode* right; 
    TNode(int x){
        data=x;
        left=right=NULL;
    }
}; 

//Method 1
TNode* bstFromLL(LNode *head,LNode *tail){
    if(head==tail){
        return NULL;
    }
    LNode *slow=head,*fast=head;
    while(fast!=tail && fast->next!=tail){
        fast=fast->next->next;
        slow=slow->next;
    }
    TNode *tree=new TNode(slow->data);
    tree->left=bstFromLL(head,slow);
    tree->right=bstFromLL(slow->next,tail);
    return tree;
}
TNode* sortedListToBST(LNode *head){
    TNode *tree=bstFromLL(head,NULL);
    return tree;
}

//Method 2
LNode *ans=NULL;
LNode* DLLToBST(LNode *head,LNode *tail){
    if(head==tail){
        return NULL;
    }
    LNode *slow=head,*fast=head;
    while(fast!=tail && fast->next!=tail){
        slow=slow->next;
        fast=fast->next->next;
    }
    if(!ans){
        ans=slow;
    }
    slow->prev=DLLToBST(head,slow);
    slow->next=DLLToBST(slow->next,tail);
    return slow;
}
void sortedDLLToBST(LNode *head){
    head=DLLToBST(head,NULL);
}
