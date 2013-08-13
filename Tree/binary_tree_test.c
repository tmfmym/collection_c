#include "binary_tree.h"
#include "../minunit.h"

int mu_tests_run = 0;
int mu_tests_success = 0;

static void test() {
  TreeNode tree_root = TreeNode_New(1);

  tree_root->add(tree_root, 11);
  tree_root->add(tree_root, 4);
  tree_root->add(tree_root, 7);
  tree_root->add(tree_root, 3);

  tree_root->show(tree_root, 0);

  tree_root->find(tree_root, 1);
  tree_root->remove(tree_root, 1);

  // ASSERT_INT_EQ(4, (int)List_Get(list, 0));

  TreeNode_Delete(tree_root);
}

int main() {
  test();
  TEST_SUMMARY();
  return 0;
}