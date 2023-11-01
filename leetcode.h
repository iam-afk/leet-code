#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int
max(int a, int b)
{
  return a > b ? a : b;
}

struct TreeNode
{
  int val;
  struct TreeNode* left;
  struct TreeNode* right;
};
