#include "cll.h"
void position_insert(List* cll, int data, int pos)
{
    int count = 0;
    Node* temp = create_node(data);
    Node* ptr = cll->head;
    if(cll->tail == NULL)
    {
        cll->head = temp;
        cll->tail = temp;
        temp->next = temp;
        cll->length++;
    }
    else if(pos == 0)
    {
        temp->next = cll->tail->next;
        cll->tail->next = temp;
        cll->length++;
    }
    else if(pos == cll->length)
    {
        cll->tail->next = temp;
        cll->tail = temp;
        temp->next = cll->head;
        cll->length++;
    }
    else
    {
        while((ptr->next!= cll->head)&&(count!= (pos-1)))
        {
            ptr = ptr->next;
            count++;
        }
        if(count == (pos-1))
        {
            temp->next = ptr->next;
            ptr->next = temp;
            cll->length++;
        }
        else if(ptr->next == cll->head)
        {
            return;
        }
    }
}


void position_delete(List* cll, int pos)
{
        Node* ptr = cll->head;
        Node* qtr;
        int count = 0;
        if(ptr == NULL)
        {
            ;
        }
        else if(pos == 0)
        {
            cll->head = ptr->next;
            cll->tail->next = cll->head;
            free(ptr);
            cll->length--;
        }
        else
        {
            while((ptr->next->next!= cll->head)&&(count!= (pos-1)))
            {
                ptr = ptr->next;
                count++;
            }
            if(count == (pos-1)&&(ptr->next->next!= cll->head))
            {
                qtr = ptr->next;
                ptr->next = qtr->next;
                free(qtr);
                cll->length--;
            }
            else if(ptr->next == cll->head)
            {
                cll->tail = ptr;
                qtr = ptr->next;
                ptr->next = qtr->next;
                free(qtr);
                cll->length--;
            }
            else
            {
                return;
            }
        }
}

int josephus(List* cll, int k)
{
    Node *temp = cll->head;
    for(int i=0; i<k; i++)
    {
        temp = temp->next;
    }
    while(cll->length > 1)
    {
        if(temp->next == cll->head)
        {
            cll->head = cll->head->next;
        }
        else if(temp->next == cll->tail)
        {
            cll->tail = temp;
        }
        Node* temp2 = temp->next;
        temp->next = temp->next->next;
        free(temp2);
        --cll->length;
        temp = temp->next;
    }
    return cll->head->data;
}


