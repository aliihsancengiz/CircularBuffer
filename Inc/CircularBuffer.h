#ifndef _MY_CIRC_BUFFER_
#define _MY_CIRC_BUFFER_


#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>


typedef struct circular_buf_t circular_buf_t;
typedef circular_buf_t*  cbuf_handle_t;

cbuf_handle_t circular_buf_init(uint8_t *b,int size);
void circular_buf_free(cbuf_handle_t self);
void circular_buf_reset(cbuf_handle_t self);
void circular_buf_add(cbuf_handle_t self,uint8_t data);
bool circular_buf_get(cbuf_handle_t self,uint8_t *data);
bool circular_buf_empty(cbuf_handle_t self);
bool circular_buf_full(cbuf_handle_t self);
size_t circular_buf_capacity(cbuf_handle_t self);
size_t circular_buf_size(cbuf_handle_t self);
#endif