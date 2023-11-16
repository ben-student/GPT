#include <stdarg.h>
#include <stdio.h>
#include "buffers.h"

//voeg karakter aan stack toe 
void push(struct stack_t *stack, char pushData)
{
    // huidige index binnen capacit van stack?
    if (stack->current_index <= stack->MAX_CAPACITY)
    {
        
        //voeg char toe aan stack en index++
        stack->data[stack->current_index] = pushData;
        stack->current_index++;
    }
    else
    {
       
        //stack is fulllll
        printf("StackOverflowError\n");
    }
}


//func om char uit stack ta halen (popppp)
char pop(struct stack_t *stack)
{
    ///minstens uno elemento in stackos?
    if (stack->current_index >= 1)
    {
        ///pop die char uit de stack en index--
        stack->current_index--;
        char data = stack->data[stack->current_index];

        return data;
    }
    else
    {
        //empty stack bro
        printf("\nstack is empty\n");
        return 0;
    }
}

//knal char in de que
void enqueue(struct queue_t *queue, char pushData)
{
    //index binne capa van quee?
    if (queue->current_index <= queue->MAX_CAPACITY)
    {
        //char aan que toevoegen en index++
        queue->data[queue->current_index] = pushData;
        queue->current_index++;
    }
    else
    {
        //que is full
        printf("queueOverflowError\n");
    }
}

//get char out of queee
char dequeue(struct queue_t *queue)
{   
    //same logica als bij pop tbh
    if (queue->current_index >= 1)
    {
        char data = queue->data[0];
        for (int i = 0; i < queue->current_index; i++)
        {
            // Verschuif de overige elementen in de queue om de verwijderde te vervangen.
            queue->data[i] = queue->data[i + 1];
        }
        queue->current_index--;

        return data;
    }
    else
    {
        printf("\nqueue is empty\n");
        return 0;
    }
}

//voeg char aan ring toe
void writePointer(struct ringbuffer_t *ring, char pushData)
{
    //lees index kleiner als schrijf indexxx??
    if (ring->read_index < ring->write_index)
    {
        ///char toevoegen en index++
        ring->data[ring->write_index] = pushData;
        ring->write_index++;
    }
    else
    {
        //ringetje is vol
        printf("\nringOverFlowError\n");
    }
    if (ring->write_index == ring->MAX_CAPACITY)
    {
     
        //write index is aan max capac dus terug op nul om verder te kunnen schrijven
        ring->write_index = 0;
    }
}
//char van ring lezen
char readPointer(struct ringbuffer_t *ring)
{
    //index++ vopr char te lezen
    ring->read_index++;
    if (ring->read_index == ring->MAX_CAPACITY)
        ring->read_index = 0;
    if (ring->write_index == ring->read_index)
    {
        
        //read index nadert write index ->> buffer geraakt leeg fout bij leeg zijn
        ring->read_index--;
        if (ring->read_index < 0)
            ring->read_index = ring->MAX_CAPACITY - 1;
        printf("\nringBuffer is empty\n");
        return '\0';
    }
    else
    {
        //char uit ringbuffer halen
        char c = ring->data[ring->read_index];

        return c;
    }
}