// @leet start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void
dumpLeafs(struct TreeNode* node, int* leafs, int* leaf_size)
{
  if (node == 0)
    return;
  if (node->left == 0 && node->right == 0)
    leafs[(*leaf_size)++] = node->val;
  else {
    dumpLeafs(node->left, leafs, leaf_size);
    dumpLeafs(node->right, leafs, leaf_size);
  }
}

bool
checkLeafs(struct TreeNode* node, int* leafs, int leaf_size, int* leaf_index)
{
  if (node == 0)
    return true;
  if (node->left == 0 && node->right == 0)
    return *leaf_index < leaf_size && leafs[(*leaf_index)++] == node->val;
  return checkLeafs(node->left, leafs, leaf_size, leaf_index) &&
         checkLeafs(node->right, leafs, leaf_size, leaf_index);
}

bool
leafSimilar(struct TreeNode* root1, struct TreeNode* root2)
{
  int leafs[200], leaf_size = 0, leaf_index = 0;
  dumpLeafs(root1, leafs, &leaf_size);
  return checkLeafs(root2, leafs, leaf_size, &leaf_index) && leaf_index == leaf_size;
}
// @leet end