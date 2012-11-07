/*
 * binary_tree.h
 *
 *  Created on: 2012/11/08
 *      Author: tomofumi
 */

#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

typedef struct _TreeNode *TreeNode;

typedef struct _TreeNode {
  int value;
  TreeNode left_node;
  TreeNode right_node;
  void (*add)(TreeNode this, int value);
  TreeNode (*find)(TreeNode this, int value);
  TreeNode (*remove)(TreeNode this, int value);
  void (*show)(TreeNode this, int depth);
} _TreeNode;

TreeNode TreeNode_New(int value);
TreeNode TreeNode_Delete(TreeNode this);

#endif /* BINARY_TREE_H_ */
