#include "5a.h"
#include <stdio.h>

//Allocating memory for Node
static Node* create_Node(int data, Node* link)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->link = link;
    return new_node;
}

//Initializing default values for the list
void list_initialize(List* ptr_list) 
{
    ptr_list->head = NULL;
    ptr_list->number_of_Nodes = 0;

}

//Inserting node in the beginning
void list_insert_front(List* ptr_list, int data) 
{
    Node* new_node = create_Node(data, ptr_list->head);
    ptr_list->head = new_node;
}


const int Node_get_data(Node *Node_ptr) 
{
    return Node_ptr->data;
}

//Deleting node from the front
void list_delete_front(List* ptr_list) 
{
    if(ptr_list->head != NULL)
    {
        Node* temp;
        temp = ptr_list->head;
        ptr_list->head = temp->link;
        free(temp);
    }   

}


void list_destroy(List* ptr_list) 
{
	Node *t, *u=NULL;
	t=ptr_list->head;
	while (t->link!=NULL){
		u=t;
		t=t->link;
		free(u);
	}
	free(ptr_list);
}

void Stack_initialize(Stack *ptr_Stack) 
{
    List* list = (List*)malloc(sizeof(List));
    list_initialize(list);

    ptr_Stack->ptr_list = list;
}

//Calling list_insert_front to push element into stack
void Stack_push(Stack *ptr_Stack, int key) 
{
    list_insert_front(ptr_Stack->ptr_list, key);
    ptr_Stack->ptr_list->number_of_Nodes++;
}

//Calling list_delete_front to pop element from stack
void Stack_pop(Stack *ptr_Stack) 
{
    list_delete_front(ptr_Stack->ptr_list);
    ptr_Stack->ptr_list->number_of_Nodes--;
}

//Function to check if stack is empty
int Stack_is_empty(Stack *ptr_Stack) 
{
    if(ptr_Stack->ptr_list->number_of_Nodes == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}

//Function to return topmost element in the stack
const int Stack_peek(Stack *ptr_Stack) 
{
    const int value = Node_get_data(ptr_Stack->ptr_list->head);
    return value;
}

void Stack_destroy(Stack *ptr_Stack)
{
    list_destroy(ptr_Stack->ptr_list);
	free(ptr_Stack);
}

int match_parenthesis(const char* string)
{

    Stack* stack = (Stack*)malloc(sizeof(Stack));  //Allocating memory for the stack
    Stack_initialize(stack);

    const char *p = string;
    const char *q = string;
    int length = 0;

    while(*q != '\0')   //loop to calculate the length of the input string
    {
        length++;
        q++;
    }
    

    while(*p != '\0')   //Loop for checking paranthesis matching
    {
        if(length % 2 != 0)   //If length is odd, return 0
        {
            return 0;
            break;  
        }

        switch(*p)    //pushing opening brackets and popping closing brackets
        {
            case '(': Stack_push(stack, *p);
                      break;
            case '{': Stack_push(stack, *p);
                      break;
            case '[': Stack_push(stack, *p);
                      break;
            case ')': if(!Stack_is_empty(stack))
                      {
                        if(Stack_peek(stack) == '(')
                            Stack_pop(stack); 
                      }
                      else
                      {
                          return 0;
                          break;
                      }
                      break;
            case '}': if(!Stack_is_empty(stack))
                      {
                        if(Stack_peek(stack) == '{')
                            Stack_pop(stack);                        
                      }
                      else
                      {
                          return 0;
                          break;
                      }                      
                      break;
            case ']': if(!Stack_is_empty(stack))
                      {
                        if(Stack_peek(stack) == '[')
                        {
                            Stack_pop(stack);
                        }
                      }
                      else
                      {
                        return 0;
                        break;
                      }           
                      
                      break;                      
        }

        p++;
    }

    //If stack is empty it means that the parenthesis match
    if(Stack_is_empty(stack))
    {        
        return 1;
    }
    else
    {        
        return 0;
    }

    
}

