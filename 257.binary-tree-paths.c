/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdio.h>
static void
dfs(struct TreeNode* node,
    int* path,
    int path_size,
    char** paths,
    int* paths_size)
{
  path[path_size++] = node->val;
  if (node->left == 0 && node->right == 0) {
    char *s = malloc(path_size * 4 + (path_size - 1) * 2 + 1), *t = s;
    t += sprintf(t, "%d", path[0]);
    for (int i = 1; i < path_size; ++i)
      t += sprintf(t, "->%d", path[i]);
    paths[(*paths_size)++] = s;
  }
  if (node->left != 0)
    dfs(node->left, path, path_size, paths, paths_size);
  if (node->right != 0)
    dfs(node->right, path, path_size, paths, paths_size);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char**
binaryTreePaths(struct TreeNode* root, int* return_size)
{
  char** paths = calloc(50, sizeof *paths);
  *return_size = 0;

  int path[100];

  dfs(root, path, 0, paths, return_size);

  return paths;
}