#include<stdio.h>
#include "trie.h"
struct trienode *getnode()
{
	struct trienode *p = (struct trienode*)malloc(sizeof(struct trienode));
	for(int i = 0; i < 26; i++)
	{
		p->child[i] = NULL;
	}
	p->endofword = 0;
	return p;
}

void insert(struct trienode *root, char *key)
{
	struct trienode *temp=root;
	int index;
	for(int i = 0; key[i] != '\0'; i++)
	{
		index = key[i] - 'a';
		if(temp->child[index] == NULL)
		{
        		temp->child[index] = getnode();
        	}
        	temp = temp->child[index];
        }
        temp->endofword = 1;
}

void display(struct trienode *curr)
  {
      //TODO: 
     //Note : DO NOT USE printf() statement, use printfun() and   newline function for printing output 
 }

int search(struct trienode * root,char *key)
{
	struct trienode *temp = root;
	int index;
	for(int i = 0; key[i] != '\0'; i++)
	{
		index = key[i] - 'a';
		if(temp->child[index] == NULL)
		{
        		return 0;
        	}
        	temp = temp->child[index];
        }
        if(temp->endofword == 1)
        {
       	return 1;
       }
       return 0;
}

void delete_trie(struct trienode *root,char *key)
{
	
	struct trienode* temp = root;
	int index;
	for(int i = 0; key[i] != '\0'; i++)
	{
		index = key[i] - 'a';
		if(temp->child[index] == NULL)
		{
			return;
		}
		push(temp, index);
		temp = temp->child[index];
	}
	temp->endofword = 0;
	push(temp, -1);
	struct stack stk;
	int x;
	while(1)
	{
		stk = pop();
		if(stk.index != -1)
		{
			stk.m->child[stk.index] = NULL;
		}
		if(stk.m == root)
		{
			break;
		}
		x = check(stk.m);
		if((x >= 1)||(stk.m->endofword == 1))
		{
			break;
		}
		else
		{
			free(stk.m);
		}
	}
	return;
}

int check(struct trienode *x)
{
	int count=0;
	for(int i = 0; i < 26; i++)
	{
		if(x->child[i] != NULL)
		{
			++count;
		}
	}
	return count;
}

void push(struct trienode *x,int k)
{
	++top;
	s[top].m = x;
	s[top].index=k;
}
struct stack pop()
{
	struct stack temp = s[top--];
	return temp;
}

















 /*void display(struct trienode *curr)
 {
   int i,j;
   for(i=0;i<26;i++)
   {
     if(curr->child[i]!=NULL)
     {
       word[length++]=i+97;
       if(curr->child[i]->endofword==1)//if word found
       {
          printf("\n");//print the word
          for(j=0;j<length;j++)
             printf("%c",word[j]);
        }
       display(curr->child[i]);
     }
    }
    length--;
    return;
 }



 struct trienode *getnode()
 {
   int i;
   struct trienode *temp;
   temp=(struct trienode*)malloc(sizeof(struct trienode));
   for(i=0;i<26;i++)
    temp->child[i]=NULL;
  temp->endofword=0;
   return temp;
 }


 void insert(struct trienode * root, char *key)
 {
   int i,index;
   struct trienode *curr;
   curr=root;

   for(i=0;key[i]!='\0';i++)
   {
     index=key[i]-'a';
     if(curr->child[index]==NULL)
        curr->child[index]=getnode();
      curr=curr->child[index];
    }
    curr->endofword=1;
  }


 int search(struct trienode * root,char *key)
  {

  int i,index;
   struct trienode *curr;
   curr=root;

   for(i=0;key[i]!='\0';i++)
   {
     index=key[i]-'a';
     if(curr->child[index]==NULL)
        return 0;
      curr=curr->child[index];
    }
    if(curr->endofword==1)
       return 1;
   return 0;
  }

 void delete_trie(struct trienode *root,char *key)
  {
    int i,j,index,flag;
    struct trienode* curr;
    curr=root;
    flag=1;

    for(i=0;key[i]!='\0';i++)
    {
      index=key[i]-'a';
      if(curr->child[index]==NULL)
      {
         printf("Key not found\n");
         return;
      }
      curr=curr->child[index];
    }
      curr->endofword=0;
      return;
  }*/