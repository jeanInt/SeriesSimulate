#ifndef FIFO_H_
#define FIFO_H_
#define u8  unsigned char
#define u16 unsigned int

#define FIFO_BUFFER_SIZE 128 // 缓冲区大小
typedef struct {
    u8 buffer[FIFO_BUFFER_SIZE] ;
    u8 head;    //大于256自觉用int
    u8 tail;
    u8 count;   //大于256自觉用int
}TFIFO;

void fifo_init(TFIFO* fifo);
u8  fifo_push(TFIFO* fifo,u8 dat);
u8  fifo_pop(TFIFO* fifo,u8* dat);

#endif  //FIFO_H_