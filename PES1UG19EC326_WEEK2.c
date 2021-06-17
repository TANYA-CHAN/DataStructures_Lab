#include<stdio.h>
#include<stdlib.h>
#include "sll.h"


void insert_at_end(List *list, int data) {
	struct Node *prev, *temp;
	temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = data;
	temp->link = NULL;
	prev = list->head;
	if(list->head == NULL)
        {
        list->head = temp;
        return;
	    }
	while (prev->link!= NULL)
	{
	    prev = prev->link;
	} prev->link = temp;
	return;
}

void list_delete_front(List* list) {
	struct Node *temp;
	temp = list->head;
	if(list->head == NULL) {
        return;
	}
	else {
        list->number_of_nodes = (list->number_of_nodes) - 1;
        temp = list->head;
        list->head = (list->head)->link;
        free(temp);
	}
}
void list_insert_at (List *list, int data, int position)
{
	struct Node *prev, *temp, *curr;
	int count = 0;
	temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = data;
	temp->link = NULL;

	count = 1;
	prev = NULL;
	curr = list->head;

    while(((curr)!=NULL) && (count < position))
    {
        prev = curr;
        curr = curr->link;
        count++;
    }
    if(curr!=NULL)
    {
        if(prev == NULL)
        {
            temp->link = list->head;
            list->head = temp;
        }
        else
        {
            prev->link = temp;
            temp->link = curr;
        }
    }
    else //(curr == NULL)
    {
        if(prev == NULL)
            curr = temp;
        else if(count == position)
            prev->link = temp;
        else
            return;
    }(list->number_of_nodes) = (list->number_of_nodes) + 1;
}
void list_reverse(List* list)
{
    struct Node *prev, *curr, *temp;
    prev = NULL;
    curr = list->head;

    if(curr == NULL)
    {
        return;
    }
    while (curr!= NULL)
    {
        temp = curr->link;
        curr->link =prev;
        prev = curr;
        curr = temp;
    }
    list->head = prev;
}





