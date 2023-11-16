#ifndef DEFINE LIJSTEN
#define DEFINE LIJSTEN


struct list_t
{
char data;
// declare recursive pointer
struct list_t *next;
};


typedef struct list_t* PrtToList;
typedef PrtToList List;


List CreateList();


void EnQ_sort(List queue, char pushData);

char DeQ_sort(List queue);



#endif /*LIJSTEN.H*/