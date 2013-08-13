/*
 * main.c
 *
 *  Created on: 2012/11/05
 *      Author: tomofumi
 */

#include <stdio.h>
#include <stdlib.h>
#include "configure.h"
#include "List/list.h"
#include "Stack/stack_array.h"
#include "Stack/stack_list.h"
#include "Queue/queue_array.h"
#include "Queue/queue_list.h"
#include "Tree/binary_tree.h"

#define ARRAY_SIZE 5

#define SHOW_FUNC printf("\n%s\n", __func__);

void TestStackArray() {
  SHOW_FUNC
  int array[ARRAY_SIZE];

  StackArray stack = StackArray_New(array, ARRAY_SIZE);
  stack->push(stack, 1);
  stack->push(stack, 2);
  stack->push(stack, 3);
  printf("pop %d\n", stack->pop(stack));
  stack->push(stack, 4);
  printf("pop %d\n", stack->pop(stack));
  printf("pop %d\n", stack->pop(stack));
  printf("pop %d\n", stack->pop(stack));
//  printf("pop %d\n", stack->pop(stack));
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
  queue->push(queue, 1);
  queue->push(queue, 2);
  queue->push(queue, 3);
  queue->push(queue, 4);
  printf("pop %d\n", queue->pop(queue));
  queue->push(queue, 5);
  printf("pop %d\n", queue->pop(queue));
  printf("pop %d\n", queue->pop(queue));
  queue->push(queue, 6);
  printf("pop %d\n", queue->pop(queue));
  printf("pop %d\n", queue->pop(queue));
  printf("pop %d\n", queue->pop(queue));
  printf("pop %d\n", queue->pop(queue));
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

void TestBinaryTree() {
  int i, action;
  TreeNode tree_root = TreeNode_New(1);

  for (i = 0; i < 10; i++) {
    tree_root->add(tree_root, rand() % 99 + 1);
  }
  while (TRUE) {
    tree_root->show(tree_root, 0);
    printf("実行する操作のタイプを入力してください。\n 1 ：追加\t2 ：検索\t3 ：削除\t それ以外：終了>");
    scanf("%d", &action);
    switch (action) {
    case 1:
      printf("1 〜100の範囲で，追加する数字を入力してください:");
      scanf("%d", &i);
      if (i < 1 || i > 100) {
        continue;
      }
      tree_root->add(tree_root, i);
      break;
    case 2:
      printf("検索する数字を入力してください:");
      scanf("%d", &i);
      if (tree_root->find(tree_root, i) != NULL ) {
        printf("%dを発見しました\n", i);
      } else {
        printf("%dは見つかりませんでした\n", i);
      }
      break;
    case 3:
      printf("削除する数字を入力してください:");
      scanf("%d", &i);
      if (tree_root->remove(tree_root, i) != NULL ) {
        printf("%dを削除しました\n", i);
      } else {
        printf("%dは見つかりませんでした\n", i);
      }
      break;
    default:
      TreeNode_Delete(tree_root);
      break;
    }
  }
}

int main(int argc, char **argv) {
//  TestStackArray();
//  TestStackList();
//  TestQueueArray();
//  TestQueueList();
//  TestBinaryTree();

  exit(EXIT_SUCCESS);
}
