#include <stdio.h>
#include <limits.h>
#include "circular_buffer.h"



void initCircularBuffer(struct circularBuffer* bufferPtr, int* data, int maxLength) {
  bufferPtr->data = data;
  bufferPtr->head = 0;
  bufferPtr->tail = 0;
  bufferPtr->maxLength = maxLength;
  bufferPtr->numData = 0 // empty size at beginning
}

int addElement(struct circularBuffer* bufferPtr, int value){
  if(isFull(bufferPtr)){
      return INT_MIN;
  }  
  bufferPtr->data[bufferPtr->tail] = value;
  bufferPtr->numData++
  bufferPtr->tail = (bufferPtr-> tail + 1) % bufferPtr->maxLength;
  return value;
}

int removeHead(struct circularBuffer* bufferPtr){
  int removedValue;
  if(isEmpty(bufferPtr)){
    return INT_MIN;
  }
  removedValue = bufferPtr->data[bufferPtr->head];
  bufferPtr->numData--;
  bufferPtr->head = (bufferPtr->head+1) % bufferPtr-> maxLength;

  return removedValue;
}


int contains(struct circularBuffer* bufferPtr, int value){
  int index = bufferPtr->tail;
  int valueFound;
  if (isEmpty(bufferPtr))
  {
    return INT_MIN;
  }
  for(int i; i<bufferPtr->maxLength; i++){
      if(bufferPtr->data[index] == value){
        valueFound = 1;
      } 
    index->tail = (index + 1 ) % bufferPtr->maxLength;
  }
  if(valueFound == 1){
    return value
  } else{
  return INT_MIN;
  }

}

int removeValue(struct circularBuffer* bufferPtr, int value){
  int index = bufferPtr->tail;
  int removedValue;
  int valueRemoved;
  if(isEmpty(bufferPtr)){
    return INT_MIN;
  }
  for(int i; i<bufferPtr->maxLength; i++){
    if(bufferPtr->data[index] == value){
      removedValue = bufferPtr->data[index];
      valueRemoved = 1;
    }
    index = ( index + 1 ) % bufferPtr->maxLength;
  }
  if(valueRemoved == 1){
      return value;
    }else{
      return INT_MIN;
    }

}

void printBuffer(struct circularBuffer* bufferPtr){
  int index = bufferPtr->tail

  for(i = 0; i < bufferPtr->maxLength; i++){
    printf("%d ", bufferPtr->data[index])
    index = (index + 1) % bufferPtr -> maxLength
  } printf("\n");

}


bool isEmpty(struct circularBuffer* bufferPtr, int numData ){
  return(bufferPtr->numData == 0);
}

bool isFull(struct circularBuffer* bufferPtr, int numData){
    return(bufferPtr-> numData == bufferPtr->maxLength);
}



