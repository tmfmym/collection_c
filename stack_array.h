/*
 * stack_array.h
 *
 *  Created on: 2012/11/05
 *      Author: tomofumi
 */

#ifndef STACK_ARRAY_H_
#define STACK_ARRAY_H_

typedef struct _StackArray *StackArray;

StackArray StackArray_New(int *array, int max);
StackArray StackArray_Delete(StackArray this);
void StackArray_Push(StackArray this, int value);
int StackArray_Pop(StackArray this);
_Bool StackArray_IsEmpty(StackArray this);

#endif /* STACK_ARRAY_H_ */
