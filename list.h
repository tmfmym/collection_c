/*
 * list.h
 *
 *  Created on: 2012/11/05
 *      Author: tomofumi
 */

#ifndef LIST_H_
#define LIST_H_

typedef struct _ListNode *ListNode;

ListNode ListNode_New(int data);
ListNode ListNode_Add(ListNode head_node, int data);
ListNode ListNode_Delete(ListNode head_node);
int ListNode_Get(ListNode head_node, int index);
int ListNode_GetFirst(ListNode head_node);
int ListNode_GetLast(ListNode head_node);
int ListNode_Remove(ListNode head_node, int index);

#endif /* LIST_H_ */