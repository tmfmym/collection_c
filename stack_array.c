/*
 * stack_array.c
 *
 *  Created on: 2012/11/05
 *      Author: tomofumi
 */
#include <stdlib.h>
#include "configure.h"
#include "logger.h"
#include "stack_array.h"

typedef struct _StackArray {
  /* データを保存する配列 */
  int *array;
  /* 最大容量 */
  int max;
  /* スタック頂上の位置（最下部からのオフセット） */
  int top;
} _StackArray;

/*
 * オブジェクトを生成
 *
 * @param array データを保存する配列
 * @param max 配列のサイズ
 * @return StackArray
 */
StackArray StackArray_New(int *array, int max) {
  StackArray instance;
  if (!(instance = (StackArray)malloc(sizeof(_StackArray)))) {
    LOGGER_ERROR("error %s\n", __func__);
  }
  instance->array = array;
  instance->max = max;
  instance->top = 0;
  return instance;
}

/*
 * オブジェクトを破棄
 *
 * @return NULL
 */
StackArray StackArray_Delete(StackArray this) {
  free(this);
  return NULL ;
}

/*
 * 値を挿入
 *
 * @param value
 */
void StackArray_Push(StackArray this, int value) {
  if (this->top == this->max) {
    LOGGER_ERROR("error:Stack overflow %s\n", __func__);
    exit(EXIT_FAILURE);
  } else {
    *(this->array + this->top) = value;
    this->top++;
  }
}

/*
 * 先頭を取得
 *
 * @return 取得した値
 */
int StackArray_Pop(StackArray this) {
  if (this->top == 0) {
    LOGGER_ERROR("error:Stack underflow %s\n", __func__);
    exit(EXIT_FAILURE);
    return 0;
  } else {
    this->top--;
    return *(this->array + this->top);
  }
}

/*
 * 空かどうか判定
 *
 * @return 結果
 */
_Bool StackArray_IsEmpty(StackArray this) {
  if (this->top == 0) {
    return TRUE;
  } else {
    return FALSE;
  }
}
