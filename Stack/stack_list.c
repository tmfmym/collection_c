/*
 * stack_list.c
 *
 *  Created on: 2012/11/05
 *      Author: tomofumi
 */
#include <stdlib.h>
#include "../configure.h"
#include "../logger.h"
#include "../List/list_node.h"
#include "stack_list.h"

typedef struct _StackList {
  ListNode list_head;
  ListNode list_last;
  int size;
} _StackList;

/*
 * オブジェクトを生成
 *
 * @param value
 * @return StackList
 */
StackList StackList_New(int value) {
  StackList instance;
  if (!(instance = (StackList)malloc(sizeof(_StackList)))) {
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
StackList StackList_Delete(StackList this) {
  if (this != NULL ) {
    ListNode_Delete(this->list_head);
    free(this);
  }
  return NULL ;
}

/*
 * 値を挿入
 *
 * @param value
 */
void StackList_Push(StackList this, int value) {
  if (this->list_head == NULL ) {
    this->list_head = StackList_New(value);
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
int StackList_Pop(StackList this) {
  int value;
  if (this->list_head == NULL ) {
    LOGGER_ERROR("error:Stack underflow %s\n", __func__);
    exit(EXIT_FAILURE);
    return 0;
  } else {
    value = ListNode_Remove(this->list_head, this->size);
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
_Bool StackList_IsEmpty(StackList this) {
  if (this->size == 0) {
    return TRUE;
  } else {
    return FALSE;
  }
}
