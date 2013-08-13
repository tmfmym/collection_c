/*
 * queue_list.c
 *
 *  Created on: 2012/11/06
 *      Author: tomofumi
 */
#include <stdlib.h>
#include <err.h>
#include "../configure.h"
#include "../logger.h"
#include "../List/list_node.h"
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
QueueList QueueList_New(void* value) {
  QueueList instance;
  if (!(instance = (QueueList)malloc(sizeof(_QueueList)))) {
    LOGGER_ERROR("Cannot allocate memory %s\n", __func__);
    return NULL;
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
  if (this != NULL) {
    ListNode_DeleteAll(this->list_head);
    free(this);
  }
  return NULL;
}

/*
 * 値を追加
 *
 * @param value
 */
void QueueList_Push(QueueList this, void* value) {
  if (this->list_head == NULL ) {
    this->list_head = ListNode_New(value);
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
void* QueueList_Pop(QueueList this) {
  void* value;
  if (this->list_head == NULL ) {
    errx(EXIT_FAILURE, "IndexOutOfBoundsException %s\n", __func__);
    return 0;
  } else {
    value = ListNode_Remove(this->list_head, 0);
    this->list_head = ListNode_GetNextNode(this->list_head);
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
