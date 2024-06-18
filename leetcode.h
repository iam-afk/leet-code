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
