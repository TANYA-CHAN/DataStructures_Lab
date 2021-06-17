#include "heap.h"
heap* heap_construct(int n){
    heap* tmp=(heap*)malloc(sizeof(heap)+n*sizeof(int));
    tmp->capacity=n;
    tmp->size=0;
    return(tmp);
}
void heap_destruct(heap* tmp){
    //TODO
	free(tmp);
		
}
int heap_get_capacity(heap* tmp){
    //TODO
	return tmp->capacity;
}
int heap_get_size(heap* tmp){
    //TODO
	return tmp->size;
}

int heap_insert(heap* tmp,int data){
    //TODO
	
	
	if(tmp->size>=tmp->capacity) {
	return 0;
	}
	else{
	int i=0;
	for(;i<tmp->size;i++)
	{ if(data<tmp->elements[i])
	break;

	}
	tmp->size++;
	for(int in=tmp->size-1;in>=i;in--)
	{tmp->elements[in]=tmp->elements[in-1];
	
	}
	tmp->elements[i]=data;
	return 1;
	
	}
	
}
int heap_get_min(heap* tmp){
    //TODO
	
	return tmp->elements[0];
}
void heap_remove(heap* tmp){
    //TODO
	//free(tmp->elements[tmp->size]);
	tmp->size--;
	for(int i=0;i<tmp->size;i++)
	tmp->elements[i]=tmp->elements[i+1];
}
