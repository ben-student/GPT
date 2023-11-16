#include "lijsten.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
   	List sort_q = CreateList();
    EnQ_sort(sort_q, 't');
	EnQ_sort(sort_q, 'e');
	EnQ_sort(sort_q, 's');
	EnQ_sort(sort_q, 't');
	EnQ_sort(sort_q, 'a');
	EnQ_sort(sort_q, NULL);
	printf("Linkedsort:\n");
	printf("%c", DeQ_sort(sort_q));
	printf("%c", DeQ_sort(sort_q));
	printf("%c", DeQ_sort(sort_q));
	printf("%c", DeQ_sort(sort_q));
	printf("%c", DeQ_sort(sort_q));
	printf("%c", DeQ_sort(sort_q));
	printf("%c", DeQ_sort(sort_q));

    return 0;
}
