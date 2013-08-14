#include "queue_list.h"
#include "../minunit.h"

int mu_tests_run = 0;
int mu_tests_success = 0;

static void test() {
  QueueList queue = QueueList_New((void*)1);
  QueueList_Push(queue, (void*)2);
  QueueList_Push(queue, (void*)3);
  QueueList_Push(queue, (void*)4);
  ASSERT_INT_EQ(1, (int)QueueList_Pop(queue));
  QueueList_Push(queue, (void*)5);
  ASSERT_INT_EQ(2, (int)QueueList_Pop(queue));
  ASSERT_INT_EQ(3, (int)QueueList_Pop(queue));
  QueueList_Push(queue, (void*)6);
  ASSERT_INT_EQ(4, (int)QueueList_Pop(queue));
  ASSERT_INT_EQ(5, (int)QueueList_Pop(queue));
  ASSERT_INT_EQ(6, (int)QueueList_Pop(queue));
  QueueList_Delete(queue);
}

int main() {
  test();
  TEST_SUMMARY();
  return 0;
}