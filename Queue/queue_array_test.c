#include "queue_array.h"
#include "../minunit.h"

int mu_tests_run = 0;
int mu_tests_success = 0;

#define ARRAY_SIZE 5

static void test() {
  int array[ARRAY_SIZE];

  QueueArray queue = QueueArray_New(array, ARRAY_SIZE);
  queue->push(queue, 1);
  queue->push(queue, 2);
  queue->push(queue, 3);
  queue->push(queue, 4);
  ASSERT_INT_EQ(1, queue->pop(queue));
  queue->push(queue, 5);
  ASSERT_INT_EQ(2, queue->pop(queue));
  ASSERT_INT_EQ(3, queue->pop(queue));
  queue->push(queue, 6);
  ASSERT_INT_EQ(4, queue->pop(queue));
  ASSERT_INT_EQ(5, queue->pop(queue));
  ASSERT_INT_EQ(6, queue->pop(queue));
  QueueArray_Delete(queue);
}

int main() {
  test();
  TEST_SUMMARY();
  return 0;
}