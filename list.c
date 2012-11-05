/*
 * list.c
 *
 *  Created on: 2012/11/05
 *      Author: tomofumi
 */

#include <stdlib.h>
#include "configure.h"
#include "list.h"

#undef LOG_LEVEL
#ifndef LOG_LEVEL
#define LOG_LEVEL 10
#endif

#include "logger.h"

/* リストの要素（ノード）を表す構造体 */
typedef struct _ListNode {
	/* 前の要素へのポインタ */
	struct _ListNode *prev;
	/* 次の要素へのポインタ */
	struct _ListNode *next;
	/* この要素がもっているデータ */
	int data;
} _ListNode;

/*
 * ListNodeオブジェクトを生成
 *
 * @return ListNode
 */
static ListNode CreateListNode() {
	ListNode new_node;
	if (!(new_node = (ListNode)malloc(sizeof(_ListNode)))) {
		LOGGER_ERROR("error %s\n", __func__);
	}
	return new_node;
}

/*
 * ListNodeオブジェクトを生成
 *
 * @param data データ
 * @return ListNode
 */
ListNode ListNode_New(int data) {
	ListNode head_node = CreateListNode();
	if (head_node == NULL ) return NULL ;

	LOGGER_DEBUG("new %x\n", head_node);

	head_node->data = data;
	head_node->prev = NULL;
	head_node->next = NULL;
	return head_node;
}

/*
 * Listオブジェクトを破棄
 *
 * @return NULL
 */
ListNode ListNode_Delete(ListNode head_node) {
	ListNode delete_node = head_node;

	LOGGER_DEBUG("delete_node %x\n", delete_node);
	while (delete_node != NULL ) {
		head_node = head_node->next;
		LOGGER_DEBUG("remove %x\n", delete_node);
		free(delete_node);
		delete_node = head_node;
	}
	return NULL ;
}

/*
 * 要素を追加
 *
 * @param data
 * @return 新しく追加した位置(ポインタ)
 */
ListNode ListNode_Add(ListNode head_node, int data) {
	ListNode new_node = CreateListNode();
	if (new_node == NULL ) return NULL ;

	ListNode temp_node = head_node->next;
	ListNode next_node = head_node;

	LOGGER_DEBUG("add_ head_node %x\n", head_node);
	LOGGER_DEBUG("temp_node %x\n", temp_node);

	while (temp_node != NULL ) {
		next_node = temp_node;
		temp_node = temp_node->next;
		LOGGER_DEBUG("next\n");
	}
	next_node->next = new_node;
	new_node->prev = next_node;
	new_node->data = data;
	LOGGER_DEBUG("add %x\n", new_node);
	return new_node;
}

/*
 * 指定された位置にある要素を取得
 *
 * @param
 * @return
 */
int ListNode_Get(ListNode head_node, int index) {
	ListNode temp_node = head_node;
	ListNode target_node = temp_node;

	for (int i = 0; i < index; i++) {
		target_node = temp_node->next;
		temp_node = target_node;
	}

	if (target_node == NULL ) {
		LOGGER_ERROR("indexOutOfBoundsException %s\n", __func__);
		exit(EXIT_FAILURE);
		return -1;
	}
	return target_node->data;
}

/*
 * 最初の要素を取得
 *
 * @param
 * @return 最初の要素
 */
int ListNode_GetFirst(ListNode head_node) {
	if (head_node == NULL ) {
		exit(EXIT_FAILURE);
		return -1;
	}
	return head_node->data;
}

/*
 * 最後の要素を取得
 *
 * @param
 * @return 最後の要素
 */
int ListNode_GetLast(ListNode head_node) {
	ListNode temp_node = head_node;
	ListNode target_node = temp_node;

	while (temp_node != NULL ) {
		target_node = temp_node;
		temp_node = temp_node->next;
	}
	return target_node->data;
}

/*
 * 指定された位置にある要素を削除
 *
 * @param
 * @return 指定された位置に以前あった要素
 */
int ListNode_Remove(ListNode head_node, int index) {
	ListNode temp_node = head_node;
	ListNode target_node = temp_node;

	for (int i = 0; i < index; i++) {
		target_node = temp_node->next;
		temp_node = target_node;
	}
	if (target_node == NULL ) {
		LOGGER_ERROR("indexOutOfBoundsException %s\n", __func__);
		exit(EXIT_FAILURE);
		return -1;
	}
	int data = target_node->data;
	ListNode prev = target_node->prev;
	ListNode next = target_node->next;

	if (prev != NULL ) prev->next = next;
	if (next != NULL ) next->prev = prev;

	LOGGER_DEBUG("remove %x\n", target_node);
	free(target_node);
	return data;
}
