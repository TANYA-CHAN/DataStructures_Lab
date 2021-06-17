##include<math.h>
#include "poly.h"

void insert_at_end(List *list, int data)
{
	struct Node *prev, *temp;
	temp = (Node*)malloc(sizeof(struct Node));
	temp->data = data;
	temp->link = NULL;
	prev = list->head;
    if(list->head == NULL)
    {
        list->head = temp;
    }
    else
    {
       while(prev->link!= NULL)
    {
         prev = prev->link;
    }prev->link = temp;
    } ++list->number_of_nodes;
}

long long int evaluate(List *list, int x)
{
    struct Node *ptr;
    ptr = list->head;
    long long int count = 0, res = 0, term = 0;
    ptr = list->head;
    if(ptr->link == NULL)
    {
        return ptr->data * pow(x, 0);
    }
    while (ptr!=NULL)
    {
        term = (ptr->data)*pow(x, count);
        res =res + term;
        count++;
        ptr = ptr->link;
    }
    return res;
}

