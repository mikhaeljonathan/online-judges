#include <stdio.h>
#include <stdlib.h>

struct node{
	int key;
	int height;
	int sizeleft;
	int sizeright;
	node *left;
	node *right;
};

int getHeight(struct node *Node){
	if(Node == NULL) return 0;
	else{
		return Node->height;
	}
}

int getBF(struct node *Node){
	if(Node == NULL) return 0;
	else{
		return getHeight(Node->left) - getHeight(Node->right);
	}
}

int max(int left, int right){
	if(left > right) return left;
	else return right;
}

struct node *newnode(int key){
	struct node *curr = (struct node *) malloc (sizeof(struct node));
	curr->key = key;
	curr->height = 1;
	curr->sizeleft = curr->sizeright = 0;
	curr->left = NULL;
	curr->right = NULL;
	return curr;
}

struct node *leftrotate(struct node *root){
	struct node *newRoot = root->right;
	struct node *x = newRoot->left;
	
	newRoot->left = root;
	root->right = x;
	
	if (x) root->sizeright = x->sizeleft + x->sizeright + 1;
	else root->sizeright = 0;
	newRoot->sizeleft = root->sizeleft + root->sizeright + 1;
	
	root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
	newRoot->height = max(getHeight(newRoot->left), getHeight(newRoot->right)) + 1;
	
	return newRoot;
}

struct node *rightrotate(struct node *root){
	struct node *newRoot = root->left;
	struct node *x = newRoot->right;
	
	newRoot->right = root;
	root->left = x;
	
	if (x) root->sizeleft = x->sizeleft + x->sizeright + 1;
	else root->sizeleft = 0;
	newRoot->sizeright = root->sizeleft + root->sizeright + 1;
	
	root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
	newRoot->height = max(getHeight(newRoot->left), getHeight(newRoot->right)) + 1;
	
	return newRoot;
}

struct node *insert(struct node *Node, int key){
	if(Node == NULL) return newnode(key);
	else if(key < Node->key){
		(Node->sizeleft)++;
		Node->left = insert(Node->left, key);
	}
	else if(key > Node->key){
		(Node->sizeright)++; 
		Node->right = insert(Node->right, key);
	} else {
		return Node;
	}
	
	Node->height = max(getHeight(Node->left), getHeight(Node->right)) + 1;
	
	int bf = getBF(Node);
	
	if(bf < -1 && key > Node->right->key){
		//LL
		return leftrotate(Node);
	}
	if(bf < -1 && key < Node->right->key){
		//RL
		Node->right = rightrotate(Node->right);
		return leftrotate(Node);
	}
	if(bf > 1 && key < Node->left->key){
		//RR
		return rightrotate(Node);
	}
	if(bf > 1 && key > Node->left->key){
		//LR
		Node->left = leftrotate(Node->left);
		return rightrotate(Node);
	}
	return Node;
}

struct node* find(struct node* root, int x){
	if (!root) return NULL;
	if (x < root->key) return find(root->left, x);
	else if (x > root->key) return find(root->right, x);
	else return root;
}

int findindex(struct node* root, int x){
	if (!root) return 0;
	if (x < root->key) return findindex(root->left, x);
	else if (x > root->key) return findindex(root->right, x) + root->sizeleft + 1;
	else return root->sizeleft + 1;
}

void freeall(struct node* root){
	if (!root) return;
	freeall(root->left);
	freeall(root->right);
	free(root);
}

int main (){
	int q;
	scanf("%d", &q);
	struct node* root = NULL;
	while (q--){
		int com, x;
		scanf("%d %d", &com, &x);
		if (com == 1){
			root = insert(root, x);
		} else {
			if (!find(root, x)) printf("Data tidak ada\n");
			else printf("%d\n", findindex(root, x));
		}
	}
	freeall(root);
	root = NULL;
	return 0;
}
