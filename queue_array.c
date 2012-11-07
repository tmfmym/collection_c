/*
 * queue_array.c
 *
 *  Created on: 2012/11/06
 *      Author: tomofumi
 */
#include <stdlib.h>
#include <err.h>
#include "configure.h"
#include "logger.h"
#include "queue_array.h"

static void QueueArray_Push(QueueArray this, int value);
static int QueueArray_Pop(QueueArray this);
static _Bool QueueArray_IsEmpty(QueueArray this);

/*
 * オブジェクトを生成
 *
 * @param array データを保存する配列
 * @param max 配列のサイズ
 * @return QueueArray
 */
QueueArray QueueArray_New(int *array, int max) {
  QueueArray instance;
  if (!(instance = (QueueArray)malloc(sizeof(_QueueArray)))) {
    LOGGER_ERROR("error %s\n", __func__);
  }
  instance->array = array;
  instance->max = max;
  instance->first = 0;
  instance->last = 0;
  instance->push = QueueArray_Push;
  instance->pop = QueueArray_Pop;
  instance->is_empty = QueueArray_IsEmpty;
  return instance;
}

/*
 * オブジェクトを破棄
 *
 * @return NULL
 */
QueueArray QueueArray_Delete(QueueArray this) {
  if (this != NULL ) {
    free(this);
  }
  return NULL ;
}

/*
 * 値を追加
 *
 * @param value
 */
static void QueueArray_Push(QueueArray this, int value) {
  if ((this->last + 1) % this->max == this->first) {
    LOGGER_INFO("Queue is full. Cannot push value.\n");
  } else {
    *(this->array + this->last) = value;
    /* いちばん後ろの場合は，先頭にもってくる */
    this->last = (this->last + 1) % this->max;
  }
}

/*
 * 先頭を取得
 *
 * @return 取得した値
 */
static int QueueArray_Pop(QueueArray this) {
  int value;

  if (this->first == this->last) {
    errx(EXIT_FAILURE, "Queue is empty %s\n", __func__);
    return -1;
  } else {
    value = *(this->array + this->first);
    /* 先頭を次に移動する */
    this->first = (this->first + 1) % this->max;
    return value;
  }
}

/*
 * 空かどうか判定
 *
 * @return 結果
 */
static _Bool QueueArray_IsEmpty(QueueArray this) {
  if (this->first == this->last) {
    return TRUE;
  } else {
    return FALSE;
  }
}
