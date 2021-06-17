#include <stdio.h>
/*#include "6a.h"*/
int main() {
	char expression[350];
	int number_of_inputs = 0;
	scanf("%d", &number_of_inputs);
	for(int counter = 0; counter < number_of_inputs; ++ counter) {
		scanf("%s", expression);
		printf("%d\n", postfix_eval(expression));
	}
	return 0;
}

/*-------------------------------------------*/


#include <stdio.h>
#include <stdlib.h>
#define debug printf("HERE")

typedef struct node {
	int data;
	struct node *link;
}Node;

typedef struct list {
	Node *head;
	int number_of_Nodes;
}List;

/* initializes a linked List */
void List_initialize(List* List);

void List_insert_front(List* List, int data);

void List_delete_front(List *List);

/* Returns the element that (*Node_ptr) contains */
const int Node_get_data(Node* Node_ptr);

/* deallocates resources held by the List */
void List_destroy(List* List);


typedef struct {
	List *ptr_List;
} Stack;

void stack_initialize(Stack* ptr_stack);
void stack_push(Stack* ptr_stack, int data);
void stack_pop(Stack* ptr_stack);
int stack_is_empty(Stack* ptr_stack);
const int stack_peek(Stack* ptr_stack);
void stack_destroy(Stack* ptr_stack);

/* The implementations for the above functions are provided below main() */

/* Returns the result of the postfix expression */
int postfix_eval(const char * expression);
/* TODO:
 * Provide suitable implementation for the above function declaration, namely, postfix_eval()
 */


/*----------------------------------------------------*/

/*#include "6a.h"*/
#include <ctype.h>

static Node* create_Node(int data, Node* link) {
	Node* temp =  (Node*)malloc(sizeof(Node));
	temp -> data = data;
	temp -> link = link;
	return temp;
}

void List_initialize(List* ptr_List)
{
    ptr_List->head = NULL;
    ptr_List->number_of_Nodes = 0;
}

void List_insert_front(List* ptr_List, int data)
{
    struct Node* newn = create_Node(data, ptr_List->head);
    ptr_List-> head = newn;
    ptr_List->number_of_Nodes++;
}

const int Node_get_data(Node *Node_ptr)
{
	return Node_ptr->data;
}

void List_delete_front(List* ptr_List)
{
	if(ptr_List->head == NULL)
    {
        //none
    }
    else
    {
        Node* temp = ptr_List->head;
        ptr_List->head = temp->link;
        free(temp);
        ptr_List->number_of_Nodes--;
    }
}

void List_destroy(List* ptr_List)
{
	Node *x, *u = NULL;
	x = ptr_List->head;
	while(x != NULL)
    {
        u = x;
        x = x->link;
        free(u);
    }
    free(ptr_List);
}


void stack_initialize(Stack *ptr_stack)
{
	ptr_stack -> ptr_List = (List*)malloc(sizeof(List));
	List_initialize(ptr_stack->ptr_List);
}

void stack_push(Stack *ptr_stack, int key)
{
	List_insert_front(ptr_stack->ptr_List, key);
}

void stack_pop(Stack *ptr_stack)
{
	List_delete_front(ptr_stack-> ptr_List);
}

int stack_is_empty(Stack *ptr_stack)
{
	if(ptr_stack->ptr_List->head != NULL)
        return 0;
	else
        return 1;
}

const int stack_peek(Stack *ptr_stack)
{
	return ptr_stack->ptr_List->head->data;
}

void stack_destroy(Stack *ptr_stack)
{
	List_destroy(ptr_stack->ptr_List);
	free(ptr_stack);
}

int postfix_eval(const char* expression)
{
    Stack* st=(Stack*)malloc(sizeof(Stack));
    stack_initialize(st);
    for(int i=0;expression[i]!='\0';i++)
    {
        char ch=expression[i];
        if(isdigit(ch))
            stack_push(st,ch-'0');
        else
        {
            int a,b,c;
            a=stack_peek(st);
            stack_pop(st);
            b=stack_peek(st);
            stack_pop(st);
            switch(ch)
            {
                case '+':
                    c=a+b;
                    break;
                case '-':
                    c=b-a;
                    break;
                case '*':
                    c=b*a;
                    break;
                case '/':
                    c=b/a;
                    break;
            }
            stack_push(st,c);        }
    }
    return stack_peek(st);
}


