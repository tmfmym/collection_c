/*
 * stack_list.h
 *
 *  Created on: 2012/11/05
 *      Author: tomofumi
 */

#ifndef STACK_LIST_H_
#define STACK_LIST_H_

typedef struct _StackList *StackList;

StackList StackList_New(int value);
StackList StackList_Delete(StackList this);
void StackList_Push(StackList this, int value);
int StackList_Pop(StackList this);
_Bool StackList_IsEmpty(StackList this);

#endif /* STACK_LIST_H_ */
