#ifndef __cplusplus

#define _GNU_SOURCE

#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "uthash.h"

struct ListNode
{
  int val;
  struct ListNode* next;
};

struct TreeNode
{
  int val;
  struct TreeNode* left;
  struct TreeNode* right;
};

#else

#include <bits/stdc++.h>

struct TreeNode
{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode()
    : val(0)
    , left(nullptr)
    , right(nullptr)
  {
  }
  TreeNode(int x)
    : val(x)
    , left(nullptr)
    , right(nullptr)
  {
  }
  TreeNode(int x, TreeNode* left, TreeNode* right)
    : val(x)
    , left(left)
    , right(right)
  {
  }
};

#endif