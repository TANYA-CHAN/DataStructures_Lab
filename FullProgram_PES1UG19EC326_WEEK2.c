#include<stdio.h>
#include<stdlib.h>
//#include"sll.h"

//Node of the linked list
typedef struct Node {
	int data;
	struct Node *link;
} Node;

//Handle of the list. Its head points to the first node in the list.
typedef struct List {
	Node *head;
	int number_of_nodes;
} List;

/* initializes a linked list */
List* list_initialize();

/* Inserts data at specified position 0 <= position <= length(list). */
void list_insert_at(List* list, int data, int position);

/*Inserts data at the end of the List*/
void insert_at_end(List *list, int data);

/* Removes the First node of the linked list. No operation if the list was empty */
void list_delete_front(List* list);

/* Prints the entire List as "X1, X2, ..., Xn" where X1 to Xn are the elements of the list,
if list is empty prints "EMPTY" */
void list_print(List* list);

/* Reverses the element of the list*/
void list_reverse(List* list);

/* deallocates resources held by the list */
void list_destroy(List* list);


List* list_initialize() {
	List* list = (List*) malloc(sizeof(List));
	list->head = NULL;
	list->number_of_nodes = 0;
	return list;
}

void list_print(List* list)
	{
	Node *p;
	p=list->head;
	if(p == NULL)
	{
		printf("EMPTY\n");
		return;
	}
	while (p!=NULL){
		printf("%d=>",p->data);
		p=p->link;
	}
	printf("\n");
}
void list_destroy (List *list)
{
	Node *t, *u=NULL;
	t=list->head;
	while (t->link!=NULL){
		u=t;
		t=t->link;
		free(u);
	}
	free(list);
}
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


  void create_node(List *list, int data)
  {
    struct Node *prev, *temp, *curr;
    curr = list->head;
    temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    //check if this is the first element
    if(curr == NULL)
      list->head = temp;
    else
     {
        temp->link = list->head;
        list->head = temp;
     }
 }



int main() {
	int choice;
	List* list = list_initialize();
	do {
        printf("Enter the number\n 1-Insert at end \n 2--Print \n 3---Delete front \n 4--Insert at pos\n 5--List_reverse\n 6---Destroy\n 7--Create node");
		scanf("%d", &choice);
		switch(choice) {
			int element, index;
			case 1:
				/*Insert element at the End of the list*/
				printf(" choosen: INSERT AT END \n");
				scanf("%d", &element);
				insert_at_end(list, element);
				break;
			case 2:
				/* Print list contents */
				printf("choosen: PRINT\n");
				list_print(list);
				break;
			case 3:
				/* Remove front element */
				printf("choosen: DELETE FRONT\n");
				list_delete_front(list);
				break;
			case 4:
				/* Insert elements at specified positions */
				printf("choosen: INSERT AT POS\n");
				scanf("%d%d", &element, &index);
				list_insert_at(list, element, index);
				break;
			case 5:
				/*Reverses the elements of the list*/
				printf("choosen: LIST REVERSE\n");
				list_reverse(list);
				break;
            case 6:
				/*Reverses the elements of the list*/
				printf("choosen: DESTROY LIST\n");
				list_destroy (list);
				break;
            case 7:
				/*Reverses the elements of the list*/
				printf("choosen: CREATE NODE\n");
				scanf("%d", &element);
				create_node(list, element);
				break;
		}
	} while(choice != 0);
	list_destroy(list);
	return 0;
}
