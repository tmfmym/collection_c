/*
 * queue_array.h
 *
 *  Created on: 2012/11/05
 *      Author: tomofumi
 */

#ifndef QUEUE_ARRAY_H_
#define QUEUE_ARRAY_H_

#include <stdbool.h>

typedef struct _QueueArray *QueueArray;

typedef struct _QueueArray {
  int *array; /* データを保存する配列 */
  int max; /* 最大容量(キューのサイズ+1) 空と満杯を区別するため */
  int first; /* キューの先頭位置（配列先頭からのオフセット）*/
  int last; /* キューの末尾位置（配列先頭からのオフセット */
  void (*push)(QueueArray this, int value);
  int (*pop)(QueueArray this);
  bool (*is_empty)(QueueArray this);
} _QueueArray;

QueueArray QueueArray_New(int *array, int max);
QueueArray QueueArray_Delete(QueueArray this);

#endif /* QUEUE_ARRAY_H_ */
