// @leet imports start
using namespace std;
// @leet imports end

// @leet start
class Solution
{
public:
  int numSpecial(vector<vector<int>>& mat)
  {
    vector<int> r(mat.size()), c(mat.front().size());
    for (int i = 0; i < mat.size(); i++)
      for (int j = 0; j < mat[i].size(); j++)
        r[i] += mat[i][j], c[j] += mat[i][j];
    int ans = 0;
    for (int i = 0; i < mat.size(); i++)
      for (int j = 0; j < mat[i].size(); j++)
        ans += mat[i][j] == 1 && r[i] == 1 && c[j] == 1;
    return ans;
  }
};
// @leet end