/*
 * queue_list.h
 *
 *  Created on: 2012/11/05
 *      Author: tomofumi
 */

#ifndef QUEUE_LIST_H_
#define QUEUE_LIST_H_

typedef struct _QueueList *QueueList;

QueueList QueueList_New(int value);
QueueList QueueList_Delete(QueueList this);
void QueueList_Push(QueueList this, int value);
int QueueList_Pop(QueueList this);
_Bool QueueList_IsEmpty(QueueList this);

#endif /* QUEUE_LIST_H_ */