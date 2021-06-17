#include "dll.h"

int count_nodes(List* dll)
{
    struct Node *ptr = dll->head;
    int count = 0;
    while(ptr!= NULL)
    {
        ptr = ptr->next;
        count++;
    }
    return count;
}

void insert_front(List* dll, int data)
{
    struct Node *p  = (struct Node*)malloc(sizeof(struct Node));
    p->data = data;
    p->next = NULL;
    p->prev = NULL;
    if(dll->head == NULL)
    {
        dll->head = p;
        dll->tail = p;
    }
    else
    {
        p->next = dll->head;
        dll->head->prev = p;
        dll->head = p;
    }
    ++dll->number_of_nodes;
}


void dllist_delete_beginning(List* list)
{
    if(list->head!= NULL)
    {
        Node *p = list->head;
        list->head  = list->head->next;
        if(p->next!= NULL)
        {
            list->head->prev = NULL;
        }
        --list->number_of_nodes;
        free(p);
    }
}


void position_delete(List* dll, int pos)
{
    if((pos < 0) || (pos > (dll->number_of_nodes - 1)))//underflow
    {
         ;
    }
    else if(pos == 0)
    {
        Node *temp = dll->head;
        dll->head = dll->head->next;
        if(temp->next!= NULL)
        {
            dll->head->prev =NULL;
        }
        --dll->number_of_nodes;
        free(temp);
    }
    else if(pos == (dll->number_of_nodes-1))
    {
        Node *temp = dll->tail;
        dll->tail = dll->tail->prev;
        dll->tail->next = NULL;
        --dll->number_of_nodes;
        free(temp);
    }
    else
    {
        Node *temp = dll->head;
        for(int i = 0; i < pos; i++)
            temp = temp->next;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        --dll->number_of_nodes;
        free(temp);
    }
}

int search_list(List* dll,int key)
{
    int pos = 0;
    Node *p = dll->head;
    while(p!=NULL)
    {
        if(p->data == key)
        {
            return pos;
        }
        else
        {
            p = p->next;
            ++pos;
        }
    }
    return -1;
}


void reverse_list(List* dll)
{
    if(dll->head !=NULL)
    {
        struct Node *curr = dll->head;
        struct Node *temp = NULL;
        while(curr!= NULL)
        {
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            curr = curr->prev;
        }
        Node *temp2 = dll->head;
        dll->head = dll->tail;
        dll->tail = temp2;
    }
}

