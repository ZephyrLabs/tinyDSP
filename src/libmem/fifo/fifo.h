/**
 * @file fifo.h
 * @author Sravan Senthilnathan
 * @brief include header for FIFO cyclic buffer
 * @version 0.1
 * @date 2023-05-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#ifndef __FIFO_H__
#define __FIFO_H__

typedef struct{
    int* fifoBuffer;
    int size;
    int ptr;
}__fifoFixed;

typedef struct {
    float* fifoBuffer;
    int size;
    int ptr;
}__fifoFloat;

__fifoFixed* FifoFixed(int size);
__fifoFloat* FifoFloat(int size);

int fifoFixedAt(__fifoFixed* fifoObject, int index);
float fifoFloatAt(__fifoFloat* fifoObject, int index);

void fifoFixedEnqueue(__fifoFixed* fifoObject, int data);
void fifoFloatEnqueue(__fifoFloat* fifoObject, float data);


#endif
