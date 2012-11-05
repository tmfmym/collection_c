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

#define ARRAY_SIZE 5

void TestList() {
	printf("%s\n", __func__);
	ListNode list_node = ListNode_New(1);
	ListNode_Add(list_node, 2);
	ListNode_Add(list_node, 3);
	printf("ListNode_Get(0): %d\n", ListNode_Get(list_node, 0));
	printf("ListNode_Get(1): %d\n", ListNode_Get(list_node, 1));
	printf("ListNode_Get(2): %d\n", ListNode_Get(list_node, 2));
	printf("ListNode_GetFirst(): %d\n", ListNode_GetFirst(list_node));
	printf("ListNode_GetLast(): %d\n", ListNode_GetLast(list_node));
	printf("ListNode_Remove(2): %d\n", ListNode_Remove(list_node, 1));
	printf("ListNode_Remove(1): %d\n", ListNode_Remove(list_node, 1));
//	printf("ListNode_Get(1): %d\n", ListNode_Get(list_node, 1));
	list_node = ListNode_Delete(list_node);
}

void TestStackArray() {
	printf("%s\n", __func__);
	int array[ARRAY_SIZE];

	StackArray stack = StackArray_New(array, ARRAY_SIZE);
	StackArray_Push(stack, 1);
	StackArray_Push(stack, 2);
	StackArray_Push(stack, 3);
	printf("pop %d\n", StackArray_Pop(stack));
	printf("pop %d\n", StackArray_Pop(stack));
	printf("pop %d\n", StackArray_Pop(stack));
}

void TestStackList() {
	printf("%s\n", __func__);
	StackList stack = StackList_New(1);
	StackList_Push(stack, 2);
	StackList_Push(stack, 3);
	printf("pop %d\n", StackList_Pop(stack));
	printf("pop %d\n", StackList_Pop(stack));
	printf("pop %d\n", StackList_Pop(stack));
}

int main(int argc, char **argv) {
//	TestList();
	TestStackArray();
	TestStackList();
	exit(0);
}
