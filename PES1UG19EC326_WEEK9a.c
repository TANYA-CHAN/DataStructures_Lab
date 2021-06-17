#include "et.h"

Node * createExpressionTree(char* a,int len)
{
    //TODO
	int i=0,top=-1;
	char ch;
	Node *newn,*root;
	struct Node *stack[100];
	for(i=0;a[i]!='\0';i++)
	{	ch=a[i];
		newn=(Node*)malloc(sizeof(Node));
		newn->data=ch;
		newn->left=NULL;
		newn->right=NULL;
		newn->prev=NULL;
		if(ch>='a' && ch<='z' || ch>='A' && ch<='Z')	stack[++top]=newn;
		else{
			newn->right=stack[top--];
			stack[top]->prev=newn;
			newn->left=stack[top--];
			stack[top]->prev=newn;
			stack[++top]=newn;
			newn->prev=stack[top];
			}
		
	}
	root=stack[top--];
		return root;
}


void inorder(Node *root)
{
 //TODO 
 // Note : Do not change the printf
	if(root!=NULL){
	inorder(root->left);
	printf("%c",root->data);
	inorder(root->right);	
	} 
}

void preorder(Node *root)
{
 //TODO 
 // Note : Do not change the printf
	if(root!=NULL){
	printf("%c",root->data);   
	preorder(root->left);
	preorder(root->right);
	}
}

void postorder(Node *root)
{
 //TODO 
 // Note : Do not change the printf
	if(root!=NULL){
	postorder(root->left);
	postorder(root->right);
	printf("%c",root->data);
	} 
}

void freeTree(Node *root)
{
	if(root!=NULL){
	freeTree(root->left);
	freeTree(root->right);
	free(root);
	}
}