#include "6b.h"
stack* stack_initialize(int size)
{
    stack* new_stack = (stack*)malloc(sizeof(stack));
    new_stack->arr = (int*)malloc(sizeof(int)*size);
    new_stack->top = -1;
    return new_stack;
}

void stack_push(stack *ptr_stack, int key)
{
    ptr_stack->top++;
    ptr_stack->arr[ptr_stack->top] = key;
}

void stack_pop(stack *ptr_stack)
{
    if(stack_is_empty(ptr_stack))
        return;
    else
        ptr_stack->top--;
}

int stack_is_empty(stack *ptr_stack)
{
    if(ptr_stack->top == -1)
        return 1;
    else
        return 0;
}

int stack_peek(stack *ptr_stack)
{
    return ptr_stack->arr[ptr_stack->top];
}

void stack_destroy(stack *ptr_stack)
{
    free(ptr_stack->arr);
    ptr_stack->top = -1;
    free(ptr_stack);
}
int isOperand(char ch)
{
    if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        return 1;
    else
        return 0;
}

int precedence(char s)
{
    if(s=='/' || s == '*')
        return 2;
    else if(s== '+' || s == '-')
        return 1;
    else
        return 0;
}

void convert_infix_to_postfix(const char *source_infix,char *target_postfix)
{
    struct stack* new_stack =(stack*)malloc(sizeof(stack));
    new_stack=stack_initialize(strlen(source_infix));
    int i,k;
    for(i=0,k=-1;source_infix[i]!='\0';i++)               //loop runs until the position is null
    {
        if(isOperand(source_infix[i]))
            target_postfix[++k]=source_infix[i];
        else if(source_infix[i]=='(')
            stack_push(new_stack,source_infix[i]);
        else if(source_infix[i]=='{')
            stack_push(new_stack,source_infix[i]);
        else if(source_infix[i]=='[')
            stack_push(new_stack,source_infix[i]);
        else if(source_infix[i]==')') //to match with open parenthesis
        {
            while(!(stack_is_empty(new_stack)) && (stack_peek(new_stack) !='('))
            {
                target_postfix[++k]=stack_peek(new_stack);
                stack_pop(new_stack);
            }
            stack_pop(new_stack);
        }//to match with open flower brace
        else if(source_infix[i]=='}')
        {
            while(!(stack_is_empty(new_stack)) && (stack_peek(new_stack) !='{'))
            {
                target_postfix[++k]=stack_peek(new_stack);
                stack_pop(new_stack);
            }
            stack_pop(new_stack);
        }
        else if(source_infix[i]==']')
        {
            while(!(stack_is_empty(new_stack)) && (stack_peek(new_stack) !='['))
            {
                target_postfix[++k]=stack_peek(new_stack);
                stack_pop(new_stack);
            }
            stack_pop(new_stack);
        }
        else
        {
            while(!(stack_is_empty(new_stack))&&(precedence(source_infix[i])<=precedence(stack_peek(new_stack))))
            {
                target_postfix[++k]=stack_peek(new_stack);
                stack_pop(new_stack);
            }
            stack_push(new_stack,source_infix[i]);
        }
    }
    while(!stack_is_empty(new_stack))
    {
        target_postfix[++k]=stack_peek(new_stack);
        stack_pop(new_stack);
    }
    target_postfix[++k]='\0';
}
