#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "uthash.h"

struct TreeNode
{
  int val;
  struct TreeNode* left;
  struct TreeNode* right;
};
