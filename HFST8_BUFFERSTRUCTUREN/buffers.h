#ifndef DEFINE BUFFERS
#define DEFINE BUFFERS

struct ringbuffer_t
{
    char data[16];
    unsigned int MAX_CAPACITY;
    unsigned int write_index;
    unsigned int read_index;
};

struct queue_t
{
    char data[16];
    unsigned int MAX_CAPACITY;
    unsigned int current_index;
};

struct stack_t
{
    char data[16];
    unsigned int MAX_CAPACITY;
    unsigned int current_index;
};

void push(struct stack_t *stack, char pushData);

char pop(struct stack_t *stack);

void enqueue(struct queue_t *queue, char pushData);

char dequeue(struct queue_t *queue);

void writePointer(struct ringbuffer_t *ring, char pushData);

char readPointer(struct ringbuffer_t *ring);

#endif /*BUFFERS.H*/