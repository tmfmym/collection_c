#include "stack_list.h"
#include "../minunit.h"

int mu_tests_run = 0;
int mu_tests_success = 0;

static void test() {
  StackList stack = StackList_New(1);
  StackList_Push(stack, 2);
  ASSERT_INT_EQ(2, StackList_Pop(stack));
  StackList_Push(stack, 3);
  StackList_Push(stack, 4);
  ASSERT_INT_EQ(4, StackList_Pop(stack));
  ASSERT_INT_EQ(3, StackList_Pop(stack));
  ASSERT_INT_EQ(1, StackList_Pop(stack));
//  printf("pop %d\n", stack->pop(stack));
  StackList_Delete(stack);
}

int main() {
  test();
  TEST_SUMMARY();
  return 0;
}