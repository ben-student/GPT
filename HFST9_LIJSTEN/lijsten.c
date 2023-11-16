#include <stdarg.h>
#include <stdio.h>
#include "lijsten.h"




List CreateList()
{
	List list;
	list = (struct list_t*)malloc(sizeof(struct list_t));
	if(list == NULL)
    {
        printf("Unable to allocate memory.");
        exit(0);
    }
	list->next = NULL;
	return list;
}

void EnQ_sort(List queue, char pushData)
{
	if (queue->next == NULL)
	{
		struct list_t* new_node = CreateList();
		queue->next = new_node;
		queue->data = pushData;
	}
	else if ((queue->data > pushData))
	{
		struct list_t* new_node = CreateList();
		new_node->data = queue->data;
		queue->data = pushData;
		new_node->next = queue->next;
		queue->next = new_node;
	}
	else if ((pushData <= queue->next->data)){
		struct list_t* new_node = CreateList();
		new_node->next = queue->next;
		queue->next = new_node;
		new_node->data = pushData;
	}
	else
	{
		EnQ_sort(queue->next, pushData);
	}
}


char DeQ_sort(List queue)
{
	if (queue->next == NULL)
	{
		printf("\nNothing to read\n");
		return '\0';
	}
	else
	{
		char buffer = queue->data;
		*queue = *queue->next;
		return buffer;
	}
}