/*
 * stack_array.c
 *
 *  Created on: 2012/11/05
 *      Author: tomofumi
 */
#include <stdlib.h>
#include "../configure.h"
#include "../logger.h"
#include "stack_array.h"

static void Push(StackArray this, int value);
static int Pop(StackArray this);
static _Bool IsEmpty(StackArray this);

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
  instance->push = Push;
  instance->pop = Pop;
  instance->is_empty = IsEmpty;
  return instance;
}

/*
 * オブジェクトを破棄
 *
 * @return NULL
 */
StackArray StackArray_Delete(StackArray this) {
  if (this != NULL ) {
    free(this);
  }
  return NULL ;
}

/*
 * 値を挿入
 *
 * @param value
 */
static void Push(StackArray this, int value) {
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
static int Pop(StackArray this) {
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
static _Bool IsEmpty(StackArray this) {
  if (this->top == 0) {
    return TRUE;
  } else {
    return FALSE;
  }
}
