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

typedef struct _QueueArray {
  /* データを保存する配列 */
  int *array;
  /* 最大容量(キューのサイズ+1) 空と満杯を区別するため */
  int max;
  /* キューの先頭位置（配列先頭からのオフセット） */
  int first;
  /* キューの末尾位置（配列先頭からのオフセット） */
  int last;
} _QueueArray;

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
  return instance;
}

/*
 * オブジェクトを破棄
 *
 * @return NULL
 */
QueueArray QueueArray_Delete(QueueArray this) {
  free(this);
  return NULL ;
}

/*
 * 値を追加
 *
 * @param value
 */
void QueueArray_Push(QueueArray this, int value) {
  if ((this->last + 1) % this->max == this->first) {
    /* 現在配列の中身は，すべてキューの要素で埋まっている */
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
int QueueArray_Pop(QueueArray this) {
  int value;

  if (this->first == this->last) {
    LOGGER_INFO("Queue is empty %s\n", __func__);
    errx(EXIT_FAILURE, "Queue is empty %s\n", __func__);
    return -1 ; // TODO 整数型で-1返すのはまずい
  } else {
    value = *(this->array + this->first);
    this->first = (this->first + 1) % this->max;
    return value;
  }
}

/*
 * 空かどうか判定
 *
 * @return 結果
 */
_Bool QueueArray_IsEmpty(QueueArray this) {
  if (this->first == this->last) {
    return TRUE;
  } else {
    return FALSE;
  }
}
