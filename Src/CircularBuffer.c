#include "../Inc/CircularBuffer.h"



// Circular buffer Container
struct circular_buf_t
{
    uint8_t *buffer;
    size_t head,tail,maxsize;
    bool full;
};

static void advance_head_pointer(cbuf_handle_t self)
{
    assert(self);
    if(self->full)
    {
        self->tail=(self->tail+1) %self->maxsize;
    }
    self->head=(self->head + 1) % self->maxsize;
    self->full=(self->head == self->tail);
}
static void retreive_tail_pointer(cbuf_handle_t self)
{
    assert(self);
    self->full=false;
    self->tail=(self->tail+1) % self->maxsize;
}

cbuf_handle_t circular_buf_init(uint8_t *buffer,int size)
{
    // Check argument is valid
    assert(buffer && size);
    // Create a dynamicly allocated circular buffer handler
    cbuf_handle_t cbuf=malloc(sizeof(circular_buf_t));
    cbuf->buffer=buffer;
    cbuf->maxsize=size;
    circular_buf_reset(cbuf);
    return cbuf;
}
void circular_buf_free(cbuf_handle_t self)
{
    if(self != NULL)
    {
        free(self);
    }
}
void circular_buf_reset(cbuf_handle_t self)
{
    self->head=0;
    self->tail=0;
    self->full=false;
}
bool circular_buf_full(cbuf_handle_t self)
{
    assert(self);
    return self->full;
}
bool circular_buf_empty(cbuf_handle_t self)
{
    assert(self);
    return (!circular_buf_full(self) && (self->head == self->tail));
}
size_t circular_buf_capacity(cbuf_handle_t self)
{
    assert(self);
    return self->maxsize;
}
size_t circular_buf_size(cbuf_handle_t self)
{
    assert(self);
    size_t s=self->maxsize;
    if(!circular_buf_full(self))
    {
        if(self->head >= self->tail)
        {
            s=self->head-self->tail;
        }
        else
        {
            s=self->maxsize+self->head-self->tail;
        }
    }
    return s;
}

void circular_buf_add(cbuf_handle_t self,uint8_t data)
{
    assert(self);
    self->buffer[self->head]=data;
    advance_head_pointer(self);
}
bool circular_buf_get(cbuf_handle_t self,uint8_t *data)
{
    assert(self);
    if(circular_buf_empty(self))
    {
        return false;
    }
    *data=self->buffer[self->tail];
    retreive_tail_pointer(self);
    return true;
}


