/*
 * queue_list.c
 *
 *  Created on: 2012/11/06
 *      Author: tomofumi
 */
#include <stdlib.h>
#include "configure.h"
#include "logger.h"
#include "list.h"
#include "queue_list.h"

typedef struct _QueueList {
  ListNode list_head;
  ListNode list_last;
  int size;
} _QueueList;

/*
 * オブジェクトを生成
 *
 * @param array データを保存する配列
 * @param max 配列のサイズ
 * @return QueueList
 */
QueueList QueueList_New(int value) {
  QueueList instance;
  if (!(instance = (QueueList)malloc(sizeof(_QueueList)))) {
    LOGGER_ERROR("error %s\n", __func__);
    return NULL ;
  }
  ListNode list = ListNode_New(value);
  instance->list_head = list;
  instance->list_last = list;
  instance->size = 0;
  return instance;
}

/*
 * オブジェクトを破棄
 *
 * @return NULL
 */
QueueList QueueList_Delete(QueueList this) {
  ListNode_Delete(this->list_head);
  free(this);
  return NULL ;
}

/*
 * 値を追加
 *
 * @param value
 */
void QueueList_Push(QueueList this, int value) {
  if (this->list_head == NULL ) {
    this->list_head = QueueList_New(value);
    this->size = 0;
  } else {
    this->list_last = ListNode_Add(this->list_head, value);
    this->size++;
  }
}

/*
 * 先頭を取得
 *
 * @return 取得した値
 */
int QueueList_Pop(QueueList this) {
  int value;
  if (this->list_head == NULL ) {
    LOGGER_ERROR("error:Stack underflow %s\n", __func__);
    exit(EXIT_FAILURE);
    return 0;
  } else {
    printf("list_head %x\n", this->list_head);
    value = ListNode_Remove(this->list_head, 0);
    this->list_head = ListNode_GetNextNode(this->list_head);
    printf("list_head %x\n", this->list_head);
    if (this->size == 0) {
      this->list_head = NULL;
    } else {
      this->size--;
    }
  }
  return value;
}

/*
 * 空かどうか判定
 *
 * @return 結果
 */
_Bool QueueList_IsEmpty(QueueList this) {
  if (this->size == 0) {
    return TRUE;
  } else {
    return FALSE;
  }
}
