/*
 * list.c
 *
 *  Created on: 2012/11/19
 *      Author: tomofumi
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <err.h>
#include "list_node.h"
#include "list.h"

static void _List_Remove(List self, ListNode target_node);

/*
 * Listを生成
 */
List List_New() {
  List instance;

  instance = (List)malloc(sizeof(_List));
  if (instance == NULL) return NULL;

  instance->head = NULL;
  instance->tail = NULL;
  instance->size = 0;
  return instance;
}

/*
 * Listを破棄
 */
List List_Delete(List self) {
  if (self == NULL) return NULL;

  if (self->head != NULL) {
    ListNode delete_node = self->head;
    ListNode temp_node = self->head;

    while (delete_node != NULL) {
      temp_node = temp_node->next;
      free(delete_node);
      delete_node = temp_node;
    }
  }

  self = NULL;
  return self;
}

/*
 * 要素を追加
 *
 * @param value 要素のデータ
 * @return 新しく追加した位置
 */
int List_Add(List self, void* value) {
  ListNode new_node = ListNode_New(value);
  int index = 0;

  if (new_node == NULL) return -1;

  if (self->head != NULL) {
    ListNode temp_node = self->head->next;
    ListNode next_node = self->head;

    while (temp_node != NULL) {
      next_node = temp_node;
      temp_node = temp_node->next;
      index++;
    }
    next_node->next = new_node;
    new_node->prev = next_node;
    self->tail = new_node;
    self->tail->prev = next_node;
  } else {
    self->head = new_node;
    self->tail = new_node;
  }
  self->size++;
  return index;
}

/*
 * 指定された位置にある値を取得
 *
 * @param index 先頭からの位置
 * @return 指定された位置の値
 */
void* List_Get(List self, int index) {
  int i;
  ListNode temp_node = self->head;
  ListNode target_node = temp_node;

  for (i = 0; i < index && temp_node != NULL; i++) {
    target_node = temp_node->next;
    temp_node = target_node;
  }

  if (target_node == NULL) {
    //errx(EXIT_FAILURE, "Index out bounds: %s(%d)\n", __func__, index);
    return NULL;
  }
  return target_node->value;
}

/*
 * 最初の要素を取得
 */
void* List_GetFirst(List self) {
  if (self->head == NULL) return NULL;
  return self->head->value;
}

/*
 * 最後の要素を取得
 */
void* List_GetLast(List self) {
  if (self->tail == NULL) return NULL;
  return self->tail->value;
}

/*
 * 次のノードを取得
 *
 * @return ListNode
 */
void* List_GetNext(List self) {
  if (self->head != NULL) return self->head->next;
  return NULL;
}

/*
 * 指定された位置にある要素を削除
 *
 * @param index 先頭からの位置
 * @return 指定された位置に以前あった要素
 */
void* List_Remove(List self, int index) {
  int i;
  void* value;
  ListNode target_node = self->head;
  ListNode temp_node = target_node;
  

  for (i = 0; i < index; i++) {
    target_node = temp_node->next;
    temp_node = target_node;
  }
  if (target_node == NULL) return NULL;

  value = target_node->value;

  _List_Remove(self, target_node);
  return value;
}

/*
 * 指定された要素のデータがあれば削除
 *
 * @param 削除する要素のデータ
 */
_Bool List_RemoveValue(List self, void* value) {
  ListNode target_node = List_Search(self, value);

  if (target_node == NULL) return false;

  _List_Remove(self, target_node);
  return true;
}

/*
 * 指定された要素があれば削除
 */
static void _List_Remove(List self, ListNode target_node) {
  ListNode prev = target_node->prev;
  ListNode next = target_node->next;

  if (prev != NULL) {
    prev->next = next;
  }
  if (next != NULL) {
    next->prev = prev;
  } else {
    self->tail = prev;
  }
  self->size--;
  
  if (self->size == 0) {
    self->head = NULL;
    self->tail = NULL;
  }

  free(target_node);
}

/*
 * 指定された要素を検索
 *
 * @param 検索する要素のデータ
 * @return 見つかったListNode
 */
ListNode List_Search(List self, void* value) {
  ListNode temp_node = self->head;
  ListNode target_node = temp_node;

  while (temp_node != NULL && target_node->value != value) {
    target_node = temp_node->next;
    temp_node = target_node;
  }

  if (target_node == NULL) return NULL;
  return target_node;
}
