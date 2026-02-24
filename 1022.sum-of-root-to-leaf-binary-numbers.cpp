// @leet imports start
using namespace std;
// @leet imports end

// @leet start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution
{
public:
  int sumRootToLeaf(TreeNode* root)
  {
    return [](this auto self, TreeNode* node, int n) {
      if (!node)
        return 0;
      n = 2 * n + node->val;
      if (!node->left && !node->right)
        return n;
      return self(node->left, n) + self(node->right, n);
    }(root, 0);
  }
};
// @leet end