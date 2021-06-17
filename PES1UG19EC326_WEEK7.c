#include "queue.h"

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
