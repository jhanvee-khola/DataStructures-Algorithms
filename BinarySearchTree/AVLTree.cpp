//AVL tree is a self-balancing Binary Search Tree (BST) where the difference between heights of left and right subtrees cannot be more than one for all nodes. 

// C++ program to insert a node in AVL tree
#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
	int val;
	Node *left;
	Node *right;
	int height;
};
Node* newNode(int key){
	Node* node = new Node();
	node->val = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1; // new node is initially added at leaf
	return(node);
}

// A utility function to right
// rotate subtree rooted with y
Node *rightRotate(Node *y){
	Node *x=y->left;
	Node *T2=x->right;

	// Perform rotation
	x->right=y;
	y->left=T2;

	// Update heights
	y->height=max(y->left->height,y->right->height)+1;
	x->height = max(x->left->height,x->right->height)+1;

	// Return new root
	return x;
}

// A utility function to left
// rotate subtree rooted with x
Node *leftRotate(Node *x){
	Node *y=x->right;
	Node *T2=y->left;

	// Perform rotation
	y->left=x;
	x->right=T2;

	// Update heights
	x->height=max(x->left->height,x->right->height)+1;
	y->height=max(y->left->height,y->right->height)+1;

	// Return new root
	return y;
}

// Get Balance factor of node N
int getBalance(Node *N){
	if(N == NULL)
		return 0;
	return (N->left->height)-(N->right->height);
}

// Recursive function to insert a key
// in the subtree rooted with node and
// returns the new root of the subtree.
Node* insert(Node* node, int key){
	/* 1. Perform the normal BST insertion */
	if(node == NULL)
		return(newNode(key));

	if(key<node->val)
		node->left=insert(node->left, key);
	else if(key>node->val)
		node->right=insert(node->right, key);
	else // Equal keys are not allowed in BST
		return node;

	/* 2. Update height of this ancestor node */
	node->height=1+max(node->left->height,node->right->height);

	/* 3. Get the balance factor of this ancestor
		node to check whether this node became
		unbalanced */
	int balance=getBalance(node);

	// If this node becomes unbalanced, then
	// there are 4 cases

	// Left Left Case
	if(balance>1 && key<node->left->val)
		return rightRotate(node);

	// Right Right Case
	if(balance<-1 && key>node->right->val)
		return leftRotate(node);

	// Left Right Case
	if(balance>1 && key>node->left->val){
		node->left=leftRotate(node->left);
		return rightRotate(node);
	}

	// Right Left Case
	if(balance<-1 && key<node->right->val){
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	/* return the (unchanged) node pointer */
	return node;
}

// A utility function to print preorder
// traversal of the tree.
// The function also prints height
// of every node
void preOrder(Node *root){
	if(root != NULL){
		cout<<root->val<<" ";
		preOrder(root->left);
		preOrder(root->right);
	}
}

int main(){
	Node *root = NULL;
	
	/* Constructing tree given in
	the above figure */
	root = insert(root, 10);
	root = insert(root, 20);
	root = insert(root, 30);
	root = insert(root, 40);
	root = insert(root, 50);
	root = insert(root, 25);
	
	/* The constructed AVL Tree would be
				30
			/ \
			20 40
			/ \ \
		10 25 50
	*/
	cout<<"Preorder traversal of the constructed AVL tree is \n";
	preOrder(root);
	
	return 0;
}
