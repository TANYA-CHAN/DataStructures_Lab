#include<stdio.h>
#include<stdlib.h>
#include "tbt.h"

void tree_initialize(Tree *tree)
{
	tree->root = NULL;
}

void tree_insert(Tree *tree, int data)
{
	Node *p = (Node*)malloc(sizeof(Node));
	p->data = data;
	p->left = NULL;
	p->right = NULL;
	p->leftThread = 1;
	p->rightThread = 1;
	if(tree->root == NULL)
	{
		tree->root = p;
		return ;
	}
	else
	{
		Node *temp = tree->root;
		while(temp != NULL)
		{
			if(data > temp->data)
			{
				if(temp->rightThread == 0)
				{
					temp = temp->right;
				}
				else
				{
					break;
				}
			}
			else
			{
				if(temp->leftThread == 0)
				{
					temp = temp->left;
				}
				else
				{
					break;
            			}
            		}
            	}
            	if(data < temp->data)
            	{
            		p->left = temp->left;
            		p->right = temp;
            		temp->leftThread = 0;
            		temp->left = p;
            	}
            	else
            	{
            		p->right = temp->right;
            		p->left = temp;
            		temp->right = p;
            		temp->rightThread = 0;
        	}
    	}
}

Node *inorder_predecessor(Node *ptr)
{
	if(ptr->leftThread == 1)
	{
		return ptr->left;
	}
	ptr = ptr->left;
	while(ptr->rightThread == 0)
	{
		ptr = ptr->right;
	}
	return ptr;
}

Node *inorder_successor(Node *ptr)
{
	if(ptr->rightThread == 1)
	{
		return ptr->right;
	}
	ptr = ptr->right;
	while(ptr->leftThread == 0)
	{
		ptr = ptr->left;
	}
	return ptr;
}

void print_ascending(Tree *tree)
{
    if (tree->root == NULL)
    {
        printf("Empty\n");
        return;
    }
    else
    {
    	Node *curr = tree->root;
    	while(curr->leftThread == 0)
    	{
    		curr = curr->left;
    	}
    	while(curr != NULL)
    	{
    		printfun(curr->data);
    		curr = inorder_successor(curr);
    	}
    }
    nextline();
}

void print_descending(Tree *tree)
{
    if (tree->root == NULL)
    {
        printf("Empty\n");
        return;
    }
    else
    {
    	Node *curr = tree->root;
    	while(curr->rightThread == 0)
    	{
    		curr = curr->right;
    	}
    	while(curr != NULL)
    	{
    		printfun(curr->data);
    		curr = inorder_predecessor(curr);
    	}
    }
    nextline();
}

void destroy(Node *r)
{
	free(r);
}

void tree_destroy(Tree *t)
{
    destroy(t->root);
}