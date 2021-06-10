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

struct node *predecessor(struct node *Node){
	struct node *curr = Node->left;
	while(curr->right){
		curr = curr->right;
	}
	return curr;
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

struct node *deleteKey(struct node *Node, int key){
	if(Node == NULL) return NULL;
	else if(key < Node->key){
		(Node->sizeleft)--;
		Node->left = deleteKey(Node->left, key);
	}
	else if(key > Node->key){
		(Node->sizeright)--;
		Node->right = deleteKey(Node->right, key);
	}
	else{
		//key is found
		
		if(Node->left == NULL || Node->right == NULL){
			//case ga punya anak
			struct node *temp = NULL;
			if(Node->left) temp = Node->left;
			else temp = Node->right;
			if(temp == NULL){
				temp = Node;
				Node = NULL;
			}
			else{
				//punya anak kiri atau kanan
				*Node = *temp;
			}
			free(temp);
		}
		else{
			//punya 2 anak
			struct node *pred = predecessor(Node);
			Node->key = pred->key;
			(Node->sizeleft)--;
			Node->left = deleteKey(Node->left, pred->key);
		}
	}
	if(Node == NULL) return NULL;
	Node->height = max(getHeight(Node->left), getHeight(Node->right)) + 1;
	int bf = getBF(Node);
	
	if(bf < -1 && getBF(Node->right) <= 0){
		//LL
		return leftrotate(Node);
	}
	if(bf > 1 && getBF(Node->left) >= 0){
		//RR
		return rightrotate(Node);
	}
	if(bf > 1 && getBF(Node->left) < 0){
		//LR
		Node->left = leftrotate(Node->left);
		return rightrotate(Node);
	}
	if(bf < -1 && getBF(Node->right) > 0){
		//RL
		Node->right = rightrotate(Node->right);
		return leftrotate(Node);
	}
	return Node;
}

struct node* find(struct node* root, int x){
	if (!root) return NULL;
	if (x < root->key) return find(root->left, x);
	else if (x > root->key) return find(root->right, x);
	else return root;
}

int findith(struct node* Node, int k){
	if (Node->sizeleft == k) return Node->key;
	
	if (k < Node->sizeleft) return findith(Node->left, k);
	else return findith(Node->right, k - Node->sizeleft - 1);
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
	int com;
	struct node* root = NULL;
	while (scanf("%d", &com) && com != -1){
		int n;
		scanf("%d", &n);
		if (com == 1){
			root = insert(root, n);
		} else if (com == 2){
			root = deleteKey(root, n);
		} else if (com == 3){
			if (!find(root, n)) printf("-1\n");
			else printf("%d\n", findindex(root, n));
		} else {
			n--;
			if (!root || n == -1 || n > root->sizeleft + root->sizeright) printf("-1\n");
			else printf("%d\n", findith(root, n));
		}
	}
	
	freeall(root);
	root = NULL;
	return 0;
}
