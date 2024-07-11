#include "fifo.h"

TFIFO fifo;
void fifo_init(TFIFO* fifo)
{
    u8 i ;
    for(i=0;i<FIFO_BUFFER_SIZE;i++)
    {
        fifo->buffer[i] = 0;
    }
    fifo->count = 0;
    fifo->head = 0;
    fifo->tail = 0;
}

u8  fifo_push(TFIFO* fifo,u8 dat)
{
    if(fifo->count == FIFO_BUFFER_SIZE)
    {
        return 0;
    }
    else
    {
        fifo->buffer[fifo->head] = dat;
        fifo->head = (fifo->head + 1) % FIFO_BUFFER_SIZE;
        fifo->count++;
        return 1;
    }
}

u8  fifo_pop(TFIFO* fifo,u8* dat)
{
    if(fifo->count == 0)
    {
        return 0;
    }
    else
    {
        *dat = fifo->buffer[fifo->tail];
        fifo->tail = (fifo->tail + 1) % FIFO_BUFFER_SIZE;
        fifo->count--;
        return 1;
    }
}
