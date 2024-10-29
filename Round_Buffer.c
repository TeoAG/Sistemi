#include <stdint.h>

#define BUFFER_SIZE 1024

typedef struct {
    uint8_t data[BUFFER_SIZE];
    uint16_t head;
    uint16_t tail;
} round_buffer_t;

void put(round_buffer_t* buffer, uint8_t* data) {
    if ((buffer->head + 1) % BUFFER_SIZE == buffer->tail) {
        
    } else {
        buffer->data[buffer->head] = *data;
        buffer->head = (buffer->head + 1) % BUFFER_SIZE;
    }
}

uint8_t get(round_buffer_t* buffer) {
    if (buffer->head == buffer->tail) {
        
    } else {
        uint8_t data = buffer->data[buffer->tail];
        buffer->tail = (buffer->tail + 1) % BUFFER_SIZE;
        return data;
    }
}
