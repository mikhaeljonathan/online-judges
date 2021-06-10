#include <stdio.h>
#include <stdlib.h>

struct query{
	int i;
	int j;
	int k;
	int queries;
	int ans;
};

struct node{
	int val;
	int height;
	int leftchild;
	int rightchild;
	struct node* left;
	struct node* right;
};

void merge(struct query q[], int aleft, int aright, int bleft, int bright, int leftidx){
	int size = bright - aleft + 1;
	struct query temp[size];
	int aindex = aleft;
	int bindex = bleft;
	int tindex = 0;
	
	while (aindex <= aright && bindex <= bright){
		if (leftidx){
			if (q[aindex].i <= q[bindex].i) temp[tindex++] = q[aindex++];
			else temp[tindex++] = q[bindex++];
		} else {
			if (q[aindex].queries <= q[bindex].queries) temp[tindex++] = q[aindex++];
			else temp[tindex++] = q[bindex++];
		}
	}
	
	while (aindex <= aright) temp[tindex++] = q[aindex++];
	
	while (bindex <= bright) temp[tindex++] = q[bindex++];
	
	for (int i = 0; i < size; i++) q[aleft + i] = temp[i];
}

void mergeSort(struct query q[], int left, int right, int leftidx){
	if (left == right) return;
	
	int mid = (left + right) / 2;
	mergeSort(q, left, mid, leftidx);
	mergeSort(q, mid + 1, right, leftidx);
	merge(q, left, mid, mid + 1, right, leftidx);
}

struct node* newnode(int val){
	struct node* newn = (struct node*)malloc(sizeof(struct node));
	newn->val = val;
	newn->height = 1;
	newn->leftchild = newn->rightchild = 0;
	newn->left = newn->right = NULL;
	return newn;
}

int max(int a, int b){
	return (a > b) ? a : b;
}

int getheight(struct node* root){
	if (!root) return 0;
	else return root->height;
}

int getbf(struct node* root){
	if (!root) return 0;
	else return getheight(root->left) - getheight(root->right);
}

struct node* rightrotate(struct node* root){
	struct node* newroot = root->left;
	struct node* x = newroot->right;
	
	newroot->right = root;
	root->left = x;
	
	if (x) root->leftchild = x->leftchild + x->rightchild + 1;
	else root->leftchild = 0;
	newroot->rightchild = root->leftchild + root->rightchild + 1;
	
	root->height = max(getheight(root->left), getheight(root->right)) + 1;
	newroot->height = max(getheight(newroot->left), getheight(newroot->right)) + 1;
	
	return newroot;
}

struct node* leftrotate(struct node* root){
	struct node* newroot = root->right;
	struct node* x = newroot->left;
	
	newroot->left = root;
	root->right = x;
	
	if (x) root->rightchild = x->leftchild + x->rightchild + 1;
	else root->rightchild = 0;
	newroot->leftchild = root->leftchild + root->rightchild + 1;
	
	root->height = max(getheight(root->left), getheight(root->right)) + 1;
	newroot->height = max(getheight(newroot->left), getheight(newroot->right)) + 1;
	
	return newroot;
}

struct node* insertavl(struct node* root, int val){
	if (!root) return newnode(val);
	if (val <= root->val) {
		(root->leftchild)++;
		root->left = insertavl(root->left, val);
	} else {
		(root->rightchild)++;
		root->right = insertavl(root->right, val);
	}
	
	
	root->height = max(getheight(root->left), getheight(root->right)) + 1;
	int bf = getbf(root);
	
	if (bf < -1 && val > root->right->val)
		return leftrotate(root);
	if (bf > 1 && val < root->left->val)
		return rightrotate(root);
	if (bf < -1 && val < root->right->val){
		root->right = rightrotate(root->right);
		return leftrotate(root);
	}
	if (bf > 1 && val > root->left->val){
		root->left = leftrotate(root->left);
		return rightrotate(root);
	}
	return root;
}

struct node* findpred(struct node* root){
	struct node* curr = root->left;
	while (curr->right) curr = curr->right;
	return curr;
}

struct node* deleteavl(struct node* root, int val){
	if (!root) return NULL;
	if (val < root->val){
		(root->leftchild)--;
		root->left = deleteavl(root->left, val);
	} else if (val > root->val){
		(root->rightchild)--;
		root->right = deleteavl(root->right, val);
	} else {
		if (!root->left || !root->right){
			struct node* temp = root->left ? root->left : root->right;
			if (!temp){
				free(root);
				root = NULL;
				return root;
			} else {
				*root = *temp;
			}
		} else {
			struct node* pred = findpred(root);
			root->val = pred->val;
			(root->leftchild)--;
			root->left = deleteavl(root->left, pred->val);
		}
	}
	
	root->height = max(getheight(root->left), getheight(root->right)) + 1;
	int bf = getbf(root);
	
	if (bf < -1 && getbf(root->right) <= 0)
		return leftrotate(root);
	if (bf > 1 && getbf(root->left) >= 0)
		return rightrotate(root);
	if (bf < -1 && getbf(root->right) > 0){
		root->right = rightrotate(root->right);
		return leftrotate(root);
	}
	if (bf > 1 && getbf(root->left) < 0){
		root->left = leftrotate(root->left);
		return rightrotate(root);
	}
	return root;
}

int findkth(struct node* root, int k){
	if (k == root->leftchild) return root->val;
	
	if (k < root->leftchild) return findkth(root->left, k);
	else return findkth(root->right, k - root->leftchild - 1);
}

int main (){
	int n, m;
	scanf("%d %d", &n, &m);
	int prettyvalue[n + 1];
	struct query q[m];
	for (int i = 1; i <= n; i++) scanf("%d", &prettyvalue[i]);
	for (int i = 0; i < m; i++) {
		scanf ("%d %d %d", &q[i].i, &q[i].j, &q[i].k);
		q[i].k--;
		q[i].queries = i;
	}
	
	mergeSort(q, 0, m - 1, 1);
	int left = 1;
	int right = 1;
	struct node* root = NULL;
	
	for(int i = 0; i < m; i++){
		for (int j = left; j < q[i].i; j++) root = deleteavl(root, prettyvalue[j]);
		if (q[i].i >= right) right = q[i].i;
		for (int j = right; j <= q[i].j; j++) root = insertavl(root, prettyvalue[j]);
		q[i].ans = findkth(root, q[i].k);
		left = q[i].i;
		right = q[i].j + 1;
	}
	
	mergeSort(q, 0, m - 1, 0);
	for (int i = 0; i < m; i++) printf("%d\n", q[i].ans);
	
	return 0;
}
