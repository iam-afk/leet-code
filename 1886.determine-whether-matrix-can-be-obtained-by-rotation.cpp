// @leet imports start
using namespace std;
// @leet imports end

// @leet start
class Solution
{
public:
  bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target)
  {
    int n = mat.size();

    auto rotate = [n](auto r) {
      return [r, n](int i, int j) -> pair<int, int> {
        auto [ri, rj] = r(i, j);
        return { rj, n - ri - 1 };
      };
    };

    auto r0 = [n](int i, int j) -> pair<int, int> { return { i, j }; };
    auto r90 = rotate(r0);
    auto r180 = rotate(r90);
    auto r270 = rotate(r180);

    return findRotation(mat, target, r0, r90, r180, r270);
  }

  template<typename... Rotations>
  bool findRotation(auto const& mat,
                    auto const& target,
                    Rotations&&... rotations)
  {
    return (isRotation(mat, target, std::forward<Rotations>(rotations)) ||
            ...);
  }

  bool isRotation(auto const& mat, auto const& target, auto rotation)
  {
    for (int i = 0; i < mat.size(); i++)
      for (int j = 0; j < mat[i].size(); j++) {
        auto [r, c] = rotation(i, j);
        if (mat[i][j] != target[r][c])
          return false;
      }
    return true;
  }
};
// @leet end