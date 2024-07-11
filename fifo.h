#ifndef FIFO_H_
#define FIFO_H_
#define u8  unsigned char
#define u16 unsigned int

#define FIFO_BUFFER_SIZE 128 // ��������С
typedef struct {
    u8 buffer[FIFO_BUFFER_SIZE] ;
    u8 head;    //����256�Ծ���int
    u8 tail;
    u8 count;   //����256�Ծ���int
}TFIFO;

void fifo_init(TFIFO* fifo);
u8  fifo_push(TFIFO* fifo,u8 dat);
u8  fifo_pop(TFIFO* fifo,u8* dat);

#endif  //FIFO_H_