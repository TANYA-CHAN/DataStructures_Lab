#include "hash.h"
HashTable *create_table(int size)
{
    //TODO
    int * table=(int*)malloc(size*sizeof(int));
    HashTable * h = (HashTable*)malloc(sizeof(HashTable));
    h->size=size;
    for(int i=0;i<size;i++)
        table[i]=-1;
    h->table=table;
    return h;
}

void insert(HashTable *htable, int element)
{
    //TODO
    int key=element%htable->size;
    if(htable->table[key]==-1)
        htable->table[key]=element;
    else
        for(int i=key+1;i<htable->size;i++)
        {
            if(htable->table[i]==-1)
            {
                htable->table[i]=element;
                break;
            }
        }
}

int search(HashTable *htable, int element)
{
    //TODO
    int key=element%htable->size;
    int f=0;
    for(int i=key;i<htable->size;i++)
    {
        if(htable->table[i]==element)
        {
            f=1;
            break;
        }
    }
    if(f==1)
        return 1;
    else 
        return 0;
}

void delete (HashTable *htable, int element)
{
    //TODO
    int key=element%htable->size;
    for(int i=key;i<htable->size;i++)
    {
        if(htable->table[i]==element)
        {
            htable->table[i]=-1;
            break;
        }
    }
}


void destroy_table(HashTable *htable)
{
    //TODO
    free(htable->table);
    free(htable);
}
/*
5
4
1 0
1 1
1 3
1 8
4
2 0
2 9
4
3 8
3 102
0
*/