/*
 * list.c
 *
 *  Created on: 2012/11/05
 *      Author: tomofumi
 */
 
#include <stdio.h>
#include <stdlib.h>
#include "list_node.h"

/*
 * ListNodeオブジェクトを生成
 *
 * @param value データ
 * @return ListNode
 */
ListNode ListNode_New(void* value) {
  ListNode instance = (ListNode)malloc(sizeof(_ListNode));

  if (instance == NULL) return NULL;

  instance->prev = NULL;
  instance->next = NULL;
  instance->value = value;
  return instance;
}

/*
 * Listオブジェクトを破棄
 *
 * @return NULL
 */
ListNode ListNode_Delete(ListNode node) {
  if (node != NULL) {
    free(node);
  }
  return NULL;
}
