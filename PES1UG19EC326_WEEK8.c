#include<stdio.h>
#include "bst.h"

void tree_initialize(Tree *tree)
{
    tree->root = NULL;
}

void tree_insert(Tree *tree, int data)
 {

   struct node *temp,*curr,*prev;

  temp= malloc(sizeof(struct node));
  temp->data=data;
  temp->left=temp->right=NULL;
  if(tree->root == NULL)
    tree->root =temp;
  else
  {
    curr= tree->root;
    prev=NULL;
    while(curr!=NULL)
    {
      prev=curr;
      if(data <curr->data)
        curr=curr->left;
      else
        curr=curr->right;
    }
   if(data <prev->data)
     prev->left=temp;
   else
     prev->right=temp;
 }
}


void tree_delete(Tree *tree, int element)
{
    struct node *temp, *current, *prev, *qptr, *ptr;
    prev = NULL;
    current = tree->root;
    while(( current != NULL)&&(current->data != element))
    {
        prev = current;
        if(element < current->data)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }
    if( current == NULL)
    {
        return tree->root;
    }
    if((current->left == NULL)||(current->right == NULL))
    {
        if(current->left == NULL)
        {
            qptr = current->right;
        }
        else
        {
            qptr = current->left;
        }


        if(prev == NULL)
        {
            return qptr;
        }
        else if(current == prev->left)
        {
            prev->left = qptr;
        }
        else
        {
            prev->right = qptr;
        }
        free(current);
      }
   else
   {
       ptr = NULL;
       temp = current->right;
       while(temp->left != NULL)
       {
           ptr = temp;
           temp = temp->left;
       }
       current->data = temp->data;
       if(ptr != NULL)
       {
           ptr->left = temp->right;
       }
       else
       {
           current->right = temp->right;
       }
       free(temp);
   }
   return tree->root;
}

void tree_inorder(Node *r)
{
if(r!=NULL)
	{
		tree_inorder(r->left);
		printf("%d",r->data);
		tree_inorder(r->right);
	}
}

void tree_preorder(Node *r)
{
if(r!=NULL)
	{
		printf("%d",r->data);
		tree_inorder(r->left);

		tree_inorder(r->right);
	}
}

void tree_postorder(Node *r)
{
if(r!=NULL)
	{
		tree_inorder(r->left);

		tree_inorder(r->right);
		printf("%d",r->data);
	}
}

void postorder(Tree *t)
{
   tree_preorder(t->root);
}

void preorder(Tree *t)
{

	tree_postorder(t->root);
}

void inorder(Tree *t)
{
    tree_inorder(t->root);
}

void destroy(Node *r)
{
    if(r != NULL)
    {
        destroy(r->left);
        destroy(r->right);
        free(r);
    }
}

void tree_destroy(Tree *t)
{
    destroy(t->root);
}