#include "stack_array.h"
#include "../minunit.h"

int mu_tests_run = 0;
int mu_tests_success = 0;

#define ARRAY_SIZE 5

static void test() {
  int array[ARRAY_SIZE];

  StackArray stack = StackArray_New(array, ARRAY_SIZE);
  stack->push(stack, 1);
  stack->push(stack, 2);
  ASSERT_INT_EQ(2, stack->pop(stack));
  stack->push(stack, 3);
  stack->push(stack, 4);
  ASSERT_INT_EQ(4, stack->pop(stack));
  ASSERT_INT_EQ(3, stack->pop(stack));
  ASSERT_INT_EQ(1, stack->pop(stack));
//  printf("pop %d\n", stack->pop(stack));
  
  StackArray_Delete(stack);
}

int main() {
  test();
  TEST_SUMMARY();
  return 0;
}