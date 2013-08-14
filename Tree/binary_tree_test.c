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

// void TestBinaryTree() {
//   int i, action;
//   TreeNode tree_root = TreeNode_New(1);

//   for (i = 0; i < 10; i++) {
//     tree_root->add(tree_root, rand() % 99 + 1);
//   }
//   while (TRUE) {
//     tree_root->show(tree_root, 0);
//     printf("実行する操作のタイプを入力してください。\n 1 ：追加\t2 ：検索\t3 ：削除\t それ以外：終了>");
//     scanf("%d", &action);
//     switch (action) {
//     case 1:
//       printf("1 〜100の範囲で，追加する数字を入力してください:");
//       scanf("%d", &i);
//       if (i < 1 || i > 100) {
//         continue;
//       }
//       tree_root->add(tree_root, i);
//       break;
//     case 2:
//       printf("検索する数字を入力してください:");
//       scanf("%d", &i);
//       if (tree_root->find(tree_root, i) != NULL ) {
//         printf("%dを発見しました\n", i);
//       } else {
//         printf("%dは見つかりませんでした\n", i);
//       }
//       break;
//     case 3:
//       printf("削除する数字を入力してください:");
//       scanf("%d", &i);
//       if (tree_root->remove(tree_root, i) != NULL ) {
//         printf("%dを削除しました\n", i);
//       } else {
//         printf("%dは見つかりませんでした\n", i);
//       }
//       break;
//     default:
//       TreeNode_Delete(tree_root);
//       break;
//     }
//   }
// }
