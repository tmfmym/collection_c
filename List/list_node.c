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

/*
 * Listオブジェクトを破棄
 *
 * @return NULL
 */
ListNode ListNode_DeleteAll(ListNode node) {
  if (node == NULL) return NULL;

  ListNode delete_node = node;
  ListNode temp_node = node;

  while (delete_node != NULL) {
    temp_node = temp_node->next;
    free(delete_node);
    delete_node = temp_node;
  }
  return NULL;
}

/*
* 指定された位置にある要素を削除
*
* @param
* @return 指定された位置に以前あった要素
*/
void* ListNode_Remove(ListNode head_node, int index) {
  int i;
  void* value;
  ListNode temp_node = head_node;
  ListNode target_node = temp_node;

  for (i = 0; i < index; i++) {
    target_node = temp_node->next;
    temp_node = target_node;
  }
  if (target_node == NULL) {
    exit(EXIT_FAILURE);
    return NULL;
  }
  value = target_node->value;
  ListNode prev = target_node->prev;
  ListNode next = target_node->next;

  // printf("target:%x prev=%x next=%x\n", target_node, target_node->prev, target_node->next);

  if (prev != NULL) {
    // printf("prev:%x prev=%x next=%x\n", prev, prev->prev, prev->next);
    prev->next = next;
  }

  if (next != NULL) {
    // printf("next:%x prev=%x next=%x\n", next, next->prev, next->next);
    next->prev = prev;
  }

  // LOGGER_DEBUG("remove %x\n", target_node);
  free(target_node);
  return value;
}
