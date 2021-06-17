#include <stdio.h>
#include <stdlib.h>

// Node of the circular linked list
typedef struct Node
{
    int data;
    struct Node *next;
} Node;
// Handle of the list.
// Head points to the first node in the list.
// Tail points to the last node in the list.
typedef struct List
{
    Node *head;
    Node *tail;
    int length;
} List;

// initializes a cirucular linked list
List* initialize_list();

// Creates a node and stores the data in it.
Node* create_node(int data);

// Inserts data at offset position pos. No operation is required if pos is out of range.
void position_insert(List* cll, int data, int pos);

// Deletes the node at position pos. No operation is required if pos is out of range.
void position_delete(List* cll, int pos);

// Print the data present in the safe node according to the josephus problem.
int josephus(List* cll,int k);

// Prints the entire list. Prints "EMPTY" if the list is empty.
void display(List* cll);

// Deallocates resources held by the list
void destroy_list(List*);




#include <stdio.h>
#include <stdlib.h>
/*#include "cll.h"*/

int main()
{

    List* cll = initialize_list();
    int ele,choice,pos,k;

    do
    {
        scanf("%d",&choice);

        switch(choice)
        {
            // Insert at position;
            case 1:
                scanf("%d %d",&ele,&pos);
                position_insert(cll,ele,pos);
                break;

            // Delete at position
            case 2:
                scanf("%d",&pos);
                position_delete(cll, pos);
                break;

            // Josephus problem
            case 3:
                scanf("%d",&k);
                ele = josephus(cll,k);
                printf("%d\n",ele);
                break;

            // Print entire list
            case 4:
                display(cll);
                break;
        }
    }
    while (choice != 0);

    destroy_list(cll);
    return 0;
}

List* initialize_list()
{
    List* cll = (List*)malloc(sizeof(List));
    cll->head = NULL;
    cll->tail = NULL;
    cll->length = 0;
    return cll;
}

Node* create_node(int data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}
void display(List* cll)
{
	if(cll->length == 0)
        printf("EMPTY");
  	  else
   	 {
        Node* temp = cll->head;
        for(int i=0;i<cll->length;i++)
        {
            printf("%d ",temp->data);
            temp = temp->next;
        }
    }
    printf("\n");
}

void destroy_list(List* cll)
{
	Node *p = cll->head;
	Node *q = NULL;
	for(int i=0;i<cll->length;i++)
    	{
		q = p;
		p = p->next;
		free(q);
	}

    free(cll);
}


/*#include "cll.h"*/
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
            printf("Emprty List\n");
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
                printf("Element doesn't exist");
                return;
            }
        }
}

int josephus(List* cll, int k)
{
    Node* ptr = cll->head;
    Node* qtr = cll->head;
    while(ptr->next!= ptr)
    {
        int i = 0;
        while(i!=k+1)
        {
            qtr = ptr;
            ptr = ptr->next;
            i++;
        }
        qtr->next = ptr->next;
        free(ptr);
        cll->length--;
        ptr = qtr->next;
    }
    cll->head = ptr;
    cll->tail = ptr;
    cll->head->next = NULL;
    return cll->head->data;
}

