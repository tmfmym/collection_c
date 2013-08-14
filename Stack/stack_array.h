/*
 * stack_array.h
 *
 *  Created on: 2012/11/05
 *      Author: tomofumi
 */

#ifndef STACK_ARRAY_H_
#define STACK_ARRAY_H_

#include <stdbool.h>

typedef struct _StackArray *StackArray;

typedef struct _StackArray {
  int *array; /* データを保存する配列 */
  int max; /* 最大容量 */
  int top; /* スタック頂上の位置（最下部からのオフセット） */
  void (*push)(StackArray this, int value);
  int (*pop)(StackArray this);
  bool (*is_empty)(StackArray this);
} _StackArray;

StackArray StackArray_New(int *array, int max);
StackArray StackArray_Delete(StackArray this);

#endif /* STACK_ARRAY_H_ */
