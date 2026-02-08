using namespace std;

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
  bool isBalanced(TreeNode* root)
  {
    auto [ok, _] = depth(root);
    return ok;
  }

  pair<bool, int> depth(TreeNode* node)
  {
    if (node == nullptr)
      return { true, 0 };
    if (auto [ok, left] = depth(node->left); !ok)
      return { false, 0 };
    else if (auto [ok, right] = depth(node->right); !ok)
      return { false, 0 };
    else
      return { abs(left - right) <= 1, max(left, right) + 1 };
  }
};
// @leet end