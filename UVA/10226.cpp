#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
	char name[50];
	int quantity;
	struct node* left;
	struct node* right;
};

struct node* newnode(char in[]){
	struct node* newn = (struct node*)malloc(sizeof(struct node));
	strcpy(newn->name, in);
	newn->quantity = 1;
	newn->left = NULL;
	newn->right = NULL;
	return newn;
}

struct node* pushT(struct node* localroot, char in[]){
	if (!localroot) return newnode(in);

	if (strcmp(in, localroot->name) < 0) localroot->left = pushT(localroot->left, in);
	else if (strcmp(in, localroot->name) > 0) localroot->right = pushT(localroot->right, in);
	else (localroot->quantity)++;
	
	return localroot;
}

void print(struct node* localroot, int total){
	if (!localroot) return;
	print(localroot->left, total);
	printf("%s %.4lf\n", localroot->name, (double) localroot->quantity / total * 100);
	print(localroot->right, total);
}

void freeall(struct node* root){
	if (!root) return;
	freeall(root->left);
	freeall(root->right);
	free(root);
}

int main (){
	int tc;
	scanf("%d", &tc);
	getchar(); getchar();
	while (tc--){
		int total = 0;
		char in[50];
		struct node* root = NULL;
		while (scanf("%[^\n]", in) != EOF){
			getchar();
			if (strlen(in) == 0) break;
			root = pushT(root, in);
			total++;
			strcpy(in, "");
		}
		print(root, total);
		if (tc) puts("");
		freeall(root);
	}
	return 0;
}
