/*
 * list.h
 *
 *  Created on: 2012/11/19
 *      Author: tomofumi
 */
 
#ifndef LIST_H_
#define LIST_H_

#include <stdbool.h>
#include "list_node.h"

typedef struct _List{
    ListNode head;
    ListNode tail;
    int size;
} _List, *List;

List List_New();
List List_Delete(List self);
int List_Add(List self, void* value);
void* List_Get(List self, int index);
void* List_GetFirst(List self);
void* List_GetLast(List self);
void* List_Remove(List self, int index);
bool List_RemoveValue(List self, void* value);
ListNode List_Search(List self, void* value);
void* List_GetNext(List self);

#endif /* LIST_H_ */
