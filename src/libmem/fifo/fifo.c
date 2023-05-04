/**
 * @file fifo.c
 * @author Sravan Senthilnathan
 * @brief FIFO cyclic buffer
 * @version 0.1
 * @date 2023-05-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#include "fifo.h"

#include <stdlib.h>

/**
 * @brief create a fixed point fifo buffer
 * 
 * @param size size of the buffer
 * @return __fifoFixed* fifo buffer handle
 */
__fifoFixed* FifoFixed(int size){
    
    int* fifoBuffer = (int*)malloc(size * sizeof(int));

    __fifoFixed* fifoObject = malloc(sizeof(__fifoFixed));
    fifoObject->fifoBuffer = fifoBuffer;
    fifoObject->size = size;
    fifoObject->ptr =  0;

    return fifoObject;
}

/**
 * @brief create a floating point fifo buffer
 * 
 * @param size size of the buffer
 * @return __fifoFloat* fifo buffer handle
 */
__fifoFloat* FifoFloat(int size){
    
    float* fifoBuffer = (float*)malloc(size * sizeof(float));

    __fifoFloat* fifoObject = malloc(sizeof(__fifoFloat));
    fifoObject->fifoBuffer = fifoBuffer;
    fifoObject->size = size;
    fifoObject->ptr =  0;

    return fifoObject;
}

/**
 * @brief return the value at the index of the fifo
 * 
 * @param fifoObject fifo object handle
 * @param index index of the element
 * @return int index element
 */
int fifoFixedAt(__fifoFixed* fifoObject, int index){
    int ptr = index + fifoObject->ptr;
    if(ptr >= fifoObject->size) ptr -= fifoObject->size;

    return fifoObject->fifoBuffer[ptr];
}

/**
 * @brief return the value at the index of the fifo
 * 
 * @param fifoObject fifo object handle
 * @param index index of the element
 * @return float index element
 */
float fifoFloatAt(__fifoFloat* fifoObject, int index){
    int ptr = index + fifoObject->ptr;
    if(ptr >= fifoObject->size) ptr -= fifoObject->size;

    return fifoObject->fifoBuffer[ptr];
}

/**
 * @brief enqueue data into the start of the fifo buffer
 * 
 * @param fifoObject fifo object handle
 * @param data data to enqueue
 */
void fifoFixedEnqueue(__fifoFixed* fifoObject, int data){
    fifoObject->fifoBuffer[fifoObject->ptr] = data;
    
    fifoObject->ptr++;
    if(fifoObject->ptr == fifoObject->size) fifoObject->ptr -= fifoObject->size;
}

/**
 * @brief enqueue data into the start of the fifo buffer
 * 
 * @param fifoObject fifo object handle
 * @param data data to enqueue
 */
void fifoFloatEnqueue(__fifoFloat* fifoObject, float data){
    fifoObject->fifoBuffer[fifoObject->ptr] = data;

    fifoObject->ptr++;
    if(fifoObject->ptr == fifoObject->size) fifoObject->ptr -= fifoObject->size;
}