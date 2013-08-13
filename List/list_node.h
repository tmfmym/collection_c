/*
 * list.h
 *
 *  Created on: 2012/11/05
 *      Author: tomofumi
 */
 
#ifndef LIST_NODE_H_
#define LIST_NODE_H_

typedef struct _ListNode *ListNode;

typedef struct _ListNode {
  ListNode prev;
  ListNode next;
  void* value;
} _ListNode;

ListNode ListNode_New(void* value);
ListNode ListNode_Delete(ListNode node);

#endif /* LIST_H_ */
