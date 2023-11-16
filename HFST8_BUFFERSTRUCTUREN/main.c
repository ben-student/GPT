#include "buffers.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    // max capacitiet voor buffers
    int maxCapacity = 6;

    // Maak structs voor vssn buffer structuren aan en initialiseer hun eigenschappen
    struct stack_t stack = {
        .MAX_CAPACITY = maxCapacity,
        .current_index = 0,
    };

    struct queue_t queue = {
        .MAX_CAPACITY = maxCapacity,
        .current_index = 0,
    };

    struct ringbuffer_t ring = {
        .MAX_CAPACITY = maxCapacity,
        .read_index = 0,
        .write_index = 1,
    };

    //data
    char array[] = "test";

    // Vstacken vullen
    for (int i = 0; i < stack.MAX_CAPACITY; i++)
    {
        push(&stack, array[i]);
    }

    // stackken printen
    printf("stack : ");
    for (int i = 0; i < stack.MAX_CAPACITY; i++)
    {
        printf("%c", pop(&stack));
    }
    printf("\n");

    // quees enqueene
    for (int i = 0; i < queue.MAX_CAPACITY; i++)
    {
        enqueue(&queue, array[i]);
    }
    // ques afprinten
    printf("queue : ");
    for (int i = 0; i < queue.MAX_CAPACITY; i++)
    {
        printf("%c", dequeue(&queue));
    }
    printf("\n");

    // Buffers bufferen met data
    for (int i = 0; i < ring.MAX_CAPACITY; i++)
    {
        writePointer(&ring, array[i]);
    }
    // ringbuffer printen
    printf("ring : ");
    for (int i = 0; i < ring.MAX_CAPACITY; i++)
    {
        printf("%c", readPointer(&ring));
    }
    printf("\n");

    return 0;
}
