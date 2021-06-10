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

int findkth(struct node* Node, int k){
	if (Node->sizeleft == k) return Node->key;
	
	if (k < Node->sizeleft) return findkth(Node->left, k);
	else return findkth(Node->right, k - Node->sizeleft - 1);
}

int countpreceding(struct node* Node, int x){
	if (!Node) return 0;
	if (x <= Node->key){
		return countpreceding(Node->left, x);
	} else {
		return countpreceding(Node->right, x) + Node->sizeleft + 1;
	};
}

struct node* find(struct node* root, int x){
	if (!root) return NULL;
	if (x < root->key) return find(root->left, x);
	else if (x > root->key) return find(root->right, x);
	else return root;
}

void freeall(struct node* root){
	if (!root) return;
	freeall(root->left);
	freeall(root->right);
	free(root);
}

int main (){
	int q;
	scanf("%d", &q); getchar();
	struct node* root = NULL;
	while (q--){
		char com;
		int x;
		scanf("%c %d", &com, &x); getchar();
		if (com == 'I'){
			if (!find(root, x)) root = insert(root, x);
		} else if (com == 'D'){
			if (find(root, x)) root = deleteKey(root, x);
		} else if (com == 'K'){
			x--;
			if (!root || x == -1 || x > root->sizeleft + root->sizeright) printf("invalid\n");
			else printf("%d\n", findkth(root, x));
		} else {
			printf("%d\n", countpreceding(root, x));
		}
	}
	freeall(root);
	root = NULL;
	return 0;
}
