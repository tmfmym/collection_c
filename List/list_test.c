#include "list.h"
#include "../minunit.h"

int mu_tests_run = 0;
int mu_tests_success = 0;

static void test() {
  List list = List_New();

  List_Add(list, (void*)2);
  ASSERT_INT_EQ(2, (int)List_Get(list, 0));
  List_Add(list, (void*)3);
  ASSERT_INT_EQ(2, (int)List_Get(list, 0));
  ASSERT_INT_EQ(3, (int)List_Get(list, 1));
  ASSERT_INT_EQ(2, list->size);

  ASSERT_INT_EQ(2, (int)List_GetFirst(list));
  ASSERT_INT_EQ(3, (int)List_GetLast(list));
  ASSERT_INT_EQ(3, (int)List_Remove(list, 1));
  ASSERT_INT_EQ(1, list->size);

  ASSERT_INT_EQ(2, (int)List_Remove(list, 0));
  ASSERT_INT_EQ(0, list->size);

  List_Add(list, (void*)4);
  ASSERT_INT_EQ(4, (int)List_GetFirst(list));
  ASSERT_INT_EQ(4, (int)List_GetLast(list));
  ASSERT_INT_EQ(1, list->size);

  List_Add(list, (void*)5);
  List_Add(list, (void*)6);
  ASSERT_INT_EQ(6, (int)List_Get(list, 2));
  ASSERT_INT_EQ(4, (int)List_Get(list, 0));

  /* index out bounds */
  // List_Get(list, 8);
  // List_Remove(list, 2);

  list = List_Delete(list);
}

int main() {
  test();
  TEST_SUMMARY();
  return 0;
}