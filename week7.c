#include <stdlib.h>
#include <stdio.h>

typedef struct node node;

struct node
{
	int id;
	int time;
	node *link;
};

typedef struct list
{
	node *head;
	node *tail;
	int number_of_nodes;
} List;

typedef struct queue
{
	List *ptr_list;
} Queue;

void list_initialize(List *list);
void list_insert_rear(List *list, int id, int time);
const int node_get_id(node *node_ptr);
const int node_get_time(node *node_ptr);
void list_delete_front(List *list);
void list_destroy(List *list);

void queue_initialize(Queue *ptr_queue);
void queue_enqueue(Queue *ptr_queue, int id, int time);
void queue_dequeue(Queue *ptr_queue);
int queue_is_empty(Queue *ptr_queue);
void queue_peek(Queue *ptr_queue);
void queue_destroy(Queue *ptr_queue);
const int queue_find_person(Queue *ptr_queue, int t);

/*------------------------*/
//#include "queue.h"
static node *create_node(int id, int time, node *link)
{
    node *ptr = (node*)malloc(sizeof(node));
    ptr->id = id;
    ptr->time = time;
    ptr->link = NULL;
    return ptr;
}
void list_initialize(List *ptr_list)
{
    ptr_list = (List*)malloc(sizeof(List));
    ptr_list->head = NULL;
    ptr_list->tail = NULL;
    ptr_list->number_of_nodes = 0;
}
const int node_get_id(node *node_ptr)
{
    return node_ptr->id;
}

const int node_get_time(node *node_ptr)
{
    return node_ptr->time;
}

void list_insert_rear(List *ptr_list, int id, int time)
{
    node *ptr = create_node(id, time, ptr_list->tail);
    if(ptr_list->number_of_nodes == 0)
    {
        ptr_list->head = ptr;
        ptr_list->tail = ptr;
    }
    else
    {
        ptr_list->tail->link = ptr;
        ptr_list->tail = ptr;
    }
    ++ptr_list->number_of_nodes;

}

void list_delete_front(List *ptr_list)
{
    node *temp = ptr_list->head;
    ptr_list->head = ptr_list->head->link;
    free(temp);
    --ptr_list->number_of_nodes;
}

void list_destroy(List *ptr_list)
{
    node *temp1 = ptr_list->head;
    node *temp2 = NULL;
    while(temp1 != NULL)
    {
        temp2 = temp1;
        temp1 = temp1->link;
        free(temp2);
    }
}

void queue_initialize(Queue *queue_list)
{
    queue_list = (Queue*)malloc(sizeof(Queue));
    list_initialize(queue_list->ptr_list);
}

void queue_enqueue(Queue *ptr, int id, int time)
{
    list_insert_rear(ptr->ptr_list, id, time);
}

void queue_dequeue(Queue *ptr)
{
    if(!queue_is_empty(ptr))
    {
        list_delete_front(ptr->ptr_list);
    }
}

int queue_is_empty(Queue *ptr)
{
    if(ptr->ptr_list->number_of_nodes == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void queue_peek(Queue *ptr)
{
    if(!queue_is_empty(ptr))
    {
        int id = node_get_id(ptr->ptr_list->head);
        int time = node_get_time(ptr->ptr_list->head);
        printf("%d%d\n", id, time);
    }
    else
    {
        printf("Empty Queue\n");
    }
}

void queue_destroy(Queue *ptr)
{
    list_destroy(ptr->ptr_list);
}

const int queue_find_person(Queue *ptr_queue, int t)
{
    if(!queue_is_empty(ptr_queue))
    {
        int time = ptr_queue->ptr_list->head->time;
    while(time < t)
    {
        queue_dequeue(ptr_queue);
        if(!queue_is_empty(ptr_queue))
        {
            time += ptr_queue->ptr_list->head->time;
        }
        else
        {
            printf("Empty Queue\n");
            break;
        }
    }
    if(!queue_is_empty(ptr_queue))
    {
        printf("%d\n", ptr_queue->ptr_list->head->id);
    }
    }
    else
        {
        printf("Empty Queue\n");
    }
}


/*---------------*/

#include <stdio.h>
//#include "queue.h"
int main()
{
	Queue queue;
	queue_initialize(&queue);
	int choice, id, time, t;
	int loop = 1;
	while (loop)
	{
		scanf("%d", &choice);
		switch (choice)
		{
		case 0:
			scanf("%d%d", &id, &time);
			queue_enqueue(&queue, id, time);
			break;

		case 1:
			queue_dequeue(&queue);
			break;

		case 2:
			queue_peek(&queue);
			break;

		case 3:
			scanf("%d", &t);
			queue_find_person(&queue, t);
			break;

		default:
			queue_destroy(&queue);
			loop = 0;
		}
	}
	return 0;
}


