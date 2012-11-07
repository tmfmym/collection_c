/*
 * main.c
 *
 *  Created on: 2012/11/05
 *      Author: tomofumi
 */

#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "stack_array.h"
#include "stack_list.h"
#include "queue_array.h";
#include "queue_list.h"

#define ARRAY_SIZE 5

#define SHOW_FUNC printf("\n%s\n", __func__);

void TestList() {
  SHOW_FUNC
  ListNode list_node = ListNode_New(1);
  ListNode_Add(list_node, 2);
  ListNode_Add(list_node, 3);
  printf("ListNode_Get(0): %d\n", ListNode_Get(list_node, 0));
  printf("ListNode_Get(1): %d\n", ListNode_Get(list_node, 1));
  printf("ListNode_Get(2): %d\n", ListNode_Get(list_node, 2));
  printf("ListNode_GetFirst(): %d\n", ListNode_GetFirst(list_node));
  printf("ListNode_GetLast(): %d\n", ListNode_GetLast(list_node));
  printf("ListNode_Remove(2): %d\n", ListNode_Remove(list_node, 2));
  printf("ListNode_Remove(1): %d\n", ListNode_Remove(list_node, 1));
  ListNode_Add(list_node, 4);
  printf("ListNode_Get(1): %d\n", ListNode_Get(list_node, 0));
  ListNode_Add(list_node, 4);
  ListNode_Add(list_node, 4);
	printf("ListNode_Get(1): %d\n", ListNode_Get(list_node, 0));
	printf("ListNode_Get(1): %d\n", ListNode_Get(list_node, 1));
  list_node = ListNode_Delete(list_node);
}

void TestStackArray() {
  SHOW_FUNC
  int array[ARRAY_SIZE];

  StackArray stack = StackArray_New(array, ARRAY_SIZE);
  StackArray_Push(stack, 1);
  StackArray_Push(stack, 2);
  StackArray_Push(stack, 3);
  printf("pop %d\n", StackArray_Pop(stack));
  StackArray_Push(stack, 4);
  printf("pop %d\n", StackArray_Pop(stack));
  printf("pop %d\n", StackArray_Pop(stack));
  printf("pop %d\n", StackArray_Pop(stack));
//  printf("pop %d\n", StackArray_Pop(stack));
  StackArray_Delete(stack);
}

void TestStackList() {
  SHOW_FUNC
  StackList stack = StackList_New(1);
  StackList_Push(stack, 2);
  StackList_Push(stack, 3);
  printf("pop %d\n", StackList_Pop(stack));
  StackList_Push(stack, 4);
  printf("pop %d\n", StackList_Pop(stack));
  printf("pop %d\n", StackList_Pop(stack));
  printf("pop %d\n", StackList_Pop(stack));
//  printf("pop %d\n", StackList_Pop(stack));
  StackList_Delete(stack);
}

void TestQueueArray() {
  SHOW_FUNC
  int array[ARRAY_SIZE];

  QueueArray queue = QueueArray_New(array, ARRAY_SIZE);
  QueueArray_Push(queue, 1);
  QueueArray_Push(queue, 2);
  QueueArray_Push(queue, 3);
  QueueArray_Push(queue, 4);
  printf("pop %d\n", QueueArray_Pop(queue));
  QueueArray_Push(queue, 5);
  printf("pop %d\n", QueueArray_Pop(queue));
  printf("pop %d\n", QueueArray_Pop(queue));
  QueueArray_Push(queue, 6);
  printf("pop %d\n", QueueArray_Pop(queue));
  printf("pop %d\n", QueueArray_Pop(queue));
  printf("pop %d\n", QueueArray_Pop(queue));
  printf("pop %d\n", QueueArray_Pop(queue));
  QueueArray_Delete(queue);
}

void TestQueueList() {
  SHOW_FUNC
  QueueList queue = QueueList_New(1);
  QueueList_Push(queue, 2);
  QueueList_Push(queue, 3);
  QueueList_Push(queue, 4);
  printf("pop %d\n", QueueList_Pop(queue));
  QueueList_Push(queue, 5);
  printf("pop %d\n", QueueList_Pop(queue));
  printf("pop %d\n", QueueList_Pop(queue));
  QueueList_Push(queue, 6);
  QueueList_Push(queue, 7);
  printf("pop %d\n", QueueList_Pop(queue));
  printf("pop %d\n", QueueList_Pop(queue));
  printf("pop %d\n", QueueList_Pop(queue));
  printf("pop %d\n", QueueList_Pop(queue));
  QueueList_Delete(queue);
}

int main(int argc, char **argv) {
//	TestList();
//  TestStackArray();
//  TestStackList();
//  TestQueueArray();
  TestQueueList();
  exit(EXIT_SUCCESS);
}
