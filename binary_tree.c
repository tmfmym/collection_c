/*
 * binary_tree.c
 *
 *  Created on: 2012/11/08
 *      Author: tomofumi
 */

#include <stdio.h>
#include <stdlib.h>
#include "configure.h"
#include "binary_tree.h"
#include "logger.h"

static TreeNode Initilaze(int value);
static void Add(TreeNode this, int value);
static TreeNode Find(TreeNode this, int value);
static TreeNode Remove(TreeNode this, int value);
static void Show(TreeNode this, int depth);

static void ChangeParentReferenceNode(TreeNode this, TreeNode parent_node,
    TreeNode child_node, int direction);

/*
 * TreeNodeを生成
 *
 * @param value
 * @return TreeNode
 */
TreeNode TreeNode_New(int value) {
  TreeNode instance = Initilaze(value);
  if (instance == NULL ) {
    return NULL ;
  }
  LOGGER_DEBUG("new %x\n", instance);
  return instance;
}

/*
 * TreeNodeを破棄
 *
 * @param 破棄するTreeNode
 * @return NULL
 */
TreeNode TreeNode_Delete(TreeNode this) {
  if (this != NULL ) {
    TreeNode_Delete(this->left_node);
    TreeNode_Delete(this->right_node);
    free(this);
  }
  return NULL ;
}

/*
 * TreeNodeを初期化
 *
 * @param value
 * @return TreeNode
 */
static TreeNode Initilaze(int value) {
  TreeNode instance;
  if (!(instance = (TreeNode)malloc(sizeof(_TreeNode)))) {
    LOGGER_ERROR("%s %s\n", CANNOTALLOCATEMEMORY, __func__);
    return NULL ;
  }
  instance->left_node = NULL;
  instance->right_node = NULL;
  instance->value = value;
  instance->add = Add;
  instance->find = Find;
  instance->remove = Remove;
  instance->show = Show;
  return instance;
}

/*
 * ノードを追加
 *
 * @param value 追加する値
 */
static void Add(TreeNode this, int value) {
  if (this == NULL ) {
    this = Initilaze(value);
    return;
  }

  if (this->value > value) {
    if (this->left_node != NULL ) {
      this->add(this->left_node, value);
    } else {
      this->left_node = Initilaze(value);
    }
  } else {
    if (this->right_node != NULL ) {
      this->add(this->right_node, value);
    } else {
      this->right_node = Initilaze(value);
    }
  }
}

/*
 * 指定した値のノードを取得
 *
 * @param value
 * @return 指定された値。ない場合はNULL
 */
static TreeNode Find(TreeNode this, int value) {
  if (this->value > value) {
    if (this->left_node == NULL ) {
      return NULL ;
    }
    return Find(this->left_node, value);
  } else if (this->value < value) {
    if (this->right_node == NULL ) {
      return NULL ;
    }
    return Find(this->right_node, value);
  }
  return this;
}

/*
 * 指定した値を削除
 *
 * @param value 削除する値
 * @return 指定された値の親ノード。ない場合はNULL
 */
static TreeNode Remove(TreeNode this, int value) {
  TreeNode left_biggest;
  TreeNode node = this;
  TreeNode parent_node = NULL;
  int direction = 0;

  /* 削除すべき対象を見つける */
  while (node != NULL && node->value != value) {
    if (node->value > value) {
      parent_node = node;
      node = node->left_node;
      direction = -1; /* 親の左側 */
    } else {
      parent_node = node;
      node = node->right_node;
      direction = 1; /* 親の右側 */
    }
  }
  if (node == NULL ) return NULL ;

  if (node->left_node == NULL || node->right_node == NULL ) {
    if (node->left_node == NULL ) {
      ChangeParentReferenceNode(this, parent_node, node->right_node, direction);
    } else {
      ChangeParentReferenceNode(this, parent_node, node->left_node, direction);
    }
    free(node);
  } else {
    /* nodeの左側の最も大きな値（最も右側の値）を取得する */
    left_biggest = node->left_node;
    parent_node = node;
    direction = -1;
    while (left_biggest->right_node != NULL ) {
      parent_node = left_biggest;
      left_biggest = left_biggest->right_node;
      direction = 1;
    }
    /* left_biggestの値をnodeに代入し，left_biggestは左側の枝を入れる */
    node->value = left_biggest->value;
    if (direction == -1) {
      parent_node->left_node = left_biggest->left_node;
    } else {
      parent_node->right_node = left_biggest->left_node;
    }
    free(left_biggest);
  }
  return parent_node;
}

/*
 * ツリーを表示
 *
 * @param depth 階層数(ルートは0)
 */
static void Show(TreeNode this, int depth) {
  if (this == NULL ) return;

  Show(this->left_node, depth + 1);
  for (int i = 0; i < depth; i++) {
    printf("  ");
  }
  printf("%d\n", this->value);
  Show(this->right_node, depth + 1);
}

/*
 * 親のポインタを変更する
 *
 * @param parent_node　親ノード
 * @param child_node  子ノード
 * @param direction 親から見た位置 -1:左 0:自分 1:右
 */
static void ChangeParentReferenceNode(TreeNode this, TreeNode parent_node,
    TreeNode child_node, int direction) {
  switch (direction) {
  case -1:
    parent_node->left_node = child_node;
    break;
  case 1:
    parent_node->right_node = child_node;
    break;
  default:
    this = child_node;
    break;
  }
}
