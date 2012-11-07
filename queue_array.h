/*
 * queue_array.h
 *
 *  Created on: 2012/11/05
 *      Author: tomofumi
 */

#ifndef QUEUE_ARRAY_H_
#define QUEUE_ARRAY_H_

typedef struct _QueueArray *QueueArray;

QueueArray QueueArray_New(int *array, int max);
QueueArray QueueArray_Delete(QueueArray this);
void QueueArray_Push(QueueArray this, int value);
int QueueArray_Pop(QueueArray this);
_Bool QueueArray_IsEmpty(QueueArray this);

#endif /* QUEUE_ARRAY_H_ */
