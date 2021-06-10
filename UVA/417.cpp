#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
	int key;
	int height;
	char val[10];
	struct node* left;
	struct node* right;
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

struct node *newnode(char s[], int key){
	struct node *curr = (struct node *) malloc (sizeof(struct node));
	curr->key = key;
	curr->height = 1;
	strcpy(curr->val, s);
	curr->left = NULL;
	curr->right = NULL;
	return curr;
}

struct node *leftrotate(struct node *root){
	struct node *newRoot = root->right;
	struct node *x = newRoot->left;
	
	newRoot->left = root;
	root->right = x;
	
	root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
	newRoot->height = max(getHeight(newRoot->left), getHeight(newRoot->right)) + 1;
	
	return newRoot;
}

struct node *rightrotate(struct node *root){
	struct node *newRoot = root->left;
	struct node *x = newRoot->right;
	
	newRoot->right = root;
	root->left = x;
	
	root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
	newRoot->height = max(getHeight(newRoot->left), getHeight(newRoot->right)) + 1;
	
	return newRoot;
}

struct node *insert(struct node *Node, char s[], int key){
	if(Node == NULL) return newnode(s, key);
	else if(strcmp(s, Node->val) < 0){
		Node->left = insert(Node->left, s, key);
	}
	else if(strcmp(s, Node->val) > 0){
		Node->right = insert(Node->right, s, key);
	}
	
	Node->height = max(getHeight(Node->left), getHeight(Node->right)) + 1;
	
	int bf = getBF(Node);
	
	if(bf < -1 && strcmp(s, Node->right->val) > 0){
		//LL
		return leftrotate(Node);
	}
	if(bf < -1 && strcmp(s, Node->right->val) < 0){
		//RL
		Node->right = rightrotate(Node->right);
		return leftrotate(Node);
	}
	if(bf > 1 && strcmp(s, Node->left->val) < 0){
		//RR
		return rightrotate(Node);
	}
	if(bf > 1 && strcmp(s, Node->left->val) > 0){
		//LR
		Node->left = leftrotate(Node->left);
		return rightrotate(Node);
	}
	return Node;
}

struct node* find(struct node* Node, char s[]){
	if (Node == NULL) return NULL;
	else if (strcmp(s, Node->val) < 0){
		return find(Node->left, s);
	} else if (strcmp(s, Node->val) > 0){
		return find(Node->right, s);
	} else {
		return Node;
	}
}

void inOrder(struct node* root){
	if (!root) return;
	
	inOrder(root->left);
	printf("%s %d\n", root->val, root->key);
	inOrder(root->right);
}

int main (){
	char s[10];
	int idx = 0;
	struct node* root = NULL;
	//length 1
	for (char i = 'a'; i <= 'z'; i++) {
		s[0] = i;
		s[1] = '\0';
		root = insert(root, s, ++idx);
	}
	
	//length 2
	for (char i = 'a'; i <= 'z'; i++) {
		s[0] = i;
		for (char j = i + 1; j <= 'z'; j++){
			s[1] = j;
			s[2] = '\0';
			root = insert(root, s, ++idx);
		}
	}
	
	//length 3
	for (char i = 'a'; i <= 'z'; i++) {
		s[0] = i;
		for (char j = i + 1; j <= 'z'; j++){
			s[1] = j;
			for (char k = j + 1; k <= 'z'; k++){
				s[2] = k;
				s[3] = '\0';
				root = insert(root, s, ++idx);
			}
		}
	}
	
	
	//length 4
	for (char i = 'a'; i <= 'z'; i++) {
		s[0] = i;
		for (char j = i + 1; j <= 'z'; j++){
			s[1] = j;
			for (char k = j + 1; k <= 'z'; k++){
				s[2] = k;
				for (char l = k + 1; l <= 'z'; l++){
					s[3] = l;
					s[4] = '\0';
					root = insert(root, s, ++idx);
				}
			}
		}
	}
	
	//length 5
	for (char i = 'a'; i <= 'z'; i++) {
		s[0] = i;
		for (char j = i + 1; j <= 'z'; j++){
			s[1] = j;
			for (char k = j + 1; k <= 'z'; k++){
				s[2] = k;
				for (char l = k + 1; l <= 'z'; l++){
					s[3] = l;
					for (char m = l + 1; m <= 'z'; m++){
						s[4] = m;
						s[5] = '\0';
						root = insert(root, s, ++idx);
					}
				}
			}
		}
	}
	
	char in[10];
	while (scanf("%s", in) != EOF){
		if (!find(root, in)) printf("0\n");
		else printf("%d\n", find(root, in)->key);
	}
	
	return 0;
}
