#include<stdio.h>
#include "Inc/CircularBuffer.h"

int main()
{
    uint8_t *buffer=malloc(sizeof(uint8_t)*10);
    uint8_t k;
    cbuf_handle_t buf=circular_buf_init(buffer,10);
    circular_buf_add(buf,45);
    circular_buf_add(buf,50);
    circular_buf_add(buf,55);



    printf("Avaliable %d \n",circular_buf_size(buf));
    
    // if(circular_buf_get(buf,&k))
    // {
    //     printf("%d\n",k);
    // }
    // if(circular_buf_get(buf,&k))
    // {
    //     printf("%d\n",k);
    // }
    // if(circular_buf_get(buf,&k))
    // {
    //     printf("%d\n",k);
    // }
    // if(circular_buf_get(buf,&k))
    // {
    //     printf("%d\n",k);
    // }
    // else
    // {
    //     printf("Empty\n");
    // }
    


    circular_buf_free(buf);
    free(buffer);
    return 0;
}